/* DO NOT MODIFY THIS --------------------------------------------*/
.text
.global LedSub
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
/* File Name: Lab4c.s *********************************************/
/* Names of Students: Charles Ancheta and Mustafa Farow ***********/
/* Date: April 5, 2020 ********************************************/
/* General Description: Display the LED pattern of the character **/
/******************************************************************/
/******************************************************************/
LedSub:
/*Write your program here******************************************/
lea      -40(%a7),%a7 
movem.l %d2-%d7/%a2-%a5,(%a7) /* back up registers */

move.l $$(%a7), %d2 /* get the pattern address */







movem.l (%a7),%d2-%d7/%a2-%a5 /* restore registers */
lea      40(%a7),%a7
rts 
/*End of Subroutine **************************************************/ 
.data
/*All Strings placed here ********************************************/
/*End of Strings *****************************************************/
/*********************************************************************/
