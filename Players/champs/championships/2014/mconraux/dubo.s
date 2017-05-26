.name "dubo"
.comment "Tu veux du pain"

pede:
live %1
live %1
live %1
live %1
live %1
live %1
live %1
zjmp %:pede

nodeadplz:
	live %1
	live %1
	live %1
	live %3
	live %2
	live %2
	zjmp %:nodeadplz

