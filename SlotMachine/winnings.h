#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_USERNAME_LENGTH 100

typedef struct {
	int userID;
	char username[MAX_USERNAME_LENGTH];
	double account_balance;
	double winnings;
}Balance;

Balance* initializeFinancials(double initialBalance);

void displayWinnings(Balance* financials);

void updateBalance(Balance* financials, double FundsToAdd);

void freeFinancials(Balance* financials);

Balance* loadFinancialsFromFile(const char* filename, const char* username);

void saveFinancialsToFile(const char* filename, Balance* financials);