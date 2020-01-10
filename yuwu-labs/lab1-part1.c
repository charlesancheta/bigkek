#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int GeneratedNumber;
	int counter;
	int guessedNumber;
	
	srand(time(0));
	GeneratedNumber = rand()%(100 + 1 - 0);
	
	printf("Please guess a number:");
	scanf("%d",guessedNumber);
	if(guessedNumber!=GeneratedNumber){
		if(guessedNumber>GeneratedNumber){
			printf("TOO LARGE");
			scanf("%d",guessedNumber);
			counter = counter + 1;
		}
		else if(guessedNumber<GeneratedNumber){
			printf("TOO SMALL");
			scanf("%d",guessedNumber);
			counter = counter + 1;
		}
		else{
			printf("Please try again");
			scanf("%d",guessedNumber);
		}
	}
	else if(guessedNumber == GeneratedNumber){
		printf("FOUND\n");
		printf("No. of tries: %d",counter);
	}	
	return 0;
}