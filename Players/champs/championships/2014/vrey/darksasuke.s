.name "Xx_DaRk_SaSuKe_93_xX"
.comment "The Dirty Hamster"

	st		r1, 235
	st		r1, 205
	ld		%8, r15
	ld		%1, r16
	ld		%-400, r13
	ld		%0, r11
	ld		%0, r16
	zjmp	%:start

lf:
	live	%9999999
	lfork	%:lf

start:
	ld		-3, r9
	ld		-13, r7
	ld		-17, r8
	ld		%300, r10
	fork	%:forward
	live	%999999
	fork	%:backward
	ld		%0, r16
	zjmp	%:initlive

initlive:
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	ld		%0, r16

live:
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	zjmp	%:live

backward:
	live	%9999999
	sub		r13, r15, r13
	sti		r9, r10, r13
	ld		%0, r16
	zjmp	%:backward

forward:
	live	%9999999
	add		r11, r15, r11
	sti		r7, r10, r11
	sti		r8, r10, r11
	ld		%0, r16
	zjmp	%:forward

