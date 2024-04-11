#define _CRT_SECURE_NO_WARNINGS
#include "winnings.h"
#include "Homepage.h"
#include <stdio.h>
#include <stdlib.h>

void displayWinnings(Account* financials) {
    printf("Total Earnings: $%.2f\n", financials->winnings);
    printf("Current Account: $%.2f\n", financials->balance);
}

void updateAccount(Account* financials, double FundsToAdd) {
    financials->balance += FundsToAdd;
}

void startWinningsModule(Account* userFinancials) {
    fflush(stdout); // Flush the output buffer
    // Load user's financials from a file
    loadUserFromFile(userFinancials);

    // Display balance and total earnings
    displayWinnings(userFinancials);

    double addToBalance = 0;
    
    // Ask if the user would like to add funds to balance
    char response;
    printf("Would you like to add funds to your balance? (y/n): ");
    scanf(" %c", &response);
    if (response == 'y' || response == 'Y') {
        bool addMore = true;
        while (addMore) {
            printf("Enter amount to add to account: ");
            if (scanf("%lf", &addToBalance) == 1) {
                // Update balance
                updateAccount(userFinancials, addToBalance);

                // Display updated balance and total earnings
                displayWinnings(userFinancials);
            }
            else {
                
                fprintf(stderr, "Invalid input\n");
                Sleep(1000);
                // Clear input buffer
                while (getchar() != '\n');
            }

            printf("Would you like to add more to your balance? (y/n): ");
            scanf(" %c", &response);
            if (response != 'y' && response != 'Y') {
                addMore = false;
            }
        }
    }
    if (response == 'n' || response == 'N') {
        printf("Returning to the main menu.\n");
        Sleep(1000);
    }
    else {                
        fprintf(stderr, "Invalid input\n");
        printf("Returning to the main menu.\n");
        Sleep(1000);
    }

    //updateAccount(userFinancials, addToBalance);

    // Display updated balance and total earnings
    //displayWinnings(userFinancials);

    saveUserToFile(userFinancials);

    system("cls");
}