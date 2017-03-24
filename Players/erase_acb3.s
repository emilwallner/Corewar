.name "erase_acb3"
.comment "crush the acb and the num of arg's bytes increase by one -> "

fork %25
aff r1
ld %16,r3
st r3,r1
st r1,20
zjmp %-14

ld %1879244816,r2
st r2,-18
lfork %30
