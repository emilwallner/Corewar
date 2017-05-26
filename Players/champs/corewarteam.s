.name "corewarteam"
.comment "tht"

l2:		sti r1,%:live,%1
		and r1,%0,r1
fork %8
live:	live %1
		zjmp %:live
