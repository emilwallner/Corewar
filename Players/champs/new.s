.name	"Leeloo"
.comment "Multipass"
.extend
	
begin:	ld %0,r6
jump:	zjmp %:deb
.code	00	
pare:	st r0,:begin -52
	st r0,:begin -44
	st r0,:begin -52
	st r0,:begin -44
	st r0,:begin -52
	st r0,:begin -44
	st r0,:begin -52
	live %1
	st r0,:begin -44
	st r0,:begin -52
	st r0,:begin -44
	st r0,:begin -52
	st r0,:begin -44
	st r0,:begin -52
	st r0,:begin -44
	zjmp %:pare
toto:	st r15,-480
	st r4,-481
	st r7,-482
	st r8,-483
	st r13,-484
	st r14,-485
	zjmp %-510
deb:	
st1:	st r1,:lastlive1 +1
st2:	st r1,:lastlive2 +1
st3:	st r1,:lastlive3 +1
st4:	st r1,:lastlive4 +1
st5:	st r1,:live1 +1
st6:	st r1,:live2 +1
st7:	st r1,:live3 +1
st8:	st r1,:live4 +1
	ld %0x01090000 + :catch1 - :begin -1,r0
	st r0,:jump
	ld %0xFFFFFFFF,r0
	st r0,:begin -4
	st r0,:begin -8
	st r0,:begin -12

hop:	live %1
	fork %:decal2
	live %1
	ld %0,r2
	zjmp %:decal

toto1:	zjmp %:toto	
pare1:	ld %0,r0
	zjmp %:pare	
decal2: live %1
	fork %:suite
	live %1
	ld %57672448,r5
	ld %67334147,r6

	ld %57673214,r9
	ld %201551878,r10
	ld %4262136318,r11
	ld %33554432,r12

	ld %57674238,r15
	ld %369324042,r4
	ld %4262790000,r7
	ld %201200643,r8
	ld %1879899667,r13
	ld %167641600,r14
	
	fork %:separ2
	live %4
	ld %0x08F40370,r3   #ld %0x07F40370,r3

	ld %0,r2
	zjmp %:toto
separ2:	live %3
	ld %0x037004F4,r3  #ld %0x70037004,r3

	xor r2,r2,r2
	zjmp %:toto
	
padec2:	live %1
	fork %:suite
	live %1
	ld %0,r2
	zjmp %:decal

catch1:	zjmp %:catch
	
suite:	live %1
	fork %:hop
	live %1
	fork %:just
just:	live %3
	fork %:just2
just2:	live %3
	fork %:just3
just3:	live %3
	fork %:just4
	live %3
just4:	live %3
	fork %:just5
	live %3
just5:	fork %:middle
suitb:	live %3
	st r0,:st1+1
	live %3
	st r0,:st1+1
	live %3
	st r0,:st1+1
live1:	live %3
	st r0,:st1+1
live2:	live %3
	st r0,:st1+1
lastlive1: live %1
	ld %0,r6
lastlive2: live %1
	zjmp %:suitb
middle:	live %3
	st r0,:st2+1
	live %3
	st r0,:st2+1
	live %3
	st r0,:st2+1
live3:	live %3
	st r0,:st2+1
live4:	live %4
lastlive3: live %1
	ld %0,r6
lastlive4: live %1
	zjmp %:middle

	
decal:	live %1
	fork %:pare1
	live %1
	fork %:fuite
	live %1
	ld %0x03700300,r5
	ld %0x04037003,r6

	ld %0x03700501,r9
	ld %0xFC037006,r10
	ld %0x01FB0901,r11
	ld %0xF2000000,r12

	ld %0x03700901,r15
	ld %0xFC03700A,r4
	ld %0x01FB0370,r7
	ld %0x0B01FA03,r8
	ld %0x700C01F9,r13
	ld %0x0901E800,r14
	
	fork %:sepa
	live %4
	ld %0x07510370,r3
	ld %0,r2
	zjmp %:tot
sepa:	live %3
	ld %0x70037004,r3
	xor r2,r2,r2
	zjmp %:tot
catch:	
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	ld %0,r0
	zjmp %:catch
	
fuite:	live %1
	fork %:separe
	live %4
	ld %0x07510370,r3
	ld %0,r2
	zjmp %:debut
separe:	live %3
	ld %0x70037004,r3
	xor r2,r2,r2
	zjmp %:debut
	
		
tot:	st r15,488
	st r4,487
	st r7,486
	st r8,485
	st r13,484
	st r14,483
	zjmp %458
	
debut:	st r3,4
fin:

avant:	

#	075103700370075103700771

arriere:

#       08 F4 03 70 03 70 08 F4 03 70


