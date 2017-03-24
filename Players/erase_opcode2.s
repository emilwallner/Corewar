.name "erase_opcode2"
.comment "crush a ld by a fork -> 0f001e => wait end of ld, jump to 1e, 1 cycle, jump to the next..."

fork %20
ld %1,r2
ld %0,r2
zjmp %-14

ld %983070,r3
ldi %10,%10,r4
aff r3
st r3,-28
lfork %30
