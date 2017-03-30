.name   "play"
.comment "corewar"

l2:
	ld %0,r3
live:
 live	%-1
	zjmp %:live
live2:
	live %-1
	zjmp %:live2
