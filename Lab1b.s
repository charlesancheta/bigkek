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

move.l #0x43000000, %a2
move.l #0x43200000, %a3

Repeat:
move.l (%a2), %d2
cmpi.l #0xD, %d2
beq Exit
cmp.l #0x41, %d2
blt Error
cmp.l #0x46, %d2
blt Uppercase
cmp.l #0x61, %d2
blt Error
cmp.l #0x66, %d2
bgt Error
sub.l #0x20, %d2
bra increment

Uppercase:
add.l #0x20, %d2
bra increment

Error:
move.l #0xFFFFFFFF, %d2
bra increment

increment:
move.l %d2, (%a3)
addi.l #4, %a2
addi.l #4, %a3
bra Repeat

Exit:
/*End of program **************************************************/

/* DO NOT MODIFY THIS --------------------------------------------*/
movem.l (%a7),%d2-%d7/%a2-%a5 /*Restore data and address registers */
lea      40(%a7),%a7 
rts
/*----------------------------------------------------------------*/
