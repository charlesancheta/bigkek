/* DO NOT MODIFY THIS --------------------------------------------*/
.text
.global WelcomePrompt
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
/* File Name: Lab4a.s *********************************************/
/* Names of Students: Charles Ancheta and Mustafa Farow ***********/
/* Date: April 5, 2020 ********************************************/
/* General Description: Get a valid keystroke from the user *******/
/******************************************************************/
/******************************************************************/
WelcomePrompt:
/*Write your program here******************************************/
lea      -40(%a7),%a7 
movem.l %d2-%d7/%a2-%a5,(%a7) /* back up registers */

Welcome: 
pea welcomeStr /* printing welcome string */
jsr iprintf
addq.l #4, %a7 /* clean stack */
jsr cr

PromptEntry:
pea entry /* printing prompt to user */
jsr iprintf
addq.l #4, %a7
jsr cr

GetInput:
jsr getchr /* get input from keyboard */
move.l %d0, %d2 /* move input to a valid register */
cmp.l #0x30, %d2 /* compare input to ASCII '0' */
blt InvalidInput /* not a letter nor a number */
cmp.l #0x39, %d2 /* compare input to ASCII '9' */
ble ValidInput /* input is a number, skip other checks */
cmp.l #0x41, %d2 /* compare input to ASCII 'A' */
blt InvalidInput /* not a letter nor a number */
cmp.l #0x5A, %d2 /* compare input to ASCII 'Z' */
bgt InvalidInput /* not an uppercase letter */

ValidInput:
move.l %d2, 44(%a7) /* move the valid keystroke to the stack */

movem.l (%a7),%d2-%d7/%a2-%a5 /* restore registers */
lea      40(%a7),%a7
rts 
/*End of Subroutine **************************************************/ 
InvalidInput:
pea invalid /* print invalid input message */
jsr iprintf
addq.l #4, %a7 /* clean stack */
jsr cr
bra PromptEntry /* get input from user again */


.data
/*All Strings placed here **************************************************/
welcomeStr: "Welcome to Charles and Mustafa's LED Display"
entry: "Please enter an uppercase letter or number from the keyboard"
invalid: "Invalid entry, please enter a proper keystroke from the keyboard"
/*End of Strings **************************************************/
/******************************************************/
