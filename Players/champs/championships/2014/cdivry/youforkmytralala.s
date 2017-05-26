.name		"Oh, You Fork my TRALALA ..."
.comment	"HMMMM, my ding-ding-dong !!"

# LD : charge la valeur du 1er param dans le registre

# ST : stocke la valeur du registre vers le second paramètre.

# ADD : Additionne les 2 premiers registres, et met le résultat dans le 3eme.

# SUB : Soustrait les 2 premiers registres, et met le résultat dans le 3eme.

# AND : Applique un & (ET bit-a-bit) sur les 2 premiers registres, et met le 
# résultat dans le 3eme.

# OR : Applique un OU (bit-a-bit) sur les 2 premiers registres, et met le 
#résultat dans le troisième.

# XOR : Fait un OU exclusif bit a bit (c'est comme un OU normal, mais 1^1 = 0)

# ZJMP : saute a l'adresse si le carry est a 1.

# LDI : additionne les 2 premiers, traite ca comme une adresse, y lit une valeur
# de la taille d’un registre et la met dans le 3eme.

# STI  : additionne les 2 derniers, utilise cette somme comme une adresse ou 
# sera copiee la valeur du 1er param

# FORK : Crée un nouveau processus, qui hérite des diﬀérents états de son père,
 # à part son PC, qui est mis à (PC + (1er paramètre % IDX_MOD)).

# LLD : similaire a ld sans la restriction de IDX_MOD (ici 512) (a confirmer)

# LLDI : Pareil que ldi, mais n’applique aucun modulo aux adresses.

# LFORK : Pareil qu’un fork sans modulo à l'adresse.

# AFF : affiche sur la sortie standard le char ASCII

entry:
	st		r1, 6
	st		r1, r3
	live	%42
	fork	%:hanibalsmith
	zjmp	%:move1

hanibalsmith:
	live	%42
	st		r15, -50
	st		r15, -64
	st		r15, -78
	st		r15, -92
	st		r15, -106
	st		r15, -120
	st		r15, -134
	st		r15, -148
	st		r15, -162
	st		r15, -176
	st		r15, -190
	st		r15, -204
	st		r15, -218
	st		r15, -232
	st		r15, -246
	st		r15, -260
	st		r15, -274
	st		r15, -288
	st		r15, -302
	st		r15, -318
	st		r15, -332
	st		r15, -346
	st		r15, -360
	st		r15, -374
	st		r15, -388
	st		r15, -402
	st		r15, -416
	st		r15, -430
	st		r15, -444
	st		r15, -458
	st		r15, -472
	st		r15, -486
	st		r15, -500
	st		r16, 1
	live	%42
	fork	%:hanibalsmith
	zjmp	%:hanibalsmith

forking:
	live	%898
	fork	%:move2
	live	%1892
	fork	%:move2
	live	%4024
	fork	%:move2
	live	%232
	fork	%:move2

move1:
	st		r1, 6
	live	%5
	fork	%:move1
	zjmp	%9

move2:
	st		r1, 6
	live	%42
	fork	%:move2
	zjmp	%1

move3:
	st		r1, 6
	live	%42
	fork	%:move3
	zjmp	%2

move4:
	st		r1, 6
	live	%7
	fork	%:move4
	zjmp	%3

move5:
	st		r1, 6
	live	%1
	fork	%:move5
	zjmp	%4

hanibalsmith2:
	live	%512
	st		r14, 1
	st		r14, -203
	st		r14, -406
	st		r14, -609
	st		r14, -803
	st		r14, -1006
	st		r14, -1209
	st		r14, -1403
	st		r14, -1606
	st		r14, -1809
	st		r14, -2003
	st		r14, -2206
	st		r14, -2409
	st		r14, -2603
	st		r14, -2806
	st		r14, -3009
	st		r14, -3203
	st		r14, -3406
	st		r14, -3609
	st		r14, -3803
	st		r14, -4006
	st		r14, -4209
	st		r14, -4403
	st		r14, -4606
	st		r14, -4809
	st		r14, -5003
	st		r14, -5206
	st		r14, -5409
	st		r14, -5603
	st		r14, -5806
	st		r14, -6009
	st		r14, -6203
	st		r14, -6406
	st		r14, -6609
	st		r14, -6803
	st		r14, -7006
	st		r14, -7209
	st		r14, -7403
	st		r14, -7606
	st		r14, -7809
	st		r14, -8003
	st		r1, 6
	live	%1
	zjmp	%:hanibalsmith2
	fork	%:hanibalsmith2
