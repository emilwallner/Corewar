.name	"LDE LDE LDE"
	ld %0,r6
	sti r1,%:suitb,%1
	sti r1,%:suitb,%6
	sti r1,%:suitb,%11
	sti r1,%:suitb,%16
	sti r1,%:suitb,%21
	sti r1,%:suitb,%26
	sti r1,%:suitb,%31
	sti r1,%:suitb,%36
	sti r1,%:suitb,%41
	sti r1,%:suitb,%46
	sti r1,%:suitb,%51
	sti r1,%:suitb,%63
hop:	live %1

	fork %:decal2
	live %1
	ld %0,r2
	zjmp %:decal
toto:	st r15,-480
	st r4,-481
	st r7,-482
	st r8,-483
	st r13,-484
	st r14,-485
	zjmp %-510
	
	
decal2: live %1
	fork %:suite
	live %1
	ld %57672448,r5
	ld %67334147,r6

	ld %57673214,r9
	ld %201551878,r10
	ld %4262136318,r11
	ld %33554432,r12

	ld %57674238,r15
	ld %369324042,r4
	ld %4262790000,r7
	ld %201200643,r8
	ld %1879899667,r13
	ld %167641600,r14
	
	fork %:separ2
	live %4
	ld %134443011,r3
	sti r1,%:middle,%1
	sti r1,%:middle,%6
	sti r1,%:middle,%11
	sti r1,%:middle,%16
	sti r1,%:middle,%21

	ld %0,r2
	zjmp %:toto
separ2:	live %3
	ld %263024,r3
	sti r1,%:middle,%26
	sti r1,%:middle,%31
	sti r1,%:middle,%36
	sti r1,%:middle,%41
	sti r1,%:middle,%53

	xor r2,r2,r2
	zjmp %:toto
	
padec2:	live %1
	fork %:suite
	live %1
	ld %0,r2
	zjmp %:decal

	
suite:	live %1
	fork %:hop
	live %1
	fork %:middle
suitb:	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	ld %0,r6
	live %1
	zjmp %:suitb
middle:	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	ld %0,r6
	live %1
	zjmp %:middle

	
decal:	live %1
	fork %:fuite
	live %1
	ld %57672448,r5
	ld %67334147,r6

	ld %57672961,r9
	ld %4228083718,r10
	ld %33229057,r11
	ld %4060086272,r12

	ld %57673985,r15
	ld %4228083722,r4
	ld %33227632,r7
	ld %184678915,r8
	ld %1879835129,r13
	ld %151119872,r14
	
	fork %:sepa
	live %4
	ld %134443011,r3
	ld %0,r2
	zjmp %:tot
sepa:	live %3
	ld %263024,r3
	xor r2,r2,r2
	zjmp %:tot

	live %4
	live %4
	live %4
	live %4
	live %4
	live %4
	live %4
	live %4
	live %4
	live %4
	live %4
	live %4
	live %4
	live %4
	live %4
	
tot:	st r15,488
	st r4,487
	st r7,486
	st r8,485
	st r13,484
	st r14,483
	zjmp %458
	
	
fuite:	live %1
	fork %:separe
	live %4
	ld %134443011,r3
	ld %0,r2
	zjmp %:debut
separe:	live %3
	ld %263024,r3
	xor r2,r2,r2
	zjmp %:debut
debut:	st r3,4
