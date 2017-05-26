.name "Jinx"
.comment "Stay still, I'm trying to shoot you..!"

init:
	st		r1, :replic1
	st		r6, -4
	ld		:replic1, r1

start1:
	ld		%0, r7
	zjmp	%:start2

stuff1:
	live	%66
	ldi		%-5, r3, r1
	sti		r1, %-173, r3
	add		r3, r4, r3
	xor		r5, r3, r6
	zjmp	%:stuff2

stuff2:
	xor		r3, r3, r3
	zjmp	%-207

replic1:
	st		r1, r1

start2:
	sti		r1, %:live0, %1

live0:
	live	%66
	sti		r2, %:start1, %-60
	ld		%4, r4
	st		r2, 512

replic2:
	ld		%48, r5
	sti		r1, %:stuff1, %1
	sti		r1, %:stuff3, %1
	sti		r1, %:live1, %1
	sti		r1, %:live2, %1
	sti		r1, %:live3, %1
	sti		r1, %:live4, %1
	sti		r1, %:live5, %1

live1:
	live	%66

live2:
	live	%66

live3:
	live	%66

live4:
	live	%66

live5:
	live	%66
	zjmp	%:live1
	xor		r3, r3, r3
	sti		r1, %:live6, %1

live6:
	live	%66
	fork	%:live1
	sti		r1, %:loop, %1
	sti		r1, %:loop, %9
	sti		r1, %:loop, %17
	sti		r1, %:loop, %25

loop:
	live	%66
	fork	%:stuff1
	live	%66
	fork	%:loop
	live	%66
	fork	%:stuff3
	live	%66
	zjmp	%:stuff1

stuff3:
	live	%66
	ldi		%-5, r3, r1
	sti		r1, %147, r3
	add		r3, r4, r3
	xor		r5, r3, r3
	zjmp	%:stuff4
	ld		%0, r7
	zjmp	%:stuff4
	ld		%0, r7
	zjmp	%:stuff3

stuff4:
	xor		r3, r3, r3
	zjmp	%113
