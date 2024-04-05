#pragma once
#define MAXUSERNAMELENGTH   50

typedef struct Account {
    char username[MAXUSERNAMELENGTH];
    int id;
    double balance;
    double winnings;
} Account;

void loginOrSignUp(Account* currentUser, char username[MAXUSERNAMELENGTH], int id, double* balance, double* winnings);
void getUserInfo(char username[MAXUSERNAMELENGTH], int* id);
void saveUserToFile(Account* user);
void loadUserFromFile(Account* user);
Account* intializeUser();
void appIntialization(Account* currentUser);
void freeUser(Account* currentUser);