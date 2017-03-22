.name "test_ld_instruction"
.comment "test_registeries"

ld %6,r3
ld %:label,r3
ld :label,r3
label:
ld 10,r3
