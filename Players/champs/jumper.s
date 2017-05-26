#debut du mega truc qu'il est trop dur a faire

.name "Jumper !"
.comment "en fait C forker !"

gobepc:	st r1,:buff
	st r6,-4
	ld :buff,r1
debut:	ld %0,r7
	zjmp %:suite

goboucle0:	live %66
		ldi %-5,r3,r1
		sti r1,%-173,r3
		add r3,r4,r3
		xor r5,r3,r6
		zjmp %:finboucle0
		ld %0,r7
		zjmp %:goboucle0
finboucle0:	xor r3,r3,r3
		zjmp %-207

buff:	st r1,r1	
		
suite:	sti r1,%:livel,%1
livel:	live %66
	sti r2,%:debut,%-60
	ld %4,r4
	st r2,512
go:	ld %48,r5
	sti r1,%:goboucle0,%1
	sti r1,%:goboucle1,%1
	sti r1,%:live0,%1
	sti r1,%:live1,%1
	sti r1,%:live2,%1
	sti r1,%:live3,%1
	sti r1,%:live4,%1
live0:	live %66
live1:	live %66
live2:	live %66
live3:	live %66
live4:	live %66
	zjmp %:live0
	xor r3,r3,r3
	sti r1,%:livex,%1
livex:	live %66
	fork %:live0
	sti r1,%:boucle,%1
	sti r1,%:boucle,%9
	sti r1,%:boucle,%17
	sti r1,%:boucle,%25
	
boucle:	live %66
	fork %:goboucle0
	live %66
	fork %:boucle
	live %66
	fork %:goboucle1
	live %66
	zjmp %:goboucle0
goboucle1:	live %66
		ldi %-5,r3,r1
		sti r1,%17,r3
		add r3,r4,r3
		xor r5,r3,r6
		zjmp %:finboucle1
		ld %0,r7
		zjmp %:goboucle1
finboucle1:	xor r3,r3,r3
		zjmp %1
