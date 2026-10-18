#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int target; 
    int guess;  
    int count = 0; 

    srand(time(0)); 
    target = rand() % 100 + 1; 

    printf("=================================\n");
    printf("   Welcome to the Number Game!   \n");
    printf("   I have a number between 1-100 \n");
    printf("=================================\n");

    while (1) {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        count++; 

        if (guess > target) {
            printf("Too high!\n");
        } 
        else if (guess < target) {
            printf("Too low!\n");
        } 
        else {
            printf("Bingo! The answer is %d\n", target);
            printf("Total tries: %d\n", count);
            break; 
        }
    }

    return 0;
}