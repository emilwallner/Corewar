.name "zork"
.comment "just a basic living prog"

l2: ld %0,r2

live:	live	%-2
	zjmp	%:live
