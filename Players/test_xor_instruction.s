.name "test_xor_instruction"
.comment "test_registeries"

xor r2,10,r3
xor r2,:label,r3
xor %6,10,r3
xor %6,:label2,r3
xor %:label,10,r3
xor %:label,:label2,r3
xor :label,10,r3
xor :label,:label2,r3
xor 10,10,r3
xor 10,:label2,r3
xor r2,r10,r3
xor %6,r10,r3
label:
xor %:label,r10,r3
xor :label,r10,r3
label2:
xor 10,r10,r3

xor r2,10,%2
xor r2,:label3,%2
xor %6,10,%2
xor %6,:label2,%2
xor %:label4,10,%2
xor %:label,:label2,%2
xor :label3,10,%2
xor :label4,:label2,%2
xor 10,10,%2
xor 10,:label2,%2
xor r2,r10,%2
xor %6,r10,%2
label3:
xor %:label2,r10,%2
xor :label,r10,%2
label4:
xor 10,r10,%2

xor r2,10,%:label2
xor r2,:label3,%:label2
xor %6,10,%:label2
xor %6,:label2,%:label2
xor %:label4,10,%:label2
xor %:label,:label2,%:label2
xor :label3,10,%:label2
xor :label4,:label2,%:label2
xor 10,10,%:label2
xor 10,:label2,%:label2
xor r2,r10,%:label2
xor %6,r10,%:label2
label3:
xor %:label2,r10,%:label2
xor :label,r10,%:label2
label4:
xor 10,r10,%:label2
