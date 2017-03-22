.name "stayin alive"
.comment "Ha Ha Ha stayiiiiin aliiiiiiiiiive"

sti	r1,%:live,%1
sti	r1,%:live2,%1
ld	%1,r3
ld	%33,r6
forks:
add	r2,r3,r2
xor	r2,%15,r4
live2:
	live 	%4
zjmp	%:endwhile

ld	%0,r4
zjmp	%:forks

endwhile:
ld	%0,r4

live:
live %4
zjmp %:live
