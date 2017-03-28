.name "test_ldi_instruction"
.comment "test_registeries"

st r1,-20
ld -25,r3
st r3,-20
ldi r1,r1,r3
st r3,-26
ldi %6,%10,r3
ldi %6,%:label2,r3
ldi %:label,%10,r3
ldi %:label,%:label2,r3
ldi :label,%10,r3
ldi :label,%:label2,r3
ldi 10,%10,r3
ldi 10,%:label2,r3
ldi r2,r10,r3
ldi %6,r10,r3
label:
ldi %:label,r10,r3
ldi :label,r10,r3
label2:
ldi 10,r10,r3
