GREEN="\033[32m";
RED="\033[31m";
DEFAULT="\033[37m";
CYAN="\x1b[36m";

USER="../US/";
USER2="../ZAZ/"
DIFF="../DIFF/"
P="./corewar -d 200";
DIR="../Players/"

C="./corewar -dump 1000 -n -1";
C2="./corewarzaz -d 1000";

FILE="bee_gees.cor";
FILE2="bigzork.cor";
FILE3="fork.cor";
FILE5="turtle.cor";
FILE6="zork.cor";
FILE4="helltrain.cor";
FILE7="id_player_dyn.cor";
FILE8="jmp_after_load.cor";
FILE9="jmp_after_add.cor";
FILE10="move.cor";
FILE11="st.cor";
FILE12="test_add_instruction.cor";
FILE13="test_aff_instruction.cor";
FILE14="test_and_instruction.cor";
FILE15="test_comment_line.cor";
FILE16="test_comments_eol.cor";
FILE17="test_fork_instruction.cor";
FILE18="test_ld_instruction.cor";
FILE19="test_ldi_instruction.cor";
FILE20="test_lfork_instruction.cor";
FILE21="test_live_instruction.cor";
FILE22="test_lld_instruction.cor";
FILE23="test_lldi_instruction.cor";
FILE24="test_max_direct.cor";
FILE25="test_max_indirect.cor";
FILE26="test_max_register.cor";
FILE27="test_min_direct.cor";
FILE28="test_min_indirect.cor";
FILE29="test_min_register.cor";
FILE30="test_or_instruction.cor";
FILE31="test_st_instruction.cor";
FILE32="test_sti_instruction.cor";
FILE33="test_sub_instruction.cor";
FILE34="test_xor_instruction.cor";
FILE35="test_zjump_instruction.cor";

echo "\n\n\033[32m$FILE\n\033[37m"
$C $DIR$FILE > $USER$FILE; $C2 $DIR$FILE > $USER2$FILE;
diff -rsa $USER$FILE $USER2$FILE > $DIFF$FILE
cat $DIFF$FILE
#echo "\x1b[36mOutput: cat $USER$FILE\n"

echo "\n\n\033[32m$FILE1\n\033[37m"
$C $DIR$FILE1 > $USER$FILE1 ;$C2 $DIR$FILE1 > $USER2$FILE1 ;
diff -rsa $USER$FILE1 $USER2$FILE1 > $DIFF$FILE1
cat $DIFF$FILE1
#echo "\x1b[36mOutput: cat $USER$FILE1\n"

echo "\n\n\033[32m$FILE2\n\033[37m"
$C $DIR$FILE2 > $USER$FILE2 ;$C2 $DIR$FILE2 > $USER2$FILE2 ;
diff -rsa $USER$FILE2 $USER2$FILE2 > $DIFF$FILE2
cat $DIFF$FILE2
#echo "\x1b[36mOutput: cat $USER$FILE2\n"

echo "\n\n\033[32m$FILE3\n\033[37m"
$C $DIR$FILE3 > $USER$FILE3 ;$C2 $DIR$FILE3 > $USER2$FILE3 ;
diff -rsa $USER$FILE3 $USER2$FILE3 > $DIFF$FILE3
cat $DIFF$FILE3
#echo "\x1b[36mOutput: cat $USER$FILE3\n"

echo "\n\n\033[32m$FILE4\n\033[37m"
$C $DIR$FILE4 > $USER$FILE4 ;$C2 $DIR$FILE4 > $USER2$FILE4 ;
diff -rsa $USER$FILE4 $USER2$FILE4 > $DIFF$FILE4
cat $DIFF$FILE4

echo "\n\n\033[32m$FILE5\n\033[37m"
$C $DIR$FILE5 > $USER$FILE5 ;$C2 $DIR$FILE5 > $USER2$FILE5 ;
diff -rsa $USER$FILE5 $USER2$FILE5 > $DIFF$FILE5
cat $DIFF$FILE5

echo "\n\n\033[32m$FILE6\n\033[37m"
$C $DIR$FILE6 > $USER$FILE6 ;$C2 $DIR$FILE6 > $USER2$FILE6 ;
diff -rsa $USER$FILE6 $USER2$FILE6 > $DIFF$FILE6
cat $DIFF$FILE6

echo "\n\n\033[32m$FILE7\n\033[37m"
$C $DIR$FILE7 > $USER$FILE7 ;$C2 $DIR$FILE7 > $USER2$FILE7 ;
diff -rsa $USER$FILE7 $USER2$FILE7 > $DIFF$FILE7
cat $DIFF$FILE7
#echo "\x1b[36mOutput: cat $USER$FILE7\n"

echo "\n\n\033[32m$FILE8\n\033[37m"
$C $DIR$FILE8 > $USER$FILE8 ;$C2 $DIR$FILE8 > $USER2$FILE8 ;
diff -rsa $USER$FILE8 $USER2$FILE8 > $DIFF$FILE8
cat $DIFF$FILE8
#echo "\x1b[36mOutput: cat $USER$FILE8\n"

