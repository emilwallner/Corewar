.name		"Varimathras"
.comment	"If I have wings, why am I always walking?"

piege:
	st		r1, r9 #/ ld nous, r9
	live	%0
	ld		%656, r1
	ld		%151162880, r2
	sti		r1, %:piege, %0
	sti		r9, %:piege, %4
	sti		r2, %:piege, %8

init_buldog:
	ld		%0, r1
	ld		%4, r3
	ld		%88, r4
	sti		r9, %:buldog, %1
	sti		r9, %:live1, %1
	sti		r9, %:live2, %1
	sti		r9, %:live3, %1

buldog:
	live	%0
	ldi		%:buldog, r1, r2
live1:
	live	%0
	sti		r2, %:fin, r1
live2:
	live	%0
	add		r1, r3, r1
	xor		r1, r4, r16
	zjmp	%:suite
live3:
	live	%0
	and		%0, %0, r16
	zjmp	%:buldog
suite:
	ld		%0, r1
	and		%0, %0, r16
	zjmp	%:fin

complicate:
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
	live	%0
fin:
