.name "zork"
.comment "just a basic living prog"

l2:	add r2,r2,r2
	sti r3,%:live,%8	#coucou

#coucou

#coucou  #test
live:	live	%1
	zjmp	%:live #kljhlh
