# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Kappa.s                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/13 21:37:45 by gudepard          #+#    #+#              #
#    Updated: 2014/02/15 01:27:59 by gudepard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name				"Kappa"
.comment			"AKA Kappa Sandwich."

	# st	r2,	15
	# st	r3,	-1
	# live	%1							  |      r1       |
	# 0370 0200		0f03 7003		ffff 01xx		xxxx xx
	# 57672192		251883523		4294902016		xx

	# p1 -> r2 : 57672192
	#	 -> r3 : 19 st r3 -> 1303 7003 -> 318992387

	# p2 -> r2 : 251883523
	# 	 -> r3 : 23 st r3 -> 1703 7003 -> 386101251

	# p3 -> r2 : 4294902016
	#	 -> r3 : 26 st r3 -> 1A03 7003 -> 436432899

	# p4 -> r2 : r1
	#	 -> r3 : 15 st r3 -> 0f03 7003 -> 251883523

	#### REVERSE
	# st	r2,	-18
	# st	r3,	-1
	# live	%1							  -7			   -3
	# zjmp	%-15						  |      r1        |
	# 0370 02ff		ee03 7003		ffff 01xx		xxxx xx	09ffdf[03]
	# 57672447		3993202691		4294902016		xx		167763715

	# p1 -> r2 : 57672447
	#	 -> r3 : -14 st r3 -> f203 7003 -> 4060311555

	# p2 -> r2 : 3993202691
	#	 -> r3 : -10 st r3 -> f603 7003 -> 4127420419

	# p3 -> r2 : 4294902016
	#	 -> r3 : -7 st r3 -> f903 7003 -> 4177752067

	# p4 -> r2 : r1
	#	 -> r3 : -3 st r3 -> fd03 7003 -> 4244860931

	# p5 -> r2 : 167763715
	#	 -> r3 : -18 st r3 -> ee03 7003 -> 3993202691

	# 0000 0370		02ff ee03	7003 ffff	0100 0000	0109 ffdf
	# 880			50327043	1879310335	16777216	17432543

		sti		r1,		%:alive,		%1
		ld		%75,	r13
		aff		r13
		fork	%:init_forward
		live	%1337

init_backward:
		ld		%880,			r5		# 7
		ld		%50327043,		r6		# 7
		ld		%1879310335,	r7		# 7
		ld		%16777216,		r8		# 7
		ld		%17432543,		r9		# 7
		st		r5,				-80		# 5
		st		r6,				-81		# 5
		st		r7,				-82		# 5
		st		r8,				-83		# 5
		st		r9,				-84		# 5
		fork	%:r_p5					# 3
		live	%42						# 5
		fork	%:r_p4					# 3
		live	%42						# 5
		fork	%:r_p3					# 3
		live	%42						# 5
		fork	%:r_p2					# 3
		live	%42						# 5
		fork	%:r_p1					# 3
		ld		%0,				r2		# 7 carry = 1
		zjmp	%:init_forward			# 3

r_p1:
		ld		%57672447,		r2		# 7
		ld		%4060311555,	r3		# 7
		ld		%0,				r4		# 7
r_p1_2:
		live	%42						# 5
		fork	%:r_p1_2				# 3
		zjmp	%-177					# 3

r_p2:
		live	%42						# 5
		ld		%3993202691,	r2		# 7
		ld		%4127420419,	r3		# 7
		or		r12,	r12,	r12		# 5
		ld		%0,				r4		# 7
		fork	%:alive					# 3
r_p2_2:
		live	%42						# 5
		fork	%:r_p2_2				# 3
		zjmp	%-222					# 3

r_p3:
		live	%42						# 5
		ld		%4294902016,	r2		# 7
		ld		%4177752067,	r3		# 7
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		ld		%0,				r4		# 7
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
r_p3_2:
		live	%42						# 5
		fork	%:r_p3_2				# 3
		zjmp	%-280					# 3

r_p4:
		live	%42						# 5
		st		r1,				r2		# 7
		ld		%4244860931,	r3		# 7
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		ld		%0,				r4		# 7
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
r_p4_2:
		live	%42						# 5
		fork	%:r_p4_2				# 3
		zjmp	%-348					# 3

r_p5:
		live	%42						# 5
		ld		%167763715,		r2		# 7
		ld		%3993202691,	r3		# 7
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		or		r12,	r12,	r12		# 5
		ld		%0,				r4		# 7
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
		live	%42						# 5
		fork	%:alive					# 3
r_p5_2:
		live	%42						# 5
		fork	%:r_p5_2				# 3
		zjmp	%-432					# 3

init_forward:
		live	%42
		fork	%:p4
		live	%42
		fork	%:p3
		live	%42
		fork	%:p2
		live	%42
		fork	%:p1
		ld		%0,				r2	# carry = 1

alive:
		live	%42
		zjmp	%:alive

p1:
		ld		%57672192,		r2
		ld		%318992387,		r3
		ld		%0,				r4	# carry = 1
p1_2:
		live	%42
		fork	%:p1_2
		zjmp	%:move_forward

p2:
		live	%42
		ld		%251883523,		r2
		ld		%386101251,		r3
		or		r12,	r12,	r12
		ld		%0,				r4	# carry = 1
		fork	%:alive
p2_2:
		live	%42
		fork	%:p2_2
		zjmp	%:move_forward

p3:
		live	%42
		ld		%4294902016,	r2
		ld		%436432899,		r3
		or		r12,	r12,	r12
		or		r12,	r12,	r12
		ld		%0,				r4	# carry = 1
		fork	%:alive
		live	%42
		fork	%:alive
p3_2:
		live	%42
		fork	%:p3_2
		zjmp	%:move_forward

p4:
		live	%42
		st		r1,				r2
		ld		%251883523,		r3
		or		r12,	r12,	r12
		or		r12,	r12,	r12
		or		r12,	r12,	r12
		ld		%0,				r4	# carry = 1
		fork	%:alive
		live	%42
		fork	%:alive
		live	%42
		fork	%:alive
p4_2:
		live	%42
		fork	%:p4_2
		zjmp	%:move_forward

move_forward:
		st		r2,				15
		st		r3,				-1
		live	%1337