echo "\n\n\033[32m$FILE24\n\033[37m"
$C $DIR$FILE24 > $USER$FILE24 ;$C2 $DIR$FILE24 > $USER2$FILE24 ;
diff -rsa $USER$FILE24 $USER2$FILE24 > $DIFF$FILE24
cat $DIFF$FILE24

echo "\n\n\033[32m$FILE9\n\033[37m"
$C $DIR$FILE9 > $USER$FILE9 ;$C2 $DIR$FILE9 > $USER2$FILE9 ;
diff -rsa $USER$FILE9 $USER2$FILE9 > $DIFF$FILE9
cat $DIFF$FILE9

echo "\n\n\033[32m$FILE10\n\033[37m"
$C $DIR$FILE10 > $USER$FILE10 ;$C2 $DIR$FILE10 > $USER2$FILE10 ;
diff -rsa $USER$FILE10 $USER2$FILE10 > $DIFF$FILE10
cat $DIFF$FILE10

echo "\n\n\033[32m$FILE11\n\033[37m"
$C $DIR$FILE11 > $USER$FILE11 ;$C2 $DIR$FILE11 > $USER2$FILE11 ;
diff -rsa $USER$FILE11 $USER2$FILE11 > $DIFF$FILE11
cat $DIFF$FILE11

echo "\n\n\033[32m$FILE12\n\033[37m"
$C $DIR$FILE12 > $USER$FILE12 ;$C2 $DIR$FILE12 > $USER2$FILE12 ;
diff -rsa $USER$FILE12 $USER2$FILE12 > $DIFF$FILE12
cat $DIFF$FILE12

echo "\n\n\033[32m$FILE13\n\033[37m"
$C $DIR$FILE13 > $USER$FILE13 ;$C2 $DIR$FILE13 > $USER2$FILE13 ;
diff -rsa $USER$FILE13 $USER2$FILE13 > $DIFF$FILE13
cat $DIFF$FILE13

echo "\n\n\033[32m$FILE14\n\033[37m"
$C $DIR$FILE14 > $USER$FILE14 ;$C2 $DIR$FILE14 > $USER2$FILE14 ;
diff -rsa $USER$FILE14 $USER2$FILE14 > $DIFF$FILE14
cat $DIFF$FILE14

echo "\n\n\033[32m$FILE15\n\033[37m"
$C $DIR$FILE15 > $USER$FILE15 ;$C2 $DIR$FILE15 > $USER2$FILE15 ;
diff -rsa $USER$FILE15 $USER2$FILE15 > $DIFF$FILE15
cat $DIFF$FILE15

echo "\n\n\033[32m$FILE16\n\033[37m"
$C $DIR$FILE16 > $USER$FILE16 ;$C2 $DIR$FILE16 > $USER2$FILE16 ;
diff -rsa $USER$FILE16 $USER2$FILE16 > $DIFF$FILE16
cat $DIFF$FILE16

echo "\n\n\033[32m$FILE17\n\033[37m"
$C $DIR$FILE17 > $USER$FILE17 ;$C2 $DIR$FILE17 > $USER2$FILE17 ;
diff -rsa $USER$FILE17 $USER2$FILE17 > $DIFF$FILE17
cat $DIFF$FILE17

echo "\n\n\033[32m$FILE18\n\033[37m"
$C $DIR$FILE18 > $USER$FILE18 ;$C2 $DIR$FILE18 > $USER2$FILE18 ;
diff -rsa $USER$FILE18 $USER2$FILE18 > $DIFF$FILE18
cat $DIFF$FILE18

echo "\n\n\033[32m$FILE19\n\033[37m"
$C $DIR$FILE19 > $USER$FILE19 ;$C2 $DIR$FILE19 > $USER2$FILE19 ;
diff -rsa $USER$FILE19 $USER2$FILE19 > $DIFF$FILE19
cat $DIFF$FILE19

echo "\n\n\033[32m$FILE20\n\033[37m"
$C $DIR$FILE20 > $USER$FILE20 ;$C2 $DIR$FILE20 > $USER2$FILE20 ;
diff -rsa $USER$FILE20 $USER2$FILE20 > $DIFF$FILE20
cat $DIFF$FILE20
#echo "\x1b[36mOutput: cat $USER$FILE20\n"

echo "\n\n\033[32m$FILE21\n\033[37m"
$C $DIR$FILE21 > $USER$FILE21 ;$C2 $DIR$FILE21 > $USER2$FILE21 ;
diff -rsa $USER$FILE21 $USER2$FILE21 > $DIFF$FILE21
cat $DIFF$FILE21
#echo "\x1b[36mOutput: cat $USER$FILE20\n"

echo "\n\n\033[32m$FILE22\n\033[37m"
$C $DIR$FILE22 > $USER$FILE22 ;$C2 $DIR$FILE22 > $USER2$FILE22 ;
diff -rsa $USER$FILE22 $USER2$FILE22 > $DIFF$FILE22
cat $DIFF$FILE22
#echo "\x1b[36mOutput: cat $USER$FILE22\n"

