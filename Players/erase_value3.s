.name "erase_value3"
.comment "crush the value pointed by an indirect during a loading -> instruction executed with the new value"

fork %26
aff r1
ld %0,r8
ld -6,r4
st r4,50
zjmp %-14

ld %286331153,r2
st r2,-24
lfork %30
