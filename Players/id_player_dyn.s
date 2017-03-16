.name "zork"
.comment "just a basic living prog"

st r1,11
l2:	add r2,r3,r4

live:	live	%10
	zjmp %:live
