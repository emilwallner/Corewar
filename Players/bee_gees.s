.name "stayin alive"
.comment "Ha Ha Ha stayiiiiin aliiiiiiiiiive"

sti	r1,%:live,%1			#change_live_by_the_right_value
sti	r1,%:live2,%1			#change_live_by_the_right_value
ld	%1,r3
ld	%33,r6
#while_(r2_inf_a_10)
forks:
add	r2,r3,r2		#increment_r2
xor	r2,%15,r4
live2:
	live 	%4
zjmp	%:endwhile		#if_(carry)
#forksforks
ld	%0,r4			#carry_=_1
#zjmforks
#endWhile
endwhile:
ld	%0,r4			#carry_=_1

live:
live %4
zjmp %:live
