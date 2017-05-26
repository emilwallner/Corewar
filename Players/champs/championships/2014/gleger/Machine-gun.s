.name "Machine-gun"
.comment "yipikai mother fucker"

entry:	sti r1, %:live, %1
		
		ld	%0, r2
		live %10
		ld	%47, r3
		zjmp %:def

wall:	ld %70, r3
		zjmp %:wall2
		ld %15, r3
		ld	10, r4
		sub r3, r4, r3
		st r3, -162
		st r3, -173
		st r3, -184
		st r3, -195
		st r3, -206


live:	live %15
		zjmp %3

def:	st r2, -270
		zjmp %:wall
		st r2, -261
		st r2, -252
		st r2, -243
		st r2, -254
		st r2, -265
		st r2, -276
		st r2, -287
		st r2, -298
		st r2, -309
		st r2, -318
		st r2, -327
		st r2, -336
		st r2, -345
		st r2, -354
		st r2, -363
		st r2, -372
		st r2, -381
		st r2, -390
		zjmp %:def
		zjmp %:live

wall2:	live %130000
		st r5, 66
		st r5, 75
		st r5, 84
		st r5, 93
		st r5, 102
		st r5, 111
		st r5, 120
		st r5, 129
		st r5, 138
		st r5, 147
		st r5, 156
		st r5, 165
		st r5, 174
		st r5, 183
		st r5, 192
		st r5, 201
		st r5, 210
		st r5, 219
		st r5, 228
		live %131
		zjmp %:entry
