#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int min, max, relative_guess;
    int counter = 0;
    int guess = 0;

    printf("Range: Minimum ");
    scanf("%d", &min);

    printf("Range: Maximum ");
    scanf("%d", &max);

    while (guess == 0){
        counter++;
        int program_guessed_number = (min + max)/2;
        printf("Guessed Number: %d", program_guessed_number);

        printf("\n1. TOO LARGE \n2. TOO SMALL \n3. FOUND\n ");
        scanf("%d", &relative_guess);

        if (relative_guess == 1) {
            max = program_guessed_number -1;
        }
        else if (relative_guess == 2) {
            min = program_guessed_number +1;
        }
        else if (relative_guess == 3) {
            printf("FOUND IT\nNo. of tries: %d",counter);
            guess = 1;
        }
        else{
            printf("Please select one of the options\n");
            counter = counter - 1; //so the user giving an incorrect input doesn't count as an extra guess
        }
    }
return 0;
}