.name "vm_test_st"
.comment "do something"

st r1,-10
st r1,400
lld %0,r3
zjmp %7
st r1,-10
st r1,400
ldi %1,%1,r2
ldi %0,%200,r2
zjmp %7
st r1,-10
st r1,400
ldi r10,r3,r2
lldi %0,%200,r2
zjmp %10
