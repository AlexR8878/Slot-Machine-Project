#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 




void ageCheck(char input[]) {
    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
        printf("You are eligible to use the application.\n");
    }
    else if (strcmp(input, "N") == 0 || strcmp(input, "n") == 0) {
        printf("You are not eligible to use the application.\n");
    }
    else {
        printf("Invalid input.\n");
    }
}

void checkEligibility() {
    char ageInput[2]; // Changed to array for string input
    printf("+---*---*---*---SLOTS---*---*---*---*---+\n");
    printf("\n");
    printf("Are you above the legal age of 19? (Y/N): ");
    scanf("%1s", ageInput); // Read a single character
  
    ageCheck(ageInput);
}