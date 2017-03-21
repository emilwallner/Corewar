.name "test_live_instruction"
.comment "test_registeries"

label2:
live %10

live %:label
live %-13
label:
live %:label2
