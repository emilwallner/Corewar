GREEN="\033[32m";
RED="\033[31m";
DEFAULT="\033[37m";
CYAN="\x1b[36m";
USER="Result/User/";
USER2="Result/ZaZ/"
DIFF="Result/Diff/"

FILE="test_add_instruction";
FILE1="test_and_instruction";
FILE2="test_aff_instruction";
FILE3="test_fork_instruction";
FILE4="test_ld_instruction";
FILE5="test_ldi_instruction";
FILE7="test_lfork_instruction";
FILE8="test_live_instruction";
FILE9="test_lld_instruction";
FILE10="test_lldi_instruction";
FILE11="test_or_instruction";
FILE12="test_st_instruction";
FILE13="test_sti_instruction";
FILE14="test_sub_instruction";
FILE15="test_xor_instruction";
FILE16="test_zjump_instruction";


rm -dR Result
mkdir Result
mkdir Result/ZaZ
mkdir Result/User
mkdir Result/Diff

echo "\n\n\033[32m$FILE\n\033[37m"
rm players/$FILE.cor
asm_dir/asm players/$FILE.s
hexdump -vC players/$FILE.cor > $USER$FILE
rm players/$FILE.cor
./asm players/$FILE.s
hexdump -vC players/$FILE.cor > $USER2$FILE
diff -rsa $USER2$FILE $USER$FILE > $DIFF/diff_$FILE.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE.txt
echo "User ↑"

echo "\n\n\033[32m$FILE1\n\033[37m"
rm players/$FILE1.cor
asm_dir/asm players/$FILE1.s
hexdump -vC players/$FILE1.cor > $USER$FILE1
rm players/$FILE1.cor
./asm players/$FILE1.s
hexdump -vC players/$FILE1.cor > $USER2$FILE1
diff -rsa $USER2$FILE1 $USER$FILE1 > $DIFF/diff_$FILE1.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE1.txt
echo "User ↑"

echo "\n\n\033[32m$FILE2\n\033[37m"
rm players/$FILE2.cor
asm_dir/asm players/$FILE2.s
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
asm_dir/asm players/$FILE3.s
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
asm_dir/asm players/$FILE4.s
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
asm_dir/asm players/$FILE5.s
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
asm_dir/asm players/$FILE6.s
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
asm_dir/asm players/$FILE7.s
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
asm_dir/asm players/$FILE8.s
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
asm_dir/asm players/$FILE9.s
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
asm_dir/asm players/$FILE10.s
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
asm_dir/asm players/$FILE11.s
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
asm_dir/asm players/$FILE12.s
hexdump -vC players/$FILE12.cor > $USER$FILE12
rm players/$FILE12.cor
./asm players/$FILE12.s
hexdump -vC players/$FILE12.cor > $USER2$FILE12
diff -rsa $USER2$FILE12 $USER$FILE12 > $DIFF/diff_$FILE.t12xt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE12.txt
echo "User ↑"

echo "\n\n\033[32m$FILE13\n\033[37m"
rm players/$FILE13.cor
asm_dir/asm players/$FILE13.s
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
asm_dir/asm players/$FILE14.s
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
asm_dir/asm players/$FILE15.s
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
asm_dir/asm players/$FILE16.s
hexdump -vC players/$FILE16.cor > $USER$FILE
rm players/$FILE16.cor
./asm players/$FILE16.s
hexdump -vC players/$FILE16.cor > $USER2$FILE
diff -rsa $USER2$FILE16 $USER$FILE > $DIFF/diff_$FILE.txt
echo "ZaZ ↓"
cat $DIFF/diff_$FILE16.txt
echo "User ↑"
