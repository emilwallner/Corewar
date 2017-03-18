.name "tim"
.comment "just a basic living prog"

l2:	add r2,r3,r4
	ld 0,r3
	fork %10

live:	live	%3
	zjmp %:live

live2: live %3
	zjmp %:live2
