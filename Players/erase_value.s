.name "erase_value"
.comment "crush the value to ld in a register -> instruction executed with the new value"

fork %28
aff r1
ld %0,r8
ld %0,r4
st r4,50
zjmp %-14

ld %25600,r2
st r2,-20
lfork %30
