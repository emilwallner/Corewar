.name "check registries"
.comment "check registries by st everything"

st r1,-100
sti r1,%0,%0
sti r1,0,%0
st r1,-4096
lldi %400,%97,r16
