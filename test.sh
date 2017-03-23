GREEN="\033[32m";
RED="\033[31m";
DEFAULT="\033[37m";
CYAN="\x1b[36m";
USER="Result/User/";
USER2="Result/ZaZ/"
DIFF="Result/Diff/"

# FILE="test_add_instruction";
# FILE1="test_and_instruction";
# FILE2="test_aff_instruction";
# FILE3="test_fork_instruction";
# FILE4="test_ld_instruction";
# FILE5="test_ldi_instruction";
# FILE7="test_lfork_instruction";
# FILE8="test_live_instruction";
# FILE9="test_lld_instruction";
# FILE10="test_lldi_instruction";
# FILE11="test_or_instruction";
# FILE12="test_st_instruction";
# FILE13="test_sti_instruction";
# FILE14="test_sub_instruction";
# FILE15="test_xor_instruction";
# FILE16="test_zjump_instruction";

FILE="bee_gees";
FILE2="bigzork";
FILE3="fork";
FILE5="turtle";
FILE6="zork";
FILE4="helltrain";
FILE7="id_player_dyn";
FILE8="jmp_after_load";
FILE9="jmp_after_add";
FILE10="move";
FILE11="st";
FILE12="test_add_instruction";
FILE13="test_aff_instruction";
FILE14="test_and_instruction";
FILE15="test_comment_line";
FILE16="test_comments_eol";
FILE17="test_fork_instruction";
FILE18="test_ld_instruction";
FILE19="test_ldi_instruction";
FILE20="test_lfork_instruction";
FILE21="test_live_instruction";
FILE22="test_lld_instruction";
FILE23="test_lldi_instruction";
FILE24="test_max_direct";
FILE25="test_max_indirect";
FILE26="test_max_register";
FILE27="test_min_direct";
FILE28="test_min_indirect";
FILE29="test_min_register";
FILE30="test_or_instruction";
FILE31="test_st_instruction";
FILE32="test_sti_instruction";
FILE33="test_sub_instruction";
FILE34="test_xor_instruction";
FILE35="test_zjump_instruction";


rm -dR Result
mkdir Result
mkdir Result/ZaZ
mkdir Result/User
mkdir Result/Diff

echo "\n\n\033[32m$FILE\n\033[37m"
rm players/$FILE.cor
asm_dir/asm players/$FILE.s | leaks asm
hexdump -vC players/$FILE.cor > $USER$FILE
rm players/$FILE.cor
./asm players/$FILE.s
hexdump -vC players/$FILE.cor > $USER2$FILE
diff -rsa $USER2$FILE $USER$FILE > $DIFF/diff_$FILE.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE.txt
echo "User ↑"

echo "\n\n\033[32m$FILE2\n\033[37m"
rm players/$FILE2.cor
asm_dir/asm players/$FILE2.s | leaks asm
hexdump -vC players/$FILE2.cor > $USER$FILE2
rm players/$FILE2.cor
./asm players/$FILE2.s
hexdump -vC players/$FILE2.cor > $USER2$FILE2
diff -rsa $USER2$FILE2 $USER$FILE2 > $DIFF/diff_$FILE2.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE2.txt
echo "User ↑"

echo "\n\n\033[32m$FILE3\n\033[37m"
rm players/$FILE3.cor
asm_dir/asm players/$FILE3.s | leaks asm
hexdump -vC players/$FILE3.cor > $USER$FILE3
rm players/$FILE3.cor
./asm players/$FILE3.s
hexdump -vC players/$FILE3.cor > $USER2$FILE3
diff -rsa $USER2$FILE3 $USER$FILE3 > $DIFF/diff_$FILE3.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE3.txt
echo "User ↑"

echo "\n\n\033[32m$FILE4\n\033[37m"
rm players/$FILE4.cor
asm_dir/asm players/$FILE4.s | leaks asm
hexdump -vC players/$FILE4.cor > $USER$FILE4
rm players/$FILE4.cor
./asm players/$FILE4.s
hexdump -vC players/$FILE4.cor > $USER2$FILE4
diff -rsa $USER2$FILE4 $USER$FILE4 > $DIFF/diff_$FILE4.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE4.txt
echo "User ↑"

