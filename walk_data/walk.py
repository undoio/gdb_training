# This is free and unencumbered software released into the public domain.
import gdb


class WalkNodes(gdb.Command):
    """
    Walk a list of Node structures and print them out.
    """
    def __init__(self):
        super().__init__('walk-nodes', gdb.COMMAND_NONE)

    def invoke(self, args, from_tty):
        # Your code here!


WalkNodes()
