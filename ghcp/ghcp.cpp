#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){
    // A game in which you guess a number from 1 to 100 and count the tries
    // until you guess the number.
    //
    // The program generates a random number and asks you to guess it.
    // If you guess it, the program prints the number of tries.
    // If you don't guess it, the program prints the number of tries
    // and the number of tries until you guess the number.
    //
    // The program ends when you guess the number.
    //

    // Generate a random number
    srand(time(NULL));
    int number = rand() % 100 + 1;

    // Ask the user to guess the number
    int guess;
    std::cout << "Guess the number: ";
    std::cin >> guess;

    // Count the number of tries
    int tries = 1;

    // While the user doesn't guess the number
    while (guess != number) {
        // If the user guessed too high
        if (guess > number) {
            std::cout << "Too high. Try again: ";
        }
        // If the user guessed too low
        else {
            std::cout << "Too low. Try again: ";
        }
        // Ask the user to guess the number again
        std::cin >> guess;
        // Count the number of tries
        tries++;
    }

    // Print the number of tries
    std::cout << "You guessed the number in " << tries << " tries." << std::endl;

    return 0;
}
