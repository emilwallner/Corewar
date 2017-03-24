.name "erase_opcode"
.comment "crush a ld by a fork -> 0f0001 => wait end of ld, jump to 01 - >execute live, 10 cycle..."

fork %20
ld %1,r2
ld %0,r2
zjmp %-14

ld %983041,r3
ldi %10,%10,r4
aff r3
st r3,-28
lfork %30
