.name "erase_acb2"
.comment "crush the acb and the num of arg's bytes decrease by one -> "

fork %26
aff r1
ld %16,r3
st r3,20
st r1,20
zjmp %-14

ld %1342374161,r2
st r2,-19
lfork %30
