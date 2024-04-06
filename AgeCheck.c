#define _CRT_SECURE_NO_WARNINGS
#include "AgeCheck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* ageCheck(char input[]) {
    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
        return "You are eligible to use the application.\n";
    }
    else if (strcmp(input, "N") == 0 || strcmp(input, "n") == 0) {
        return "You are not eligible to use the application.\n";
        exit(1);
    }
    else {
        return "Invalid input.\n";
        exit(1);
    }
}

// Function to prompt the user and check eligibility
void checkEligibility() {
    char ageInput[3]; // Changed to array for string input
    printf("+---*---*---*---SLOTS---*---*---*---*---+\n");
    printf("\n");
    printf("Are you above the legal age of 19? (Y/N): ");
    scanf("%2s", ageInput); // Read a single character

    const char* result = ageCheck(ageInput); // Call ageCheck and capture its result

    // Print the result
    printf("%s", result);
}
