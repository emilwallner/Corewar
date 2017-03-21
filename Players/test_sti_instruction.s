.name "test_sti_instruction"
.comment "test_registeries"

ldi r3,r2,%10
ldi r3,r2,%:label
ldi r3,%6,%10
ldi r3,%6,%:label2
ldi r3,%:label,%10
ldi r3,%:label,%:label2
ldi r3,:label,%10
ldi r3,:label,%:label2
ldi r3,10,%10
ldi r3,10,%:label2
ldi r3,r2,r10
ldi r3,%6,r10
label:
ldi r3,%:label,r10
ldi r3,:label,r10
label2:
ldi r3,10,r10
