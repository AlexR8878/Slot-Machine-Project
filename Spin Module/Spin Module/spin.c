#include "spin.h"

// Function to calculate the winnings
double calculateWinnings(int lines, double gambleAmount, char spinResults[3][3]) {
    // Define the values for each symbol
    double symbolValues[] = SYMBOL_VALUES;
    char symbols[] = SYMBOLS;

    // Define multipliers for different line bets
    double multipliers[] = { 1.5, // Multiplier for one line bet
                           1.2, // Multiplier for two line bet
                           1.0 }; // Multiplier for three line bet

    // Check for matching lines
    int matchingLines = 0;
    double winnings = 0.0;
    int lineIndices[3] = { 1, 0, 2 }; // Order of lines to check: middle, top, bottom

    for (int i = 0; i < lines; i++) {
        int lineToCheck = lineIndices[i];
        if (spinResults[lineToCheck][0] == spinResults[lineToCheck][1] && spinResults[lineToCheck][1] == spinResults[lineToCheck][2]) {
            // Find the value of the matching symbol and add it to the winnings
            for (int k = 0; k < NUM_SYMBOLS; k++) {
                if (spinResults[lineToCheck][0] == symbols[k]) {
                    winnings += symbolValues[k] * gambleAmount * multipliers[lines - 1];
                    break; // Break out of the loop once the symbol is found
                }
            }
            matchingLines++;
        }
    }

    // Calculate winnings for "X" pattern separately if no matching lines
    if (matchingLines == 0 && lines == 3) {
        if (spinResults[0][0] == spinResults[1][1] && spinResults[1][1] == spinResults[2][2] &&
            spinResults[0][2] == spinResults[1][1] && spinResults[1][1] == spinResults[2][0]) {
            for (int k = 0; k < NUM_SYMBOLS; k++) {
                if (spinResults[1][1] == symbols[k]) {
                    winnings = symbolValues[k] * gambleAmount * 2; // Apply 2x bonus for "X" pattern
                    break; // Break out of the loop once the symbol is found
                }
            }
        }
    }

    return winnings;
}


// Spin function
void spin(Account* account, double gambleAmount, int lines) {
    // Array of symbols
    char symbols[] = SYMBOLS;

    // Multi-dimensional array to hold the spin results
    char spinResults[3][3];

    // Move the cursor to the top-left corner of the console
    printf("\033[H");

    // Print the slot machine interface with placeholders
    printf("+-----+-----+-----+\n");
    for (int i = 0; i < 3; i++) {
        printf("|     |     |     |\n");
    }
    printf("|     |     |     |\n");
    printf("|     |     |     |\n");
    printf("|     |     |     |\n");
    printf("|     |     |     |\n");
    printf("+-----+-----+-----+\n");

    // Move the cursor up to the first placeholder
    printf("\033[4A");

    // Spin each column and update the spinResults array
    for (int col = 0; col < 3; col++) {
        // Spin effect for the current column
        for (int i = 0; i < SPIN_EFFECT_CYCLE; i++) {
            for (int row = 0; row < 3; row++) {
                // Position the cursor at the start of the current placeholder
                printf("\033[%d;1H", 3 + row * 2);
                printf("\033[%dC", 2 + col * 6);
                // Print a random symbol for the current column
                printf("[%c]", symbols[rand() % (NUM_SYMBOLS)]);
                fflush(stdout); // Flush the output buffer
            }
            // Sleep for 200 milliseconds before the next cycle
            Sleep(200);
            // Move the cursor back to the first row of the current column for the next cycle
            printf("\033[6A");
        }

        // Set the final symbols for the current column
        for (int row = 0; row < 3; row++) {
            // Position the cursor at the start of the current placeholder
            printf("\033[%d;1H", 3 + row * 2);
            printf("\033[%dC", 2 + col * 6);
            // Generate a random symbol for the current position
            int randomSymbolIndex = rand() % (NUM_SYMBOLS);
            spinResults[row][col] = symbols[randomSymbolIndex];
            // Print the final symbol for the current placeholder
            printf("[%c]", spinResults[row][col]);
            fflush(stdout); // Flush the output buffer
        }
    }

    // Move the cursor down to after the slot machine interface
    printf("\n\n\n\r");

    double winnings = calculateWinnings(lines, gambleAmount, spinResults);
    
    printf("You won %.2f\n", winnings);
    
    account->winnings += winnings;
    account->balance += winnings;
    account->balance -= gambleAmount;

    printf("Your total winnings so far are %.2f\n", account->winnings);
    printf("Your new balance is %.2f\n", account->balance);
    Sleep(1000);
}