echo "\n\n\033[32m$FILE5\n\033[37m"
rm players/$FILE5.cor
asm_dir/asm players/$FILE5.s | leaks asm
hexdump -vC players/$FILE5.cor > $USER$FILE5
rm players/$FILE5.cor
./asm players/$FILE5.s
hexdump -vC players/$FILE5.cor > $USER2$FILE5
diff -rsa $USER2$FILE5 $USER$FILE5 > $DIFF/diff_$FILE5.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE5.txt
echo "User ↑"

echo "\n\n\033[32m$FILE6\n\033[37m"
rm players/$FILE6.cor
asm_dir/asm players/$FILE6.s | leaks asm
hexdump -vC players/$FILE6.cor > $USER$FILE6
rm players/$FILE6.cor
./asm players/$FILE6.s
hexdump -vC players/$FILE6.cor > $USER2$FILE6
diff -rsa $USER2$FILE6 $USER$FILE6 > $DIFF/diff_$FILE6.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE6.txt
echo "User ↑"

echo "\n\n\033[32m$FILE7\n\033[37m"
rm players/$FILE7.cor
asm_dir/asm players/$FILE7.s | leaks asm
hexdump -vC players/$FILE7.cor > $USER$FILE7
rm players/$FILE7.cor
./asm players/$FILE7.s
hexdump -vC players/$FILE7.cor > $USER2$FILE7
diff -rsa $USER2$FILE7 $USER$FILE7 > $DIFF/diff_$FILE7.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE7.txt
echo "User ↑"

echo "\n\n\033[32m$FILE8\n\033[37m"
rm players/$FILE8.cor
asm_dir/asm players/$FILE8.s | leaks asm
hexdump -vC players/$FILE8.cor > $USER$FILE8
rm players/$FILE8.cor
./asm players/$FILE8.s
hexdump -vC players/$FILE8.cor > $USER2$FILE8
diff -rsa $USER2$FILE8 $USER$FILE8 > $DIFF/diff_$FILE8.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE8.txt
echo "User ↑"

echo "\n\n\033[32m$FILE9\n\033[37m"
rm players/$FILE9.cor
asm_dir/asm players/$FILE9.s | leaks asm
hexdump -vC players/$FILE9.cor > $USER$FILE9
rm players/$FILE9.cor
./asm players/$FILE9.s
hexdump -vC players/$FILE9.cor > $USER2$FILE9
diff -rsa $USER2$FILE9 $USER$FILE9 > $DIFF/diff_$FILE9.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE9.txt
echo "User ↑"

echo "\n\n\033[32m$FILE10\n\033[37m"
rm players/$FILE10.cor
asm_dir/asm players/$FILE10.s | leaks asm
hexdump -vC players/$FILE10.cor > $USER$FILE10
rm players/$FILE10.cor
./asm players/$FILE10.s
hexdump -vC players/$FILE10.cor > $USER2$FILE10
diff -rsa $USER2$FILE10 $USER$FILE10 > $DIFF/diff_$FILE10.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE10.txt
echo "User ↑"

echo "\n\n\033[32m$FILE11\n\033[37m"
rm players/$FILE11.cor
asm_dir/asm players/$FILE11.s | leaks asm
hexdump -vC players/$FILE11.cor > $USER$FILE11
rm players/$FILE11.cor
./asm players/$FILE11.s
hexdump -vC players/$FILE11.cor > $USER2$FILE11
diff -rsa $USER2$FILE11 $USER$FILE11 > $DIFF/diff_$FILE11.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE11.txt
echo "User ↑"

echo "\n\n\033[32m$FILE12\n\033[37m"
rm players/$FILE12.cor
asm_dir/asm players/$FILE12.s | leaks asm
hexdump -vC players/$FILE12.cor > $USER$FILE12
rm players/$FILE12.cor
./asm players/$FILE12.s
hexdump -vC players/$FILE12.cor > $USER2$FILE12
diff -rsa $USER2$FILE12 $USER$FILE12 > $DIFF/diff_$FILE12.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE12.txt
echo "User ↑"

