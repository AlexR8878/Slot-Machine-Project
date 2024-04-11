#include "AgeCheck.h"

void ageCheck(char input[]) {
    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
        printf("You are eligible to use the application.\n");
    }
    else if (strcmp(input, "N") == 0 || strcmp(input, "n") == 0) {
        printf("You are not eligible to use the application.\n");
        exit(1);
    }
    else {
        printf("Invalid input.\n");
        exit(1);
    }
}

void checkEligibility() {
    char ageInput[2]; // Changed to array for string input
    printf("+---*---*---*-STAR-SLOTZ-*---*---*---*---+\n");
    printf("\n");
    printf("Are you above the legal age of 19? (Y/N): ");
    scanf("%s", ageInput); // Read a single character

    ageCheck(ageInput);
}