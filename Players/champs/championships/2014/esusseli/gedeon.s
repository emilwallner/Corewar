.name		"Gédéon le Cochon"
.comment	"Tout est bon dans Gédéon"

tmp:
	sti		r1, %:youshallnotpass, %1
	sti		r1, %:core, %1
	sti		r1, %:core, %9
	sti		r1, %:core, %17
	sti		r1, %:core, %25
	sti		r1, %:live1, %1
	sti		r1, %:live2, %1
	sti		r1, %:youshallnotpass2, %1
	ld		%0, r1
	fork	%:core

trap:
	ld		%0, r1

youshallnotpass:
	live	%1337
	st		r1, -16
	st		r1, -25
	st		r1, -34
	st		r1, -43
	st		r1, -52
	st		r1, -61
	st		r1, -70
	st		r1, -79
	st		r1, -88
	st		r1, -97
	st		r1, -106
	st		r1, -115
	st		r1, -124
	st		r1, -133
	st		r1, -142
	st		r1, -151
	st		r1, -160
	st		r1, -410
	st		r1, -411
	st		r1, -412
	st		r1, -413
	st		r1, -414
	st		r1, -425
	st		r1, -416
	st		r1, -417
	st		r1, -418
	st		r1, -419
	ld		%0, r1
	zjmp	%:youshallnotpass

core:
	live	%1337
	fork	%:youshallnotpass
	live	%1337
	fork	%:youshallnotpass2
	live	%1337
	fork	%:live1
	live	%1337
	fork	%:core
	#ld		%0, r1
	zjmp	%:core

live1:
	live	%1337
	fork	%:live1
	ld		%0, r1

live2:
	live	%1337
	zjmp	%:live2

youshallnotpass2:
	live	%1337
	st		r1, 30
	st		r1, 29
	st		r1, 28
	st		r1, 27
	ld		%0, r1
	zjmp	%:youshallnotpass2
