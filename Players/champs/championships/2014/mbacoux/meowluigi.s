.name "Meow Luigi"
.comment "Here we meoooooow !"

shield2:
	zjmp	%:shield2

start:
	ld		%0, r16
	sti		r1, %:mloop, %1
	fork	%:protect

mloop:
	live	%0
	fork	%:main
	zjmp	%:mloop

proloop:
	live	%0
	st		r15, -200
	st		r15, -201
	st		r15, -202
	st		r15, -203
	st		r15, -204
	st		r15, -205
	st		r15, -206
	st		r15, -207

proloop_2:
	live	%0
	st		r15, -213
	st		r15, -214
	st		r15, -215
	st		r15, -216
	st		r15, -217
	zjmp	%:proloop

protect2:
	live	%0
	fork	%:proloop
	zjmp	%:protect2

protect:
	live	%0
	fork	%:protect2
	zjmp	%:protect

main:
	sti		r1, %:replicate, %1
	sti		r1, %:mloop, %1
	sti		r1, %:main2, %1
	sti		r1, %:main3, %1
	sti		r1, %:main4, %1
	sti		r1, %:replicate_loop, %1
	sti		r1, %:protect, %1
	sti		r1, %:protect2, %1
	sti		r1, %:proloop, %1
	sti		r1, %:proloop_2, %1
	sti		r1, %:loop, %1
	sti		r1, %:loop, %6
	sti		r1, %:loop, %11
	sti		r1, %:loop, %16
	sti		r1, %:loop, %21
	sti		r1, %:loop, %26
	sti		r1, %:loop, %31
	sti		r1, %:loop, %36
	sti		r1, %:loop, %41
	sti		r1, %:loop, %46
	sti		r1, %:loop, %51
	sti		r1, %:loop, %56
	sti		r1, %:loop, %61
	sti		r1, %:loop, %66
	sti		r1, %:loop, %71
	sti		r1, %:loop, %76
	fork	%:protect

main2:
	live	%0
	fork	%:replicate

main3:
	live	%0
	fork	%:main4
	zjmp	%:main3

main4:
	live	%0
	fork	%:loop
	zjmp	%:main4

loop:
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	live	%42
	zjmp	%:loop

replicate:
	live	%0
	ld		%0, r4
	ld		%8, r5
	ld		%4, r6
	ld		%220, r8
	fork	%:replicate_loop
	ld		%4, r4

replicate_loop:
	live	%0
	ldi		%:main2, r4, r2
	sti		r2, %:replicated, r4
	add		r4, r5, r4
	sub		r4, r8, r16
	zjmp	%:replicated
	sub		r16, r6, r16
	zjmp	%:replicated
	ld		%0, r16
	zjmp	%:replicate_loop

replicated:
	live	%0

