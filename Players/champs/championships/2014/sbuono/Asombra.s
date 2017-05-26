.name "King Sombra"
.comment "Crystal empire is mine!"

init:
rest:
fork %:go
live %0
fork %:go2
prelive:
ld %251658255, r2
ld %1, r12
ld %40, r11
st r1, 11
st r16, -4
shield:
live %0
st r16, -300
st r2, -301
st r2, -302
sub r11, r12, r11
zjmp %:fork
ld %0, r16
zjmp %:shield

go:
ld %0, r16
zjmp %:assaut1

go2:
ld %0, r16
zjmp %:assaut2

fork:
ldi %:shield, %1, r13
ld %0, r16
st r13, 6
forkcycle:
live %0
fork %:forkcycle

eraser:
st r13, 6
live %0
fork %:part2

part1:
ld %190056971, r10 # sti r10,r11
ld %135004416, r7 # r8,r12 live
ld %273, r8
ld %270, r11
ld %0, r12
fork %:start1
zjmp %:start2

part2:
ld %202068999, r10 # r12 sti r7
st r13, r7
ld %276, r8
ld %274, r11
ld %0, r12
fork %:start1
zjmp %:start2

start1:
zjmp %3
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
sti r10, r11, r12
sti r7, r8, r12
live %0
start2:
sti r10, r11, r12
sti r7, r8, r12
live %0

assaut2:
live %0
ld %190055943, r10 # sti r6, r7
ld %84476405, r11 # r5 jump 01F5 (501)
ld %150994956, r3 #0x0900000c
ld %150994956, r6 #0x0900000c
ld %26, r7
ld %495, r4
ld %0, r5
zjmp %:jump

assaut1:
live %0
ld %190055943, r10 # sti r6, r7
ld %84476405, r11 # r5 jump 01F5 (501)
fork %:second
ld %190055172, r3 #0x0B540304
ld %190055172, r6 #0x0B540304
ld %507, r7
ld %24, r4
ld %0, r5
zjmp %:jump

second:
live %0
ld %84475923, r3 #0x0509001b
ld %84475923, r6
ld %511, r7
ld %28, r4
ld %0, r5
zjmp %:jump

jump:
live %0
st r10, 511
st r11, 510
zjmp %501
