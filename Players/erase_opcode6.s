.name "erase_opcode6"
.comment "crush a sti by ffffffff -> wait the end of sti, then jump 8 bytes"

fork %20
ld %-1,r4
sti r1,%100,%10
zjmp %-14

ld %255,r4
live %1
st r4,-23
lfork %30
