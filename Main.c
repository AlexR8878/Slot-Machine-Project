#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "AgeCheck.h"
#include "Account.h"

int main() {
    float balance;
    checkEligibility();

    char username[50];
    int id;
    getUserInfo(username, &id);

    int loginResult = loginOrSignUp(username, id, &balance);
    if (loginResult == -1) {
        return 1; 
    }

    Account currentUser;
    strcpy(currentUser.username, username);
    currentUser.id = id;
    currentUser.balance = balance;
    automaticFileSave(currentUser);

    return 0;
}