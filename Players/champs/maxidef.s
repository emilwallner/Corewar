.name " maxidef "
.comment " module de defense"

loop:	live %0
	zjmp %8

gobepc:	st r1,6			# 03 70 01 00 06			5
	live %66		# 01 00 00 00 42			10
	ld -4,r1		# 02 d0 ff fc 01			5
	st r2,-14		# 03 70 02 ff f2			5
	
	ld %0,r5
	zjmp %:init

slide2:	zjmp %-492

slide1: live %1
	st r2,-385
	st r4,-386
defm:	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
	st r3,-510
deflv:	live %1
	zjmp %:defm


init:	ld %57672703,r3
	#ld %57672560,r3
	sti r1,%:loop,%1
	sti r1,%:source,%1
	sti r1,%:source,%9
	sti r1,%:arbre,%1
	sti r1,%:gen21,%1
	sti r1,%:gen22,%1
	sti r1,%:deflv,%1
	sti r1,%:slide1,%1
	ld :deflv,r2
	ldi %:deflv,%4,r4
	ld %0,r5

source:	live %1
	fork %-5
	live %1
	zjmp %:arbre

arbre:	live %1
	fork %:gen22	


gen21:	live %1		
	zjmp %:slide1
gen22:	live %1		
	zjmp %:slide2