echo "\n\n\033[32m$FILE23\n\033[37m"
$C $DIR$FILE23 > $USER$FILE23 ;$C2 $DIR$FILE23 > $USER2$FILE23 ;
diff -rsa $USER$FILE23 $USER2$FILE23 > $DIFF$FILE23
cat $DIFF$FILE23
#echo "\x1b[36mOutput: cat $USER$FILE23\n"

echo "\n\n\033[32m$FILE24\n\033[37m"
$C $DIR$FILE24 > $USER$FILE24 ;$C2 $DIR$FILE24 > $USER2$FILE24 ;
diff -rsa $USER$FILE24 $USER2$FILE24 > $DIFF$FILE24
cat $DIFF$FILE24

echo "\n\n\033[32m$FILE25\n\033[37m"
$C $DIR$FILE25 > $USER$FILE25 ;$C2 $DIR$FILE25 > $USER2$FILE25 ;
diff -rsa $USER$FILE25 $USER2$FILE25 > $DIFF$FILE25
cat $DIFF$FILE25

echo "\n\n\033[32m$FILE26\n\033[37m"
$C $DIR$FILE26 > $USER$FILE26 ;$C2 $DIR$FILE26 > $USER2$FILE26 ;
diff -rsa $USER$FILE26 $USER2$FILE26 > $DIFF$FILE26
cat $DIFF$FILE26

echo "\n\n\033[32m$FILE27\n\033[37m"
$C $DIR$FILE27 > $USER$FILE27 ;$C2 $DIR$FILE27 > $USER2$FILE27 ;
diff -rsa $USER$FILE27 $USER2$FILE27 > $DIFF$FILE27
cat $DIFF$FILE27

echo "\n\n\033[32m$FILE28\n\033[37m"
$C $DIR$FILE28 > $USER$FILE28 ;$C2 $DIR$FILE28 > $USER2$FILE28 ;
diff -rsa $USER$FILE28 $USER2$FILE28 > $DIFF$FILE28
cat $DIFF$FILE28

echo "\n\n\033[32m$FILE29\n\033[37m"
$C $DIR$FILE29 > $USER$FILE29 ;$C2 $DIR$FILE29 > $USER2$FILE29 ;
diff -rsa $USER$FILE29 $USER2$FILE29 > $DIFF$FILE29
cat $DIFF$FILE29

echo "\n\n\033[32m$FILE30\n\033[37m"
$C $DIR$FILE30 > $USER$FILE30 ;$C2 $DIR$FILE30 > $USER2$FILE30 ;
diff -rsa $USER$FILE30 $USER2$FILE30 > $DIFF$FILE30
cat $DIFF$FILE30

echo "\n\n\033[32m$FILE31\n\033[37m"
$C $DIR$FILE31 > $USER$FILE31 ;$C2 $DIR$FILE31 > $USER2$FILE31 ;
diff -rsa $USER$FILE31 $USER2$FILE31 > $DIFF$FILE31
cat $DIFF$FILE31

echo "\n\n\033[32m$FILE32\n\033[37m"
$C $DIR$FILE32 > $USER$FILE32 ;$C2 $DIR$FILE32 > $USER2$FILE32 ;
diff -rsa $USER$FILE32 $USER2$FILE32 > $DIFF$FILE32
cat $DIFF$FILE32

echo "\n\n\033[32m$FILE33\n\033[37m"
$C $DIR$FILE33 > $USER$FILE33 ;$C2 $DIR$FILE33 > $USER2$FILE33 ;
diff -rsa $USER$FILE33 $USER2$FILE33 > $DIFF$FILE33
cat $DIFF$FILE33

echo "\n\n\033[32m$FILE34\n\033[37m"
$C $DIR$FILE34 > $USER$FILE34 ;$C2 $DIR$FILE34 > $USER2$FILE34 ;
diff -rsa $USER$FILE34 $USER2$FILE34 > $DIFF$FILE34
cat $DIFF$FILE34

echo "\n\n\033[32m$FILE35\n\033[37m"
$C $DIR$FILE35 > $USER$FILE35 ;$C2 $DIR$FILE35 > $USER2$FILE35 ;
diff -rsa $USER$FILE35 $USER2$FILE35 > $DIFF$FILE35
cat $DIFF$FILE35

echo "\n\n\033[32m$FILE36\n\033[37m"
$C $DIR$FILE36 > $USER$FILE36 ;$C2 $DIR$FILE36 > $USER2$FILE36 ;
diff -rsa $USER$FILE36 $USER2$FILE36 > $DIFF$FILE36
cat $DIFF$FILE36



echo "\n\n\033[32mOutput Difference:\033[37m"
diff -r $DIR$USER2 $USER > output_difference.txt
echo "\x1b[36mOutput: cat output_difference.txt\n"
