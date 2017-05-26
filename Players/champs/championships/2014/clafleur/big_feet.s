# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    big_feet.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clafleur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/16 20:28:04 by clafleur          #+#    #+#              #
#    Updated: 2014/03/02 17:23:26 by clafleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name "top defense plus plus"
.comment "la meilleure defense c'est d'avoir une bonne defense"

start:

start_piege:
ld		%-16, r5				# r2 = soustraction de start pr aller a r2 : carry a 1
ld		%-12, r4				# r4 = suite (soustraction de start pr aller a r3 : suite du carry)
ld		%-8, r6					# r6 = soustration de start pr aller a r10 : zjmp
ld		%150994944, r10			# r10 = zjmp
ld		%42991616, r2			# debut de carry a 1
ld		%256, r3				# suite du carry a 1
ld		%16, r16				# decrementation de start
ld		%12, r7					# r7 = addition de end pr aller a r7 : carry a 1
ld		%16, r9					# r9 = suite (addition de end pr aller a r9 : suite du carry)
ld		%20, r11				# r11 = addition de end pr aller a r11 : zjmp
ld		%23, r12				# compteur pour le nombres de pieges
ld		%1, r13
ld		%0, r8					# carry = 1
sti		r1, %:piege1, %1
sti		r1, %:piege2, %1
sti		r1, %:begin, %1
sti		r1, %:live, %1
fork	%:begin

piege1:							# while(1)
live	%118978653103279		# je suis en vie
sti		r2, %:start, r5 
sti		r3, %:start, r4
sti		r10, %:start, r6
sub		r5, r16, r5
sub		r4, r16, r4
sub		r6, r16, r6
sub		r12, r13, r12			# decrementation du compteur
zjmp	%:start_piege			# reviens en debut de boucle
ld		%0, r8					# carry = 1
zjmp	%:piege1				# reviens en debut de boucle

begin:
live 	%13371337
fork	%:piege1
live 	%42424242
fork	%:piege2
live 	%123456789
fork	%:begin
live	%08395432657
fork	%:live
zjmp	%:begin

live:
live	%23456789456780987
zjmp	%:begin

piege2:
live	%198562346853412
sti		r2, %:end, r7 
sti		r3, %:end, r9
sti		r10, %:end, r11
add		r7, r16, r7
add		r9, r16, r9
add		r11, r16, r11
sub		r12, r13, r12			# decrementation du compteur
zjmp	%:start_piege			# reviens en debut de boucle
ld		%0, r8					# carry = 1
zjmp	%:piege2				# reviens en debut de boucle

end:
