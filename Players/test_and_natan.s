.name "test_and_instruction"
.comment "test_registeries"

st	r2, -1
and r2,10,r3
and r2,:label,r4
and r2,r5,r5
and %6,10,r6
and %6,:label2,r7
and %6,r5,r8
and %:label,10,r9
and %:label,:label2,r10
and %:label,r5,r11
and :label,10,r12
and :label,:label2,r13
and :label,r5,r14
label:
and 10,10,r15
label2:
and 10,:label2,r16
and 10,r5,r3
