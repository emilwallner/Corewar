.name "test_and_instruction"
.comment "test_registeries"

and r2,10,r3
and r2,:label,r3
and %6,10,r3
and %6,:label2,r3
and %:label,10,r3
and %:label,:label2,r3
and :label,10,r3
and :label,:label2,r3
and 10,10,r3
and 10,:label2,r3
and r2,r10,r3
and %6,r10,r3
label:
and %:label,r10,r3
and :label,r10,r3
label2:
and 10,r10,r3

and r2,10,%2
and r2,:label3,%2
and %6,10,%2
and %6,:label2,%2
and %:label4,10,%2
and %:label,:label2,%2
and :label3,10,%2
and :label4,:label2,%2
and 10,10,%2
and 10,:label2,%2
and r2,r10,%2
and %6,r10,%2
label3:
and %:label2,r10,%2
and :label,r10,%2
label4:
and 10,r10,%2

and r2,10,%:label2
and r2,:label3,%:label2
and %6,10,%:label2
and %6,:label2,%:label2
and %:label4,10,%:label2
and %:label,:label2,%:label2
and :label3,10,%:label2
and :label4,:label2,%:label2
and 10,10,%:label2
and 10,:label2,%:label2
and r2,r10,%:label2
and %6,r10,%:label2
label3:
and %:label2,r10,%:label2
and :label,r10,%:label2
label4:
and 10,r10,%:label2
