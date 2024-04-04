#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "winnings.h"

int main() {

    // Initialize financials to NULL
    Balance* userFinancials = NULL;
    char username[MAX_USERNAME_LENGTH];

    // Loop unitl a valid username is entered or the user exits

    const char* filename = "File.txt";
    bool usernameFound = false;
    while (!usernameFound) {
        printf("Enter your username (or 'exit' to quit): ");
        if (scanf("%s", username) != 1) {
            fprintf(stderr, "Invalid input\n");
            return EXIT_FAILURE;
        }

        if (strcmp(username, "exit") == 0) {
            fprintf(stderr, "Exiting program\n");
            return EXIT_FAILURE;
        }

        // Load user's financials from a file
        userFinancials = loadFinancialsFromFile(filename, username);
        if (userFinancials != NULL) {
            usernameFound = true;
        }
        else {
            fprintf(stderr, "Username not found. Please try again.\n");
        }
    }
    // Display initial balance and total earnings
    displayWinnings(userFinancials);

    // Ask if the user would like to add funds to balance
    char response;
    printf("Would you like to add funds to your balance? (y/n): ");
    scanf(" %c", &response);
    if (response != 'y' && response != 'Y') {
        printf("Returning to the main menu.\n");
        freeFinancials(userFinancials);
        return EXIT_SUCCESS;
    }

    // Prompt user to add funds to balance
    double addToBalance;
    bool addMore = true;
    while (addMore) {
        bool validInput = false;
        while (!validInput) {
            printf("Enter amount to add to account: ");
            if (scanf("%lf", &addToBalance) != 1) {
                fprintf(stderr, "Invalid input\n");
                // Clear input buffer
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
            else {
                validInput = true;
            }
        }

        // Update balance
        updateBalance(userFinancials, addToBalance);

        // Display updated balance and total earnings
        displayWinnings(userFinancials);

        // Ask if the user wants to add more
        printf("Would you like to add more to your balance? (y/n): ");
        scanf(" %c", &response);
        if (response != 'y' && response != 'Y') {
            addMore = false;
        }
    }

    updateBalance(userFinancials, addToBalance);

    // Display updated balance and total earnings
    displayWinnings(userFinancials);

    saveFinancialsToFile(filename, userFinancials);

    // Free the allocated memory for financials
    freeFinancials(userFinancials);



	return EXIT_SUCCESS;
}