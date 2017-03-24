.name "erase_opcode8"
.comment "crush a sti by 22222222 // 00220000 -> wait the end of sti, then jump 4 // 2 bytes"

fork %20
ld %-1,r4
sti r1,%100,%10
zjmp %-14

ld %34,r4
live %1
st r4,-23
lfork %30
