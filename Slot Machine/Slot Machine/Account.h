#pragma once
#define MAXUSERNAMELENGTH   50

typedef struct Account {
    char username[MAXUSERNAMELENGTH];
    int id;
    double balance;
    double winnings;
} Account;

int userExists(char username[MAXUSERNAMELENGTH], int id, double* balance);
int loginOrSignUp(char username[MAXUSERNAMELENGTH], int id, double* balance);
void automaticFileSave(Account user);
void getUserInfo(char username[MAXUSERNAMELENGTH], int* id);
int checkBalance(char username[MAXUSERNAMELENGTH], int id, double* balance);
void intializeUser(Account* currentUser);
void freeUser(Account* currentUser);