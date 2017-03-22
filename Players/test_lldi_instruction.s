.name "test_lldi_instruction"
.comment "test_registeries"

lldi r2,%10,r3
lldi r2,%:label,r3
lldi %6,%10,r3
lldi %6,%:label2,r3
lldi %:label,%10,r3
lldi %:label,%:label2,r3
lldi :label,%10,r3
lldi :label,%:label2,r3
lldi 10,%10,r3
lldi 10,%:label2,r3
lldi r2,r10,r3
lldi %6,r10,r3
label:
lldi %:label,r10,r3
lldi :label,r10,r3
label2:
lldi 10,r10,r3
