.name "erase_value4"
.comment "crush the value of the fork's direct arg -> instruction executed with the new value"

fork %11
live %-4
fork %5

ld %268435456,r2
st r2,-8
lfork %30
