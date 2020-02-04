/* DO NOT MODIFY THIS --------------------------------------------*/
.text

.global AssemblyProgram

AssemblyProgram:
lea      -40(%a7),%a7 /*Backing up data and address registers */
movem.l %d2-%d7/%a2-%a5,(%a7)
/*----------------------------------------------------------------*/

/******************************************************************/
/* General Information ********************************************/
/* File Name: Lab1a.s *********************************************/
/* Names of Students: Charles Ancheta and Mustafa Farow          **/
/* Date: February 4, 2020                                        **/
/* General Description:                                          **/
/*                                                               **/
/******************************************************************/

/*Write your program here******************************************/
move.l #0x43000000, %a2
move.l #0x43100000, %a3

Repeat:
move.l %a2, %d2
cmpi.l #0xd, %d2
beq Exit
cmp.l #0x30, %d2
blt Error
cmp.l #0x39, %d2
bgt Uppercase
sub.l #0x30, %d2
bra increment

Uppercase:
cmp.l #0x41, %d2
blt Error
cmp.l #0x46, %d2
bgt Lowercase
sub.l #0x31, %d2
bra increment

Lowercase:
cmp.l #0x61, %d2
blt Error
cmp.l #0x66, %d2
bgt Error
sub.l #0x61, %d2
bra increment

Error:
move.l 0xFFFFFFFF, %a2
bra increment

increment:
move.l %d2, %a3
add.l #4, %a2
add.l #4, %a3
bra Repeat

Exit:
/*End of program **************************************************/

/* DO NOT MODIFY THIS --------------------------------------------*/
movem.l (%a7),%d2-%d7/%a2-%a5 /*Restore data and address registers */
lea      40(%a7),%a7 
rts
/*----------------------------------------------------------------*/
