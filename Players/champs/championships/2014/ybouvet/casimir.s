.name "CASIMIR"
.comment "GLOUBIBOULGA"

	ld %880, r2
	ld %16778753, r3
	ld %4, r4
	ld %72618000, r5
	ld %269090801, r6
	st r1, 6
	live %456
	fork %:live
	add r16, r16, r16
	zjmp %:forknikator
live:
	st r1, 6
	live %546
	st r2, 1023
	st r3, 1022
	st r4, 1021
	st r5, 1020
	st r6, 1019
	fork %993
	sti r1, %:live2, %1
	fork %:live2
	add r16, r16, r16
	zjmp %:live
live2:
	live %4
	add r16, r16, r16
	zjmp %:live2
forknikator:
	st r1, 6
	live %37
	fork %:protect1
	fork %:protect2
	add r16, r16, r16
	zjmp %:forknikator
protect1:
	st r1, 6
	live %789
	st r2, -129
	st r3, -130
	st r4, -131
	st r5, -132
	st r6, -133
	st r16, -134
	st r16, -135
	st r16, -136
	add r16, r16, r16
	zjmp %:protect1
protect2:
	st r1, 6
	live %212
	st r2, -219
	st r3, -220
	st r4, -221
	st r5, -222
	st r6, -223
	st r16, -224
	st r16, -225
	st r16, -226
	add r16, r16, r16
	zjmp %:protect2
