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
/* Names of Students: Wenxin Kang and William Chorkawy **/
/* Date: Feb 6th 2020                                       **/
/* General Description:Convert ascii number to hexa/dec equivalent **/
/*                                                               **/
/******************************************************************/

/*Write your program here******************************************/


move.l #0x43000000, %a2
move.l #0x43100000, %a3
move.l #80, %d7


number:
move.l (%a2), %d2
cmpi.l #0x0D, %d2
beq done
cmpi.l #0x30, %d2
blt error
cmpi.l #0x39, %d2
bgt uppercase
sub.l #0x30, %d2
bra counter


uppercase:
cmpi.l #0x41, %d2
blt error
cmpi.l #0x46, %d2
bgt lowercase
sub.l #0x37, %d2
bra counter


lowercase:
cmpi.l #0x61, %d2
blt error
cmpi.l #0x66, %d2
bgt error
sub.l #0x57, %d2
bra counter



error:
sub.l #1, %d7
move.l #0xFFFFFFFF, %d2
add.l #4, %a2
add.l #4, %a3
bra counter


counter:
sub.l #1, %d7
add.l #4, %a2
add.l #4, %a3
bra number




done:

/*End of program **************************************************/

/* DO NOT MODIFY THIS --------------------------------------------*/
movem.l (%a7),%d2-%d7/%a2-%a5 /*Restore data and address registers */
lea      40(%a7),%a7
rts
/*----------------------------------------------------------------*/

