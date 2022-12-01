import gdb

# Implement one or more methods of this pretty printer to change how the MyData
# class from print_this.cpp is displayed.
#
# Use GDB's "source" command to load this into your debug session. As you
# develop the code, you can reload by sourcing again.

class MyDataPrinter:
    def __init__(self, val):
        self.val = val

    def children(self):
        return []

    def display_hint(self):
        pass

    def to_string(self):
        pass


### You should not need to change the code below this point.

# Ensure our printing code is called on the MyData type.
pp = gdb.printing.RegexpCollectionPrettyPrinter("my_printer")
pp.add_printer("MyData", "^MyData$", MyDataPrinter)

# Registering a pretty-printer this way, with replace=True, makes it easy to
# edit the file and then source it again to try out a new implementation.
gdb.printing.register_pretty_printer(None, pp, replace=True)
