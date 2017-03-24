.name "erase_opcode5"
.comment "crush a sti by 0000 -> wait the end of sti, then jump 2 bytes"

fork %18
st r1,23
sti r1,%100,%10
zjmp %-14

ld %1074177,r3
live %1
st r4,-23
lfork %30
