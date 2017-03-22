.name "test_or_instruction"
.comment "test_registeries"

or r2,10,r3
or r2,:label,r3
or r2,r5,r3
or %6,10,r3
or %6,:label2,r3
or %6,r5,r3
or %:label,10,r3
or %:label,:label2,r3
or %:label,r5,r3
or :label,10,r3
or :label,:label2,r3
or :label,r5,r3
label:
or 10,10,r3
label2:
or 10,:label2,r3
or 10,r5,r3
