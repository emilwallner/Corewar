.name "erase_acb"
.comment "crush the acb but the num of arg's bytes stay the same -> "

fork %21
aff r1
lld %16,r3
st r3,50
zjmp %-14

ld %3489665027,r2
st r2,-21
lfork %30
