.name "test_sti_instruction"
.comment "test_registeries"

sti r3,r2,r10
sti r3,r2,%-10
sti r3,r2,%:label
sti r3,%6,%10
sti r3,%6,%:label2
sti r3,%:label,%10
sti r3,%:label,%:label2
sti r3,:label,%10
sti r3,:label,%:label2
sti r3,10,%10
sti r3,10,%:label2
sti r3,r2,r10
sti r3,%6,r10
label:
sti r3,%:label,r10
sti r3,:label,r10
label2:
sti r3,10,r10
