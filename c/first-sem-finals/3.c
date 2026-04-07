#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5

int main() {
    srand(time(NULL)); // seed random number generator

    int points;
    printf("How many points you want? ");
    scanf("%d", &points);

    char playAgain = 'Y';

    while ((playAgain == 'Y' || playAgain == 'y') && points > 0) {
        printf("\nGuess Menu:\n");
        printf("O Odd\nE Even\nL Low\nM Medium\nH High\nF Left\nC Center\nR Right\nN Number\n");

        int numGuesses;
        printf("\nHow many guesses would you like? (1-5) ");
        scanf("%d", &numGuesses);
        if (numGuesses < 1) numGuesses = 1;
        if (numGuesses > MAX_GUESSES) numGuesses = MAX_GUESSES;

        char guessType[MAX_GUESSES];
        int chosenNumber[MAX_GUESSES] = {0};
        int amountRisked[MAX_GUESSES] = {0};
        int pointsWon[MAX_GUESSES] = {0};

        int totalRisked = 0;

        // get guesses
        for (int i = 0; i < numGuesses; i++) {
            printf("\nGuess %d\nEnter your choice (from Guess Menu): ", i + 1);
            scanf(" %c", &guessType[i]);

            if (guessType[i] == 'N' || guessType[i] == 'n') {
                printf("Enter your number (1-36): ");
                scanf("%d", &chosenNumber[i]);
            }

            while (1) {
                printf("How many points gamble: ");
                scanf("%d", &amountRisked[i]);
                if (amountRisked[i] < 0 || amountRisked[i] > points - totalRisked) {
                    printf("Hey you can't do that. You have %d points left.\n", 
                        points - totalRisked);
                } else {
                    totalRisked += amountRisked[i];
                    break;
                }
            }
        }

        // generate random number for current turn
        int number = rand() % 36 + 1;
        printf("\nMy number is: %d\n", number);

        int previousPoints = points;

        // evaluate each guess
        for (int i = 0; i < numGuesses; i++) {
            int win = 0;

            switch (guessType[i]) {
                case 'O': case 'o': // odd
                    if (number % 2 != 0) win = amountRisked[i];
                    else win = -amountRisked[i];
                    break;
                case 'E': case 'e': // even
                    if (number % 2 == 0) win = amountRisked[i];
                    else win = -amountRisked[i];
                    break;
                case 'L': case 'l': // low 1-12
                    if (number >= 1 && number <= 12) win = 2 * amountRisked[i];
                    else win = -amountRisked[i];
                    break;
                case 'M': case 'm': // medium 13-24
                    if (number >= 13 && number <= 24) win = 2 * amountRisked[i];
                    else win = -amountRisked[i];
                    break;
                case 'H': case 'h': // high 25-36
                    if (number >= 25 && number <= 36) win = 2 * amountRisked[i];
                    else win = -amountRisked[i];
                    break;
                case 'F': case 'f': // left column (numbers 1, 4, 7, ...)
                    if ((number - 1) % 3 == 0) win = 2 * amountRisked[i];
                    else win = -amountRisked[i];
                    break;
                case 'C': case 'c': // center column (numbers 2, 5, 8, ...)
                    if ((number - 2) % 3 == 0) win = 2 * amountRisked[i];
                    else win = -amountRisked[i];
                    break;
                case 'R': case 'r': // right column (numbers 3, 6, 9, ...)
                    if ((number - 3) % 3 == 0) win = 2 * amountRisked[i];
                    else win = -amountRisked[i];
                    break;
                case 'N': case 'n': // specific number
                    if (chosenNumber[i] == number) win = 36 * amountRisked[i];
                    else win = -amountRisked[i];
                    break;
                default:
                    win = -amountRisked[i];
                    break;
            }

            pointsWon[i] = win;
            points += win;
        }

        // print results
        printf("\nPrevious Points: %d\n", previousPoints);
        printf("Guess Type  Number  Amount Risked  Won/Loss\n");
        for (int i = 0; i < numGuesses; i++) {
            printf("%c          ", guessType[i]);
            if (guessType[i] == 'N' || guessType[i] == 'n')
                printf("%2d       ", chosenNumber[i]);
            else
                printf(" -        ");
            printf("%4d          %+4d\n", amountRisked[i], pointsWon[i]);
        }

        printf("Your new balance is: %d points\n", points);

        if (points <= 0) {
            printf("You are out of points lol, game over hehehehe\n");
            break;
        }

        printf("Play again (Y or N)? ");
        scanf(" %c", &playAgain);
    }

    printf("Thanks for playing! Praise God!\n");
    return 0;
}