.name "erase_opcode7"
.comment "crush a sti by 77777777 // 00770000 -> wait the end of sti, then jump 6 // 2 bytes"

fork %20
ld %-1,r4
sti r1,%100,%10
zjmp %-14

ld %119,r4
live %1
st r4,-23
lfork %30
