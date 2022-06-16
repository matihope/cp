// A game in which you guess a random number between 1 and 100
// by entering a number and pressing enter.
// The program will tell you if your guess is too high or too low.
// If you guess the number, the program will tell you how many
// guesses it took.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, guesses = 0;
    srand(time(NULL));
    number = rand() % 100 + 1;
    printf("Guess a number between 1 and 100: ");
    scanf("%d", &guess);
    while (guess != number) {
        if (guess > number) {
            printf("Too high.\n");
        } else {
            printf("Too low.\n");
        }
        guesses++;
        printf("Guess again: ");
        scanf("%d", &guess);
    }
    printf("You guessed the number in %d guesses.\n", guesses);
    return 0;
}
