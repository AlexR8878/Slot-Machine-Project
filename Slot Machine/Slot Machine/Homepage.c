#include"Account.h"
#include"AgeCheck.h"
#include "Homepage.h"
#include "spin.h"
#include "Winnings.h"
#include "Scoreboard.h"

void mainMenu(Account* user) {
    char input[10];
    int choice;
    bool isValidInput;

    while (1) {
        printf("\n********** Main Menu **********\n");
        printf("1. Play/Spin\n");
        printf("2. Account\n");
        printf("3. Scoreboard\n");
        printf("4. Exit\n");
        printf("********************************\n");
        printf("Enter your choice (1-4): ");
        while (getchar() != '\n');
        fgets(input, 10, stdin); // Read the input as a string

        // Check for decimal point (can reuse function from Spin-Module)
        isValidInput = true;
        for (int i = 0; input[i] != '\n' && input[i] != '\0'; i++) {
            if (input[i] == '.') {
                isValidInput = false;
                break;
            }
        }

        // If input is valid and is an integer within the valid range
        if (isValidInput && sscanf(input, "%d", &choice) == 1 && choice >= 1 && choice <= 4) {
            switch (choice) {
            case 1:
                startSpinModule(user);
                break;
            case 2:
                startWinningsModule(user);
                break;
            case 3:
                displayTopWinners();
                break;
            case 4:
                saveUserToFile(user);
                printf("Exiting the program. Goodbye!\n");                
                exit(1);
            default:
                // This should never be reached due to the validation above
                break;
            }
        }
        else {
            printf("Invalid choice. Please enter a whole number between 1 and 4.\n");
        }
    }
}