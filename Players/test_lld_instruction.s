.name "test_lld_instruction"
.comment "test_registeries"

lld %6,r3
lld %:label,r3
lld :label,r3
label:
lld 10,r3
