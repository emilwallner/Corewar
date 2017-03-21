.name "test_and_instruction"
.comment "test_registeries"

and r2,10,r3
and r2,:label,r3
and r2,r5,r3
and %6,10,r3
and %6,:label2,r3
and %6,r5,r3
and %:label,10,r3
and %:label,:label2,r3
and %:label,r5,r3
and :label,10,r3
and :label,:label2,r3
and :label,r5,r3
label:
and 10,10,r3
label2:
and 10,:label2,r3
and 10,r5,r3
