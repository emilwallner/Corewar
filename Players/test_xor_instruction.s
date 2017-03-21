.name "test_xor_instruction"
.comment "test_registeries"

xor r2,10,r3
xor r2,:label,r3
xor r2,r5,r3
xor %6,10,r3
xor %6,:label2,r3
xor %6,r5,r3
xor %:label,10,r3
xor %:label,:label2,r3
xor %:label,r5,r3
xor :label,10,r3
xor :label,:label2,r3
xor :label,r5,r3
label:
xor 10,10,r3
label2:
xor 10,:label2,r3
xor 10,r5,r3