// Function to return to main menu
void returnToMainMenu() {
    // Function to call main menu will go here
}

bool isPositiveInteger(const char* str) {
    // Check for empty string
    if (*str == '\0') return false;

    // Check for positive integer
    for (; *str; str++) {
        if (!isdigit(*str)) return false;
    }
    return true;
}

// Function to start the Spin module
void startSpinModule(Account* account) {
    double gambleAmount = 0;
    int lines = 0;
    int spins = 0;
    char continuePlaying[3]; // Changed to char array to use with fgets
    char input[50];

    do {
        // Input validation for gamble amount
        do {
            printf("Enter amount gambled per spin: ");
            if (scanf("%lf", &gambleAmount) != 1) { // Read gambleAmount as a double
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n'); // Clear the buffer
                gambleAmount = 0;
                continue;
            }
            // Check if the entered amount is a double with up to 2 decimal places
            if (roundf(gambleAmount * 100) != gambleAmount * 100) {
                printf("Invalid amount. Please enter a positive double number up to 2 decimal places.\n");
                gambleAmount = 0;
            }
            if (gambleAmount <= 0 || gambleAmount > account->balance) {
                printf("Invalid amount. Please enter a positive number up to your current balance of %.2f\n", account->balance);
                gambleAmount = 0;
            }
            while (getchar() != '\n'); // Clear the buffer
        } while (gambleAmount <= 0 || gambleAmount > account->balance || roundf(gambleAmount * 100) != gambleAmount * 100);

        // Input validation for lines
        do {
            printf("Enter amount of lines (1-3): ");
            fgets(input, 50, stdin);
            // Remove newline character if present
            input[strcspn(input, "\n")] = 0;
            if (!isPositiveInteger(input)) {
                printf("Invalid input. Please enter a whole number.\n");
                lines = 0;
                continue;
            }
            lines = atoi(input);
            if (lines < 1 || lines > 3) {
                printf("Invalid number of lines. Please enter a value between 1 and 3.\n");
                lines = 0;
            }
        } while (lines < 1 || lines > 3);

        // Validate spins input
        do {
            printf("Enter number of spins: ");
            fgets(input, 50, stdin);
            // Remove newline character if present
            input[strcspn(input, "\n")] = 0;
            if (!isPositiveInteger(input)) {
                printf("Invalid input. Please enter a whole number.\n");
                spins = 0;
                continue;
            }
            spins = atoi(input);
            double totalBet = gambleAmount * spins;
            if (spins <= 0 || totalBet > account->balance) {
                printf("Invalid number of spins or insufficient balance.\n");
                spins = 0;
            }
        } while (spins <= 0 || gambleAmount * spins > account->balance);


        system("cls"); // Clear the console screen on Windows - "clear" for Unix based systems

        for (int i = 0; i < spins; i++) {
            spin(account, gambleAmount, lines);
        }

        printf("Your total winnings after %d spins are %.2f\n", spins, account->winnings);
        printf("Your balance after %d spins is %.2f\n", spins, account->balance);

        printf("Do you want to continue playing? (Y/Any other key to stop playing): ");
        fgets(continuePlaying, sizeof(continuePlaying), stdin); // Use fgets to read the input

    } while (continuePlaying[0] == 'Y' || continuePlaying[0] == 'y');


    returnToMainMenu();
}