echo "\n\n\033[32m$FILE13\n\033[37m"
rm players/$FILE13.cor
asm_dir/asm players/$FILE13.s | leaks asm
hexdump -vC players/$FILE13.cor > $USER$FILE13
rm players/$FILE13.cor
./asm players/$FILE13.s
hexdump -vC players/$FILE13.cor > $USER2$FILE13
diff -rsa $USER2$FILE13 $USER$FILE13 > $DIFF/diff_$FILE13.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE13.txt
echo "User ↑"

echo "\n\n\033[32m$FILE14\n\033[37m"
rm players/$FILE14.cor
asm_dir/asm players/$FILE14.s | leaks asm
hexdump -vC players/$FILE14.cor > $USER$FILE14
rm players/$FILE14.cor
./asm players/$FILE14.s
hexdump -vC players/$FILE14.cor > $USER2$FILE14
diff -rsa $USER2$FILE14 $USER$FILE14 > $DIFF/diff_$FILE14.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE14.txt
echo "User ↑"

echo "\n\n\033[32m$FILE15\n\033[37m"
rm players/$FILE15.cor
asm_dir/asm players/$FILE15.s | leaks asm
hexdump -vC players/$FILE15.cor > $USER$FILE15
rm players/$FILE15.cor
./asm players/$FILE15.s
hexdump -vC players/$FILE15.cor > $USER2$FILE15
diff -rsa $USER2$FILE15 $USER$FILE15 > $DIFF/diff_$FILE15.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE15.txt
echo "User ↑"

echo "\n\n\033[32m$FILE16\n\033[37m"
rm players/$FILE16.cor
asm_dir/asm players/$FILE16.s | leaks asm
hexdump -vC players/$FILE16.cor > $USER$FILE16
rm players/$FILE16.cor
./asm players/$FILE16.s
hexdump -vC players/$FILE16.cor > $USER2$FILE16
diff -rsa $USER2$FILE16 $USER$FILE16 > $DIFF/diff_$FILE16.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE16.txt
echo "User ↑"

echo "\n\n\033[32m$FILE17\n\033[37m"
rm players/$FILE17.cor
asm_dir/asm players/$FILE17.s | leaks asm
hexdump -vC players/$FILE17.cor > $USER$FILE17
rm players/$FILE17.cor
./asm players/$FILE17.s
hexdump -vC players/$FILE17.cor > $USER2$FILE17
diff -rsa $USER2$FILE17 $USER$FILE17 > $DIFF/diff_$FILE17.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE17.txt
echo "User ↑"

echo "\n\n\033[32m$FILE18\n\033[37m"
rm players/$FILE18.cor
asm_dir/asm players/$FILE18.s | leaks asm
hexdump -vC players/$FILE18.cor > $USER$FILE18
rm players/$FILE18.cor
./asm players/$FILE18.s
hexdump -vC players/$FILE18.cor > $USER2$FILE18
diff -rsa $USER2$FILE18 $USER$FILE18 > $DIFF/diff_$FILE18.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE18.txt
echo "User ↑"

echo "\n\n\033[32m$FILE19\n\033[37m"
rm players/$FILE19.cor
asm_dir/asm players/$FILE19.s | leaks asm
hexdump -vC players/$FILE19.cor > $USER$FILE19
rm players/$FILE19.cor
./asm players/$FILE19.s
hexdump -vC players/$FILE19.cor > $USER2$FILE19
diff -rsa $USER2$FILE19 $USER$FILE19 > $DIFF/diff_$FILE19.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE19.txt
echo "User ↑"

echo "\n\n\033[32m$FILE20\n\033[37m"
rm players/$FILE20.cor
asm_dir/asm players/$FILE20.s | leaks asm
hexdump -vC players/$FILE20.cor > $USER$FILE20
rm players/$FILE20.cor
./asm players/$FILE20.s
hexdump -vC players/$FILE20.cor > $USER2$FILE20
diff -rsa $USER2$FILE20 $USER$FILE20 > $DIFF/diff_$FILE20.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE20.txt
echo "User ↑"

