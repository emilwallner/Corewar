.name "erase_opcode12"
.comment "crush a sti by BB -> wait the end of sti, then  bytes"

fork %20
ld %-1,r4
sti r1,%100,%10
zjmp %-14

ld %25600,r4
live %1
st r4,-23
lfork %30
