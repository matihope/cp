import java.util.Random;
import java.util.Scanner;

public class ghcp {
    public static void main(String[] args) {
        // A game in which you guess a random number between 1 and 100
        // by entering a number and pressing enter.

        // The program will tell you if your guess is too high or too low.
        // If you guess the number, the program will tell you how many
        // guesses it took.

        int number = new Random().nextInt(100) + 1;
        int guess = 0;
        int guessCount = 0;
        boolean correct = false;

        Scanner scanner = new Scanner(System.in);

        while (!correct) {
            System.out.print("Enter a number between 1 and 100: ");
            guess = scanner.nextInt();
            guessCount++;

            if (guess == number) {
                correct = true;
            } else if (guess < number) {
                System.out.println("Your guess is too low.");
            } else {
                System.out.println("Your guess is too high.");
            }
        }

        System.out.println("You guessed the number in " + guessCount + " guesses.");

        scanner.close();
    }
}
