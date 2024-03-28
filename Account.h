#pragma once

typedef struct Account {
    char username[50];
    int id;
    float balance;
} Account;

int userExists(char username[50], int id, float* balance);
int loginOrSignUp(char username[50], int id, float* balance);
void automaticFileSave(Account user);
void getUserInfo(char username[50], int* id);
int checkBalance(char username[50], int id, float* balance);