.name "test_or_instruction"
.comment "test_registeries"

or r2,10,r3
or r2,:label,r3
or %6,10,r3
or %6,:label2,r3
or %:label,10,r3
or %:label,:label2,r3
or :label,10,r3
or :label,:label2,r3
or 10,10,r3
or 10,:label2,r3
or r2,r10,r3
or %6,r10,r3
label:
or %:label,r10,r3
or :label,r10,r3
label2:
or 10,r10,r3

or r2,10,%2
or r2,:label3,%2
or %6,10,%2
or %6,:label2,%2
or %:label4,10,%2
or %:label,:label2,%2
or :label3,10,%2
or :label4,:label2,%2
or 10,10,%2
or 10,:label2,%2
or r2,r10,%2
or %6,r10,%2
label3:
or %:label2,r10,%2
or :label,r10,%2
label4:
or 10,r10,%2

or r2,10,%:label2
or r2,:label3,%:label2
or %6,10,%:label2
or %6,:label2,%:label2
or %:label4,10,%:label2
or %:label,:label2,%:label2
or :label3,10,%:label2
or :label4,:label2,%:label2
or 10,10,%:label2
or 10,:label2,%:label2
or r2,r10,%:label2
or %6,r10,%:label2
label3:
or %:label2,r10,%:label2
or :label,r10,%:label2
label4:
or 10,r10,%:label2
