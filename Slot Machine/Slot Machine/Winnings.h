#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Account.h"

void displayWinnings(Account* financials);

void updateAccount(Account* financials, double FundsToAdd);

void startWinningsModule(Account* user);