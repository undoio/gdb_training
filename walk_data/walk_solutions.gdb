# This a GDB script
# It can be loaded into GDB by issuing a source command:
#    (gdb) source ./walk.gdb

define print-list
  set $node = $arg0
  while $node
    print $node->i
    set $node = $node->next
  end
end

define sum-list
  set $node = $arg0
  set $total = 0
  while $node
    set $total += $node->i
    set $node = $node->next
  end
  print $total
end
