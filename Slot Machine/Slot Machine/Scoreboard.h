#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Account.h"
#include "AgeCheck.h"

void updateWinnings(char username[MAXUSERNAMELENGTH], float winnings);
void updateScoreboard(char username[MAXUSERNAMELENGTH], float winnings);
void saveTopWinners();
void displayTopWinners();