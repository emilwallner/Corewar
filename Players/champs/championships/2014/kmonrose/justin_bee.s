.name "L'arene des abeilles"
.comment "Baby, baby, baby, oh !"

ertuen:
	sti		r1, %:label1, %1
	sti		r1, %:label2, %1
	sti		r1, %:label3, %1
	sti		r1, %:label4, %1
	sti		r1, %:label5, %1
	sti		r1, %:label6, %1
	sti		r1, %:label7, %1
	sti		r1, %:label8, %1
	sti		r1, %:label9, %1
	ld		%0, r16
	fork	%:label1

label4:
	live	%314
	ld		%31415926, r2
	ld		%0, r16
	fork	%:label3

label6:
	live	%314
	ld		%0, r16
	fork	%:label5

label7:
	ld		%62821932, r5
	ld		%0, r16
	fork	%:label8
	
label2:
	live	%314
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st		r2, -450
	st      r2, -450
	st      r2, -450
	zjmp	%:label2

label1:
	live	%314
	zjmp	%:label1

label3:
	live	%314
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st		r2, 450
	st      r2, 450
	st      r2, 450
	zjmp	%:label3
	
label5:
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	live    %314
	zjmp	%:label6

label8:
	zjmp	%:label9
	st		r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500

label9:
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
	st      r5, 500