echo "\n\n\033[32m$FILE20\n\033[37m"
rm players/$FILE20.cor
asm_dir/asm players/$FILE20.s | leaks asm
hexdump -vC players/$FILE20.cor > $USER$FILE20
rm players/$FILE20.cor
./asm players/$FILE20.s
hexdump -vC players/$FILE20.cor > $USER2$FILE20
diff -rsa $USER2$FILE20 $USER$FILE20 > $DIFF/diff_$FILE20.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE20.txt
echo "User ↑"

echo "\n\n\033[32m$FILE21\n\033[37m"
rm players/$FILE21.cor
asm_dir/asm players/$FILE21.s | leaks asm
hexdump -vC players/$FILE21.cor > $USER$FILE21
rm players/$FILE21.cor
./asm players/$FILE21.s
hexdump -vC players/$FILE21.cor > $USER2$FILE21
diff -rsa $USER2$FILE21 $USER$FILE21 > $DIFF/diff_$FILE21.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE21.txt
echo "User ↑"

echo "\n\n\033[32m$FILE22\n\033[37m"
rm players/$FILE22.cor
asm_dir/asm players/$FILE22.s | leaks asm
hexdump -vC players/$FILE22.cor > $USER$FILE22
rm players/$FILE22.cor
./asm players/$FILE22.s
hexdump -vC players/$FILE22.cor > $USER2$FILE22
diff -rsa $USER2$FILE22 $USER$FILE22 > $DIFF/diff_$FILE22.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE22.txt
echo "User ↑"

echo "\n\n\033[32m$FILE23\n\033[37m"
rm players/$FILE23.cor
asm_dir/asm players/$FILE23.s | leaks asm
hexdump -vC players/$FILE23.cor > $USER$FILE23
rm players/$FILE23.cor
./asm players/$FILE23.s
hexdump -vC players/$FILE23.cor > $USER2$FILE23
diff -rsa $USER2$FILE23 $USER$FILE23 > $DIFF/diff_$FILE23.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE23.txt
echo "User ↑"

echo "\n\n\033[32m$FILE24\n\033[37m"
rm players/$FILE24.cor
asm_dir/asm players/$FILE24.s | leaks asm
hexdump -vC players/$FILE24.cor > $USER$FILE24
rm players/$FILE24.cor
./asm players/$FILE24.s
hexdump -vC players/$FILE24.cor > $USER2$FILE24
diff -rsa $USER2$FILE24 $USER$FILE24 > $DIFF/diff_$FILE24.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE24.txt
echo "User ↑"

echo "\n\n\033[32m$FILE25\n\033[37m"
rm players/$FILE25.cor
asm_dir/asm players/$FILE25.s | leaks asm
hexdump -vC players/$FILE25.cor > $USER$FILE25
rm players/$FILE25.cor
./asm players/$FILE25.s
hexdump -vC players/$FILE25.cor > $USER2$FILE25
diff -rsa $USER2$FILE25 $USER$FILE25 > $DIFF/diff_$FILE25.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE25.txt
echo "User ↑"

echo "\n\n\033[32m$FILE26\n\033[37m"
rm players/$FILE26.cor
asm_dir/asm players/$FILE26.s | leaks asm
hexdump -vC players/$FILE26.cor > $USER$FILE26
rm players/$FILE26.cor
./asm players/$FILE26.s
hexdump -vC players/$FILE26.cor > $USER2$FILE26
# diff -rsa $USER2$FILE26 $USER$FILE26 > $DIFF/diff_$FILE26.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE26.txt
echo "User ↑"

echo "\n\n\033[32m$FILE27\n\033[37m"
rm players/$FILE27.cor
asm_dir/asm players/$FILE27.s | leaks asm
hexdump -vC players/$FILE27.cor > $USER$FILE27
rm players/$FILE27.cor
./asm players/$FILE27.s
hexdump -vC players/$FILE27.cor > $USER2$FILE27
diff -rsa $USER2$FILE27 $USER$FILE27 > $DIFF/diff_$FILE27.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE27.txt
echo "User ↑"

