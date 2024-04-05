
#include "Homepage.h"

void mainMenu() {
    char input[10];
    int choice;
    bool isValidInput;

    while (1) {
        printf("\n********** Main Menu **********\n");
        printf("1. Play/Spin\n");
        printf("2. Balance\n");
        printf("3. Winnings\n");
        printf("4. Scoreboard\n");
        printf("5. Exit\n");
        printf("********************************\n");
        printf("Enter your choice (1-5): ");
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
        if (isValidInput && sscanf(input, "%d", &choice) == 1 && choice >= 1 && choice <= 5) {
            switch (choice) {
            case 1:
                printf("You chose to Play/Spin.\n");
                // Add your code here
                break;
            case 2:
                printf("Your current balance is: $100\n"); // Example balance
                // Add your code here
                break;
            case 3:
                printf("Your total winnings are: $50\n"); // Example winnings
                // Add your code here
                break;
            case 4:
                printf("Scoreboard:\n");
                // Add your code here
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                // This should never be reached due to the validation above
                break;
            }
        }
        else {
            printf("Invalid choice. Please enter a whole number between 1 and 5.\n");
        }
    }

    return 0;
}