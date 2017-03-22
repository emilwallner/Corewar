.name "test_zjmp_instruction"
.comment "test_registeries"

label2:
zjmp %10

zjmp %:label
zjmp %-13
label:
zjmp %:label2
