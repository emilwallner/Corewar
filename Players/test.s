.name "11"
.comment "1"

ld %1,r2
hvds: ld %:gre,r3
ld %0,r15
zjmp %-10
live %-1
hvds: ld %1,r4
