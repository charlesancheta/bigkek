/* DO NOT MODIFY THIS --------------------------------------------*/
.text

.global AssemblyProgram

AssemblyProgram:
lea      -40(%a7),%a7 /*Backing up data and address registers */
movem.l %d2-%d7/%a2-%a5,(%a7)
/*----------------------------------------------------------------*/

/******************************************************************/
/* General Information ********************************************/
/* File Name: Lab1b.s *********************************************/
/* Names of Students: Charles Ancheta and Mustafa Farow          **/
/* Date: February 4, 2020                                        **/
/* General Description: Converts uppercase to lowercase char     **/
/*                                                               **/
/******************************************************************/

/*Write your program here******************************************/

move.l #0x43000000, %a2; initialize storage address
move.l #0x43200000, %a3; initialize converted storage address

Repeat:
move.l (%a2), %d2; copy data from %a2 to register %d2
cmpi.l #0xd, %d2; compares %d2 to return key
beq Exit; exits the program if %d2 is equal to return key
cmp.l #0x41, %d2; compares %d2 to ASCII 'A'
blt Error; branches to Error if %d2 is not an alphabetical character
cmp.l #0x5b, %d2; compares %d2 to ASCII 'Z'
blt Uppercase; branches to Uppercase if %d2 is an uppercase character
cmp.l #0x61, %d2; compares %d2 to ASCII 'a'
blt Error; branches to Error if %d2 is not an alphabetical character
cmp.l #0x7b, %d2; compares %d2 to ASCII 'z'
bgt Error; branches to Error if %d2 is not an alphabetical character
sub.l #0x20, %d2; subtracts 0x20 to convert lower to upper case
bra increment; always branch to increment

Uppercase:
add.l #0x20, %d2; adds 0x20 to convert upper to lower case
bra increment; always branch to increment

Error:
move.l #0xFFFFFFFF, %d2; copies error code to %d2
bra increment; always branch to increment

increment:
move.l %d2, (%a3); copies %d2 to address %a3 (result address)
add.l #4, %a2; increments storage address by 4 
add.l #4, %a3; increments results storage address by 4
bra Repeat; repeats the loop

Exit:
/*End of program **************************************************/

/* DO NOT MODIFY THIS --------------------------------------------*/
movem.l (%a7),%d2-%d7/%a2-%a5 /*Restore data and address registers */
lea      40(%a7),%a7 
rts
/*----------------------------------------------------------------*/
