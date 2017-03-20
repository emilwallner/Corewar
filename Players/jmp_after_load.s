.name "zork"
.comment "just_a_basic_living_prog"

l2: ld %0,r2

live:	live	%2
	zjmp	%:live
