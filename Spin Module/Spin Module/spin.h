#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define SYMBOLS  { '7', '~', '!', '@', '#', '$', '%', '^', '&', '*', '`', '/', '?', '<', '>' } // Symbols used for the slot machine
#define SYMBOL_VALUES   { 100.0, 50.0, 25.0, 20.0, 15.0, 10.0, 5.0, 2.5, 1.0, 0.50, 0.25, 0.10, 0.05, 0.025, 0.01 } // Values used for each symbol. Value position in the arrary corresonds to SYMBOL value in the same postion.
#define SPIN_EFFECT_CYCLE   10 // Change this to increase/decrease the number of cycles
#define NUM_SYMBOLS     15

typedef struct {
    float account_balance;
    float winnings;
} Balance;

typedef struct {
    int user_id;
    char username[50];
    Balance balance;
} Account;

void spinEffect();
float calculateWinnings(int lines, float gamble_amount, char spin_results[3][3]);
void spin(Account* account, float gamble_amount, int lines);
void returnToMainMenu();
void start_spin_module(Account account);