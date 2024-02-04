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

    // Initialize guessedWord with underscores
    for (int i = 0; i < strlen(answer); i++) {
        guessedWord[i] = '_';
    }
    guessedWord[strlen(answer)] = '\0';

    while (1) {
        printf("Guess the word: %s\n", guessedWord);

        char guess;
        printf("Enter a letter: ");
        scanf_s(" %c", &guess);

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
        }

        correctGuess = 0;
    }

    return 0;  // This line will never be reached in this infinite loop
}