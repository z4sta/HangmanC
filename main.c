#include <stdio.h>
#include <string.h>
#include <ctype.h>

// TODO:
// tries counter
// prevent multiple guess outputs when typing in full word

// TODO (ADVC):
// draw hangman

int main() {
    char answer[] = "testbox";
    char guessedWord[10];
    int correctGuess = 0;
    int lifes = 10;

    // Initialize guessedWord with underscores
    for (int i = 0; i < strlen(answer); i++) {
        guessedWord[i] = '_';
    }
    guessedWord[strlen(answer)] = '\0';

    
    while (lifes > 0) {

        printf("lives left: %d\n", lifes);
        printf("Guess the word: %s\n", guessedWord);

        char guess;
        printf("Enter a letter: ");
        scanf_s(" %c", &guess);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        // Convert the guess to uppercase for case-insensitive comparison
        guess = toupper(guess);

        for (int i = 0; i < strlen(answer); i++) {

            if (toupper(answer[i]) == guess) {
                guessedWord[i] = answer[i];
                correctGuess = 1;
            }
        }

        if (strcmp(answer, guessedWord) == 0) {
            printf("Congratulations! You guessed the word: %s\n", guessedWord);
            return 1;
        }

        if (!correctGuess) {
            printf("Incorrect guess. Try again.\n");
            lifes--;
        }



        correctGuess = 0;
    }

    printf("\nYou lost.");

    return 0;  // This line will never be reached in this infinite loop
}