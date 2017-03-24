.name "erase_opcode10"
.comment "crush a sti by 33 -> wait the end of sti, then  bytes"

fork %20
ld %-1,r4
sti r1,%100,%10
zjmp %-14

ld %22528,r4
live %1
st r4,-23
lfork %30
