	.name "Wall"
	.comment "Werror(you) Wextra(me)"

start:
	ld		%1, r14
	zjmp	%:wallstart
	st		r15, -8				#	15
	
stlive:
	sti	    r1,	%:wall,	%1		#	7
	sti		r1, %:alive, %1
	sti		r1, %:forklive, %1
	sti		r1, %:wallstart, %1
	sti		r1, %:fork, %1
	sti     r1, %:fork, %9
	sti     r1, %:kta, %1
	sti     r1, %:kta, %9
	sti     r1, %:kta, %17		#	63
								#	78
fork:
	live	%66
	fork	%:wallstart
	live	%66
	fork	%:fork				#	16
								#	94
kta:
	live	%2576980377			#	99
	lfork	%925
	live    %66					#	107
	lfork   %1941
	live    %66					#	115
	lfork   %2957
	
forklive:	
	live	%66
	fork	%:forklive
	aff		r1

alive:
	live	%66
	ld		%0, r16
	zjmp	%:alive

wallstart:
	live	%66
    ld      %42991616, r2
	ld      %265, r3
	ld      %4294508544, r4
	fork	%:wallstart

wall:
	live    %66
	st      r2, -300
	st      r3, -301
	st      r4, -302
	st      r2, -303
	st      r3, -304
	st      r4, -305
	st      r2, -306
	st      r3, -307
	st      r4, -308
	st      r2, -309
	st      r3, -310
	st      r4, -311
	st      r2, -312
	st      r3, -313
	st      r4, -314
    st      r2, -315
	st      r3, -316
	st      r4, -317
	st      r2, -318
	st      r3, -319
	st      r4, -320
	st      r2, -321
	st      r3, -322
	st      r4, -323
	st      r2, -324
	st      r3, -325
	st      r4, -326
	st      r2, -327
	st      r3, -328
	st      r4, -329
	ld		%0, r16
	zjmp	%:wall
