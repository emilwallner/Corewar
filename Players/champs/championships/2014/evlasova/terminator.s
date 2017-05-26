.name "terminator"
.comment "Hasta la vista, baby!"

live:
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10
		live %1
		fork %-10

protection:
			  zjmp %:live
	          ld %25, r4
	          st r4, -500
	          st r4, -500
		      st r4, -500
	          st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
	          st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
	          st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
		      st r4, -500
	          zjmp %:protection
