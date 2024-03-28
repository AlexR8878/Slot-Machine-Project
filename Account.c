#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Account.h"

int userExists(char username[50], int id, float* balance) {
    FILE* file = fopen("File.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    Account user;
    while (fscanf(file, "%s %d %f", user.username, &user.id, &user.balance) != EOF) {
        if (strcmp(user.username, username) == 0 && user.id == id) {
            *balance = user.balance;
            fclose(file);
            return 1; // User already exists
        }
    }

    fclose(file);
    return 0; // User doesn't exist
}

int loginOrSignUp(char username[50], int id, float* balance) {
    FILE* file = fopen("File.txt", "a+");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    Account user;
    while (fscanf(file, "%s %d %f", user.username, &user.id, &user.balance) != EOF) {
        if (strcmp(user.username, username) == 0 && user.id == id) {
            *balance = user.balance;
            fclose(file);
            printf("Welcome back, %s!\n", username);
            return 1; // User logged in successfully
        }
    }

    printf("User not found. Creating new account...\n");
    fprintf(file, "%s %d 0\n", username, id); // Initialize balance to 0 for new account
    fclose(file);
    printf("Account created successfully!\n");
    *balance = 0; // Set balance to 0 for new account
    return 0; // New account created
}

void automaticFileSave(Account user) {
    FILE* file = fopen("File.txt", "a");
    if (file == NULL) {
        printf("Error: Unable to open file for saving.\n");
        return;
    }
    fprintf(file, "Username: %s\nID: %d\nBalance: %.2f\n", user.username, user.id, user.balance);
    fclose(file);
    printf("User data saved successfully.\n");
}

void getUserInfo(char username[50], int* id) {
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your ID: ");
    scanf("%d", id);
}

int checkBalance(char username[50], int id, float* balance) {
 
    FILE* file = fopen("File.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    Account user;
    while (fscanf(file, "%s %d %f", user.username, &user.id, &user.balance) != EOF) {
        if (strcmp(user.username, username) == 0 && user.id == id) {
            *balance = user.balance;
            fclose(file);
            printf("Your current balance is: $%.2f\n", *balance);
            return 1; // Balance checked successfully
        }
    }

    fclose(file);
    printf("User not found.\n");
    return 0; // User doesn't exist
}