.name 		"dtonc v1.0pl3"
.comment	"ta mere elle fait du rodeo sur les kfar"
.extend

	ld	%0x80000000, r6	# moins
	ld	%10, r3		# offset
	ld	%200, r4	# range

gen:
	live	%1
	add	r2, r3, r2
	sub	r2, r4, r5
	and	r5, r6, r5
	zjmp	%:ok
	ld	%0, r2
ok:
	live	%1
	fork	%:no
	fork	%:gen
	ld	%0, r5
	zjmp	%:gen
	
no:
	live	%1	
	sti	r8, %:end, r2
	add	r2, r3, r2
	sub	r4, r2, r5	#r4 = r2
	zjmp	%:boucle2
	ld	%0, r5
	zjmp	%:no
	
boucle2:
	ld	%0, r2
	zjmp	%:no

end:	
