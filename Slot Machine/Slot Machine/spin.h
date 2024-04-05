#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>
#include "Account.h"

#define SYMBOLS  { '7', '~', '!', '@', '#', '$', '%', '^' } // Symbols used for the slot machine
#define SYMBOL_VALUES   { 100.0, 50.0, 25.0, 20.0, 15.0, 10.0, 5.0, 2.5 } // Values used for each symbol. Value position in the arrary corresonds to SYMBOL value in the same postion.
#define SPIN_EFFECT_CYCLE   10 // Change this to increase/decrease the number of cycles
#define NUM_SYMBOLS     8

double calculateWinnings(int lines, double gambleAmount, char spinResults[3][3]);
void spin(Account* account, double gambleAmount, int lines);
void returnToMainMenu();
bool isPositiveInteger(const char* str);
void startSpinModule(Account* account);