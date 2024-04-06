#include "Account.h"
#include "AgeCheck.h"
#include "Homepage.h"

int main(int argc, char* argv[]) {
    argc = 7;
    argv[1] = "1a1a1a";
    // Check if a code was provided as a command-line argument
    if (argc < 2) {
        printf("No code provided. Please start the application with a valid code.\n");
        return 1;
    }

    // Validate the provided code
    if (isValidCode(argv[1])) {
        printf("Valid code provided. Starting the application...\n");
        // Start the application
    }
    else {
        printf("Invalid code provided. Please start the application with a valid code.\n");
        return 1;
    }
    Account* currentUser = intializeUser();

    appIntialization(currentUser);

    mainMenu(currentUser);

    free(currentUser);

    return 0;
}