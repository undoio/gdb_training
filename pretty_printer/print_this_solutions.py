import gdb


class MyDataPrinter:
    def __init__(self, val):
        self.val = val

    def children(self):
        # Iterate through the fields we'd like to display.
        for i in ["index", "output", "extra"]:
            yield i, self.val[i]

        # We could have used the to_string() method to just print the output we
        # wanted - that would be fine, just less convenient.


# Ensure our printing code is called on the MyData type.
pp = gdb.printing.RegexpCollectionPrettyPrinter("my_printer")
pp.add_printer("MyData", "^MyData$", MyDataPrinter)


# Registering a pretty-printer this way, with replace=True, makes it easy to
# edit the file and then source it again to try out a new implementation.
gdb.printing.register_pretty_printer(None, pp, replace=True)
