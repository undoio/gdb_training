# This is free and unencumbered software released into the public domain.
import gdb


class WalkNodes(gdb.Command):
    """
    Walk a list of Node structures and print them out.
    """
    def __init__(self):
        super().__init__('walk-nodes', gdb.COMMAND_NONE)

    def invoke(self, args, from_tty):
        # Parse whatever we're passed as a starting pointer for the data
        # structure.
        head = gdb.parse_and_eval(args)

        # Check that the user passed a sensibly-typed argument - inform them if
        # not.
        if head.type != gdb.lookup_type("Node").pointer():
            raise gdb.GdbError("Argument must be of type Node *")

        # Walk the linked list, printing out the node data.
        while head:
            node = head.dereference()
            print(f"Node @ {node.address}: i = {node['i']}")
            head = node["next"]


WalkNodes()
