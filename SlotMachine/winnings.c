#define _CRT_SECURE_NO_WARNINGS
#include "winnings.h"
#include <stdio.h>
#include <stdlib.h>

Balance* initializeFinancials(double initialBalance) {
    Balance* financials = (Balance*)malloc(sizeof(Balance));
    if (financials == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    financials->account_balance = initialBalance;
    financials-> winnings = 0.0;
    return financials;
}

void displayWinnings(Balance* financials) {
    printf("Total Earnings: $%.2f\n", financials->winnings);
    printf("Current Balance: $%.2f\n", financials->account_balance);
}

void updateBalance(Balance* financials, double FundsToAdd) {
    financials->account_balance += FundsToAdd;
}

void freeFinancials(Balance* financials) {
    free(financials);
}

Balance* loadFinancialsFromFile(const char* filename, const char* username) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    char buffer[MAX_USERNAME_LENGTH];
    double initialBalance, winnings;
    while (fscanf(file, "%s", buffer) == 1) {
        if (strcmp(buffer, username) == 0) {
            if (fscanf(file, "%lf %lf", &initialBalance, &winnings) == 2) {
                Balance* financials = initializeFinancials(initialBalance);
                strcpy(financials->username, username);
                financials->winnings = winnings;
                fclose(file);
                return financials;
            }
            break;
        }
        // Skip to the next record
        fscanf(file, "%lf %lf", &initialBalance, &winnings); // Assume these reads are successful for simplicity
    }

    fclose(file);
    return NULL;
}

void saveFinancialsToFile(const char* filename, Balance* financials) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    fprintf(file, "%.2f\n%.2f", financials->account_balance, financials->winnings);
    fclose(file);
}