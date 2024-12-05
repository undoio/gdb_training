# This is free and unencumbered software released into the public domain.
import gdb

class NodePrinter:
    def __init__(self, val):
        self.val = val

    def children(self):
        # Iterate through the fields we'd like to display.
        #
        # Walk the linked list, yielding the node data to the rest of the
        # printing machinery.
        head = self.val.address
        while head:
            node = head.dereference()
            # We're formatting a string to describe the list node (which might
            # not show, depending on the display_hint value we've chosen).
            #
            # We're *not* formatting a string for the "i" value - GDB already
            # knows how to format ints. If the value was more complex, GDB
            # might recurse into another pretty printer to display it
            # correctly.
            yield f"Node @ {node.address}", node['i']
            head = node["next"]

    def display_hint(self):
        # Display this like an "array" so that it looks like a sequence of
        # values. You could also try "map" or removing this method to see the
        # default behaviour.
        return 'array'

    def to_string(self):
        # Print a header for the root of our data structure.
        return f'<Node list @ {self.val.address}>'


# Ensure our printing code is called on the Node type.
pp = gdb.printing.RegexpCollectionPrettyPrinter("Node")
pp.add_printer("Node", "^Node$", NodePrinter)


# Registering a pretty-printer this way, with replace=True, makes it easy to
# edit the file and then source it again to try out a new implementation.
gdb.printing.register_pretty_printer(None, pp, replace=True)
