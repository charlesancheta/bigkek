#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    //declare the valuables 
    int program_gussed_number;
    int user_hint;
    int counter = 1; //stores the number of times the program guessed the value 
    int min;
    int max;

    //ask the user for two values that defines the range for a number
    printf("Range: minimum ");
    scanf("%d", &min);

    printf("Range: maximum ");
    scanf("%d", &max);

    //program guesses the number until it gets it right by asking for hints 
    while (true) {
    program_gussed_number =  (min + max)/2;
    printf("Guessed number : %d \n", program_gussed_number);
    printf(" 1. TOO LARGE \n 2. TOO SMALL \n 3. FOUND \n"); //ask user to select one of the options
    scanf("%d", &user_hint);

        if (user_hint == 1 ) {
            max = program_gussed_number - 1;
            counter = counter + 1; 
        } else if (user_hint == 2) {
            min = program_gussed_number + 1;
            counter = counter + 1;
        } else {
            printf(" FOUNT IT \n No. of tries: %d", counter);
            break;
        }
    }
    return 0;   
    
}
