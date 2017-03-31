.name "vm_test_st"
.comment "do something"

label2:
sti r3,r2,r10
sti r3,r2,%-10
sti r3,r2,%:label
sti r3,%6,%10
sti r3,%6,%:label2
sti r3,%:label,%10
sti r3,%:label,%:label2
sti r3,:label,%200
sti r3,:label,%:label2
sti r3,10,%200
sti r3,10,%:label2
sti r3,r2,r20
sti r3,%6,r10
label:
sti r3,%:label,r10
sti r3,:label,r10
sti r3,10,r10
ld %512,r3
sti r3,%512,%513
sti r3,%511,%10
