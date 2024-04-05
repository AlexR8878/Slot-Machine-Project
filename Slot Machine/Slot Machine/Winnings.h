#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Account.h"

Account* initializeFinancials(double initialAccount);

void displayWinnings(Account* financials);

void updateAccount(Account* financials, double FundsToAdd);

void freeFinancials(Account* financials);

Account* loadFinancialsFromFile(const char* filename, const char* username);

void saveFinancialsToFile(const char* filename, Account* financials);

void startWinningsModule(Account* user);