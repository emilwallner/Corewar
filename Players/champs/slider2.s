.name		"Sliders"
.comment	"And the winner is ..."

		sti     r1,%:leon_live,%1
		sti	r1,%:fork1,%1
		sti	r1,%:fork2,%1
		sti	r1,%:roger_live,%1
		sti	r1,%:torp,%1
		sti	r1,%:torp_,%1
		sti	r1,%:fork3,%1
		sti	r1,%:fork_live,%1
		sti	r1,%:live,%1
		sti	r1,%:live,%6
		sti	r1,%:live,%11
		sti	r1,%:live,%16
		sti	r1,%:live,%21
		sti	r1,%:live,%26
		sti	r1,%:live,%31
		sti	r1,%:live,%36
		sti	r1,%:live,%41
		sti	r1,%:live,%46
		sti	r1,%:live,%51
		sti	r1,%:live,%56
		sti	r1,%:live,%61
		sti	r1,%:live,%66
		sti	r1,%:live,%71
		sti	r1,%:live,%76
		sti	r1,%:live,%81
		sti	r1,%:live,%86
		sti	r1,%:live,%91
		sti	r1,%:live,%96
		sti	r1,%:live,%101	
		sti	r1,%:live,%106
		sti	r1,%:live,%111
		sti	r1,%:live,%116
		ld	%48,r14	
		ld      %4,r4
		ld      %48,r6
		ld	%48,r13
		ld	%:leon_ecrit,r8
		ld	%330,r9
		add	r8,r9,r8
		ld	%:roger,r12
		sub	r12,r8,r12
fork1:		live	%42
		fork	%:fork_live
fork2:		live	%42
		fork	%:leon
fork3:		live	%42
		fork	%:roger
		ld	%0,r15	
		zjmp	%:torp
leon:		ld      %0,r2
leon_live:	live    %42
		ldi     %:leon,r2,r3
		sti     r3,r8,r2
		add     r2,r4,r2
		xor     r13,r2,r7
		zjmp    %415
		ld      %0,r15
leon_ecrit:	zjmp    %:leon_live
roger:		ld	%0,r10
roger_live:	live	%42
		ldi	%:roger,r10,r11
		sti	r11,r12,r10
		add	r10,r4,r10
		xor	r6,r10,r7
		zjmp	%-361
		ld	%0,r15
roger_ecrit:	zjmp	%:roger_live
torp:		live	%42	
		fork	%:leon
torp_:		live	%42
		fork	%:roger
		ld	%0,r15
		zjmp	%:torp
live:		live	%42
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
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42	
		zjmp	%:live
fork_live:	live	%42
		fork	%:live
		ld	%0,r15
		zjmp	%:fork_live
	










