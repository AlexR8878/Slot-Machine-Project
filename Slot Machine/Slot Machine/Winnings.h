#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Account.h"

void displayWinnings(Account* financials);

void updateAccount(Account* financials, double FundsToAdd);

void loadFinancialsFromFile(const char* filename, Account* financials);

void saveFinancialsToFile(const char* filename, Account* financials);

void startWinningsModule(Account* user);