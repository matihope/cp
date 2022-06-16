# A game in which you guess a number from 1 to 100
import random

# Main
def main():
    print('Welcome to the game "Guess the number"')
    print('I\'m thinking of a number between 1 and 100.')
    print('Try to guess it in as few attempts as possible.')
    print()

    number = random.randint(1, 100)
    guess = int(input('Take a guess: '))
    tries = 1

    while guess != number:
        if guess > number:
            print('Lower...')
        else:
            print('Higher...')

        guess = int(input('Take a guess: '))
        tries += 1

    print('You guessed it! The number was', number)
    print('And it only took you', tries, 'tries!')


if __name__ == '__main__':
    main()
