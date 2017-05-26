.name "Candy"
.comment ""

	st		r1, r12
	ld      %0 , r14
	zjmp    %:base

def:
	st		r9, -256
	st		r10, -256
	st		r14, -9
	st      r4, -21
	st      r14, -30
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st		r9, -256
	st		r10, -256
	st		r14, -9
	st      r4, -21
	st      r14, -30
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st		r10, -256
	st		r14, -9
	st      r4, -21
	st      r14, -30
	ld      %0 , r15
	zjmp %:def

liv:
	live    %42
	fork    %:live3
	ld      %0 , r16
	zjmp    %:base

base:
	live 	%42
	ld		%57672449, r3
	ld		%57672959, r4
	ld		%42991616, r9
	ld		%235536380, r10
	ld		%16777216 ,r11
	xor		r12, r14, r15
	sti		r15, %:live1, %1
	sti		r15, %:liv, %1
	sti		r15, %:live2, %1
	zjmp    %:live1

live1:
	live	%42
	fork	%:def
	fork	%:save
	ld		%0 , r15
	zjmp	%:liv

live3:
	st      r3, 256
	st      r3, 256
	st      r3, 256
	live %1
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
	live %1
	st      r3, 256
zjmp %:live3

attak:
	live 	%42
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
	st      r9, 256
zjmp %:attak

live2:
		live    %1
save:
		live %1
		fork	%:attak
		st      r4, 254
		zjmp %:save
