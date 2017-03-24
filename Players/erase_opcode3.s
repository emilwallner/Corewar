.name "erase_opcode3"
.comment "crush a ld by a aff -> don't know if it is exec or wait end of ld, then jump 5 bytes"

fork %20
ld %1,r2
ld %0,r2
zjmp %-14

ld %1074177,r3
ldi %10,%10,r4
aff r3
st r3,-28
lfork %30
