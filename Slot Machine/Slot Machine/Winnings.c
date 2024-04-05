#define _CRT_SECURE_NO_WARNINGS
#include "winnings.h"
#include <stdio.h>
#include <stdlib.h>

void displayWinnings(Account* financials) {
    printf("Total Earnings: $%.2f\n", financials->winnings);
    printf("Current Account: $%.2f\n", financials->balance);
}

void updateAccount(Account* financials, double FundsToAdd) {
    financials->balance += FundsToAdd;
}

void loadFinancialsFromFile(const char* filename, Account* financials) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return; // This function should not return a value since it's return type is void
    }

    char buffer[MAXUSERNAMELENGTH];
    double balance, winnings;
    while (fscanf(file, "%s %lf %lf", buffer, &balance, &winnings) == 3) {
        if (strcmp(financials->username, buffer) == 0) {
            financials->winnings = winnings;
            financials->balance = balance;
            break; // Found the record, no need to continue reading the file
        }
    }
    fclose(file);
}

void saveFinancialsToFile(const char* filename, Account* financials) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    fprintf(file, "%.2f\n%.2f", financials->balance, financials->winnings);
    fclose(file);
}

void startWinningsModule(Account* userFinancials) {

    const char* filename = "File.txt";

    // Load user's financials from a file
    loadFinancialsFromFile(userFinancials, filename);

    // Display balance and total earnings
    displayWinnings(userFinancials);

    // Ask if the user would like to add funds to balance
    char response;
    printf("Would you like to add funds to your balance? (y/n): ");
    scanf(" %c", &response);
    if (response != 'y' && response != 'Y') {
        printf("Returning to the main menu.\n");
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
        updateAccount(userFinancials, addToBalance);

        // Display updated balance and total earnings
        displayWinnings(userFinancials);

        // Ask if the user wants to add more
        printf("Would you like to add more to your balance? (y/n): ");
        scanf(" %c", &response);
        if (response != 'y' && response != 'Y') {
            addMore = false;
        }
    }

    updateAccount(userFinancials, addToBalance);

    // Display updated balance and total earnings
    displayWinnings(userFinancials);

    saveFinancialsToFile(filename, userFinancials);

    return EXIT_SUCCESS;
}