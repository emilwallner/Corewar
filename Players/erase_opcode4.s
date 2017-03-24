.name "erase_opcode4"
.comment "crush a sti by a aff -> wait the end of sti, then jump 6 bytes"

fork %18
st r1,23
sti r1,%100,%10
zjmp %-14

ld %1074177,r3
live %1
st r3,-23
lfork %30
