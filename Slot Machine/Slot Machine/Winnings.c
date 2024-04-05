#define _CRT_SECURE_NO_WARNINGS
#include "winnings.h"
#include <stdio.h>
#include <stdlib.h>

Account* initializeFinancials(double initialAccount) {
    Account* financials = (Account*)malloc(sizeof(Account));
    if (financials == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    financials->balance = initialAccount;
    financials->winnings = 0.0;
    return financials;
}

void displayWinnings(Account* financials) {
    printf("Total Earnings: $%.2f\n", financials->winnings);
    printf("Current Account: $%.2f\n", financials->balance);
}

void updateAccount(Account* financials, double FundsToAdd) {
    financials->balance += FundsToAdd;
}

void freeFinancials(Account* financials) {
    free(financials);
}

Account* loadFinancialsFromFile(const char* filename, const char* username) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    char buffer[MAXUSERNAMELENGTH];
    double initialAccount, winnings;
    while (fscanf(file, "%s", buffer) == 1) {
        if (strcmp(buffer, username) == 0) {
            if (fscanf(file, "%lf %lf", &initialAccount, &winnings) == 2) {
                Account* financials = initializeFinancials(initialAccount);
                strcpy(financials->username, username);
                financials->winnings = winnings;
                fclose(file);
                return financials;
            }
            break;
        }
        // Skip to the next record
        fscanf(file, "%lf %lf", &initialAccount, &winnings); // Assume these reads are successful for simplicity
    }

    fclose(file);
    return NULL;
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
    userFinancials = loadFinancialsFromFile(filename, userFinancials);

    // Display balance and total earnings
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