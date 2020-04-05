/* DO NOT MODIFY THIS --------------------------------------------*/
.text
.global convert
.extern cr
.extern iprintf
.extern getchr
.extern TurnOnLed
.extern TurnOffLed
.extern Row
.extern Column
.extern Delay
/*----------------------------------------------------------------*/

/******************************************************************/
/* General Information ********************************************/
/* File Name: Lab4b.s *********************************************/
/* Names of Students: Charles Ancheta and Mustafa Farow ***********/
/* Date: April 5, 2020 ********************************************/
/* General Description: Gets the pattern address of a specific ****/
/********************** ASCII character from memory ***************/
/******************************************************************/
convert:
/*Write your program here******************************************/
lea      -40(%a7),%a7 
movem.l %d2-%d7/%a2-%a5,(%a7) /* back up registers */

move.l 44(%a7), -(%a7) /* push ASCII keystroke on top of the stack */
jsr convert1
move.l (%a7)+, %d2 /* pop the pattern address off the stack */
move.l %d2, 44(%a7) /* move the pattern address to the stack */

movem.l (%a7),%d2-%d7/%a2-%a5 /* restore registers */
lea      40(%a7),%a7
rts 
/*End of Subroutine **************************************************/ 
.data
/*All Strings placed here ********************************************/
/*End of Strings *****************************************************/
