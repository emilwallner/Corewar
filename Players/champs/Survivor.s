.name    "Survivor"
.comment "Invincible"

	live	%1
	fork	%:f1
	zjmp	%:j1
<<<<<<< .mine
f1:	ld	%5, r2
=======
f1:	ld	%4, r2
>>>>>>> .r20
	zjmp	%:run
j1:	
run:	xor	r0, r0, r0
l1:	st	r2, 1
	live	%1
	zjmp	%:l1
               
 
	