.name "zork"
.comment "justabasiclivingprog"

l2:	add r2,r2,r2
	sti r3,%:live,%8

live:	live	%1
	zjmp	%-600