echo "\n\n\033[32m$FILE28\n\033[37m"
rm players/$FILE28.cor
asm_dir/asm players/$FILE28.s | leaks asm
hexdump -vC players/$FILE28.cor > $USER$FILE28
rm players/$FILE28.cor
./asm players/$FILE28.s
hexdump -vC players/$FILE28.cor > $USER2$FILE28
diff -rsa $USER2$FILE28 $USER$FILE28 > $DIFF/diff_$FILE28.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE28.txt
echo "User ↑"

echo "\n\n\033[32m$FILE29\n\033[37m"
rm players/$FILE29.cor
asm_dir/asm players/$FILE29.s | leaks asm
hexdump -vC players/$FILE29.cor > $USER$FILE29
rm players/$FILE29.cor
./asm players/$FILE29.s
hexdump -vC players/$FILE29.cor > $USER2$FILE29
# diff -rsa $USER2$FILE29 $USER$FILE29 > $DIFF/diff_$FILE29.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE29.txt
echo "User ↑"

echo "\n\n\033[32m$FILE30\n\033[37m"
rm players/$FILE30.cor
asm_dir/asm players/$FILE30.s | leaks asm
hexdump -vC players/$FILE30.cor > $USER$FILE30
rm players/$FILE30.cor
./asm players/$FILE30.s
hexdump -vC players/$FILE30.cor > $USER2$FILE30
diff -rsa $USER2$FILE30 $USER$FILE30 > $DIFF/diff_$FILE30.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE30.txt
echo "User ↑"

echo "\n\n\033[32m$FILE31\n\033[37m"
rm players/$FILE31.cor
asm_dir/asm players/$FILE31.s | leaks asm
hexdump -vC players/$FILE31.cor > $USER$FILE31
rm players/$FILE31.cor
./asm players/$FILE31.s
hexdump -vC players/$FILE31.cor > $USER2$FILE31
diff -rsa $USER2$FILE31 $USER$FILE31 > $DIFF/diff_$FILE31.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE31.txt
echo "User ↑"

echo "\n\n\033[32m$FILE32\n\033[37m"
rm players/$FILE32.cor
asm_dir/asm players/$FILE32.s | leaks asm
hexdump -vC players/$FILE32.cor > $USER$FILE32
rm players/$FILE32.cor
./asm players/$FILE32.s
hexdump -vC players/$FILE32.cor > $USER2$FILE32
diff -rsa $USER2$FILE32 $USER$FILE32 > $DIFF/diff_$FILE32.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE32.txt
echo "User ↑"

echo "\n\n\033[32m$FILE33\n\033[37m"
rm players/$FILE33.cor
asm_dir/asm players/$FILE33.s | leaks asm
hexdump -vC players/$FILE33.cor > $USER$FILE33
rm players/$FILE33.cor
./asm players/$FILE33.s
hexdump -vC players/$FILE33.cor > $USER2$FILE33
diff -rsa $USER2$FILE33 $USER$FILE33 > $DIFF/diff_$FILE33.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE33.txt
echo "User ↑"

echo "\n\n\033[32m$FILE34\n\033[37m"
rm players/$FILE34.cor
asm_dir/asm players/$FILE34.s | leaks asm
hexdump -vC players/$FILE34.cor > $USER$FILE34
rm players/$FILE34.cor
./asm players/$FILE34.s
hexdump -vC players/$FILE34.cor > $USER2$FILE34
diff -rsa $USER2$FILE34 $USER$FILE34 > $DIFF/diff_$FILE34.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE34.txt
echo "User ↑"

echo "\n\n\033[32m$FILE35\n\033[37m"
rm players/$FILE35.cor
asm_dir/asm players/$FILE35.s | leaks asm
hexdump -vC players/$FILE35.cor > $USER$FILE35
rm players/$FILE35.cor
./asm players/$FILE35.s
hexdump -vC players/$FILE35.cor > $USER2$FILE35
diff -rsa $USER2$FILE35 $USER$FILE35 > $DIFF/diff_$FILE35.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE35.txt
echo "User ↑"
