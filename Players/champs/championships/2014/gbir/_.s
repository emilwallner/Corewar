.name "Underscore"
.comment "__UNDERSCORE_S__"

first:
	ld		%0, r2
	zjmp	%:begin
	zjmp	%-511
defdessus:
	live	%-42
	sti		r10, r11, r13
	add		r12, r13, r13
	xor		r13, %-255, r14
	zjmp	%:zero
	ld		%0, r14
	zjmp	%:defdessus
zero:
	ld		%0, r13
	zjmp	%:defdessus
#plein de truck pour remplir
lasertop:
	live	%-42
	ld		%-128, r6
	fork	%:lasera
	ld		%190056198, r7
	ld		%0, r5
	ld		%0, r16
	zjmp	%:laser
lasera:
	ld      %84541307, r7
	ld      %4, r5
	ld		%190056198, r16
dec1:
	st      r16, -490
dec2:
	st      r7, -491
laser:
	ld		%0, r2
	zjmp	%-511
empty:
	lldi    %42, %42, r16
#def du dessus
atj1:
	live	%-42
	sti		r1, %:defdessus, %1
	ld		%57672959, r10
	ld		%-30, r11
	ld		%-5, r12
	st		r1, 6
defplus:
	live	%-42
	fork	%:defdessus
	ld		%-165, r13
	ld		%0, r2
	zjmp	%:defplus
at2:
	sti		r1, %:li1, %1
	sti     r1, %:proc1, %1
	fork    %:atj1
	st      r1, 6
	live    %-42
	or		r1, r1, r7
	ld		%1880161814, r9
	ld      %1879571989, r10
	ld      %34209281, r11
#live + def dessous + attack
atf:
	fork	%:proc1
li1:
	live	%-42
	fork	%:head
	ld		%0, r2
	zjmp	%:brain
head:
	ld		%191104768, r7
	ld		%5, r6
	ld		%0, r2
	zjmp	%:forklive
proc1:
	live	%-42
	fork    %:tail
corps:
	ld      %101056768, r7
	ld      %9, r6
	ld      %0, r2
	zjmp    %:forklive
tail:
	ld      %0, r2
	ld      %12, r6
	ld      %0, r2
	zjmp    %:forklive
forklive:
	st		r1, 6
	live    %-42
	sti		r7, r6, %317
	ld		%0, r2
	zjmp	%309
beginnewattack:
	sti     r16, %:modme, %1
	fork	%:def_at
	ld      %24, r16
	sti     r16, %:modme, %1
	st      r1, 6
	live    %-42
golive:
	ld      %0, r2
	zjmp    %511
brain:
	ld		%16, r12
	add		r12, r9, r9
	add		r12, r10, r10
	add		r12, r11, r11
	st		r1, 6
	live	%-42
	ld		%0, r2
	sti		r1, %:lasertop, %1
	sti     r9, %:dec1, %1
	sti     r10, %:dec2, %1
	sti     r11, %:laser, %6
	fork	%:lasertop
	zjmp	%:atf
begin:
	ld		%16777216, r16
	sti		r16 ,%:first, %6
	st		r1, 117
	sti		r1, %:sst, %1
	ld		%507, r4
	ld		%507, r6
	st		r1, 6
	live	%-42
def_at:
	ld		%190055170, r8
	ld		%67699190, r9
	st		r8, 511
	st		r9, 510
modme:
	ld		%24, r8
	fork	%:at2
at1:
	fork	%:sjmp
sst:
	live	%-1
	ld		%0, r2
	ld		%190055682, r3
	ld		%190056194, r5
	ld		%190056194, r7
	ld		%0, r16
	zjmp	%448
sjmp:
	live	%0
	ld		%4, r2
	ld		%101253622, r3
	ld		%134807571, r5
	ld		%134807571, r7
	ld		%0, r16
	zjmp	%405
