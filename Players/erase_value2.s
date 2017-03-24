.name "erase_value2"
.comment "crush num of register while it is being loaded -> instruction executed with the new register"

fork %33
aff r1
ld %0,r8
ld %10,r4
st r4,50
st r3,50
zjmp %-14

ld %2563,r2
st r2,-24
lfork %30
