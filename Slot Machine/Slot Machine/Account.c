#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
#include "Account.h"


void loginOrSignUp(Account* user, const char username[MAXUSERNAMELENGTH], int id, double* balance, double* winnings) {
    char filename[100];
    sprintf(filename, "%s_%d.txt", username, id);

    // Try to open the file for reading to check if it exists
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        // File does not exist, so create a new file for the user
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error: Unable to open file for saving.\n");
            return;
        }
        fprintf(file, "%s %d 0.00 0.00\n", username, id);
        fclose(file);
        printf("Account created successfully!\n");
        strcpy(user->username, username);
        user->id = id;
        user->balance = 0.00;
        user->winnings = 0.00;
        *balance = 0.00;
        *winnings = 0.00;
    }
    else {
        // File exists, read the user data from the file
        fscanf(file, "%s %d %lf %lf", user->username, &user->id, &user->balance, &user->winnings);
        fclose(file);
        *balance = user->balance;
        *winnings = user->winnings;
        printf("Welcome back, %s!\n", username);
    }
}

void saveUserToFile(Account* user) {
    char filename[100];
    sprintf(filename, "%s_%d.txt", user->username, user->id);

    FILE* file = fopen(filename, "w"); // Open the file in write mode to overwrite the existing file
    if (file == NULL) {
        printf("Error: Unable to open file for saving.\n");
        return;
    }

    fprintf(file, "%s %d %.2f %.2f\n", user->username, user->id, user->balance, user->winnings);
    fclose(file);
    printf("User data saved successfully for %s.\n", user->username);
}

void loadUserFromFile(Account* user) {
    char filename[100];
    sprintf(filename, "%s_%d.txt", user->username, user->id);

    FILE* file = fopen(filename, "r"); // Open the file in read mode
    if (file == NULL) {
        printf("Error: Unable to open file for reading. User may not exist.\n");
        return;
    }

    fscanf(file, "%s %d %lf %lf", user->username, &user->id, &user->balance, &user->winnings);
    fclose(file);
    printf("User data loaded successfully for %s.\n", user->username);
}

void getUserInfo(char username[MAXUSERNAMELENGTH], int* id) {
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your ID: ");
    scanf("%d", id);
}

Account* intializeUser() {

    Account* currentUser = (Account*)malloc(sizeof(Account));

    if (currentUser == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    currentUser->balance = 100.00;
    currentUser->winnings = 0.0;
    currentUser->id = 0;
    currentUser->username[0] = '\0';
    return currentUser;
}

void appIntialization(Account* currentUser) {
    double balance, winnings;
    checkEligibility();

    char username[MAXUSERNAMELENGTH];
    int id;
    getUserInfo(username, &id);

    loginOrSignUp(currentUser, username, id, &balance, &winnings);

    strcpy(currentUser->username, username);
    currentUser->id = id;
    currentUser->balance = balance;
    currentUser->winnings = winnings;
    saveUserToFile(currentUser);
    Sleep(2000);
    system("cls");
}

void freeUser(Account* currentUser) {
    free(currentUser);
}