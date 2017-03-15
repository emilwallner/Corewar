.name "bigzork"
.comment "I know i cant win"

ld %1, r1

loop:
add r1, r1, r1
ld %0, r2
zjmp %:r1
live %1
ld %0, r2
zjmp %:loop
