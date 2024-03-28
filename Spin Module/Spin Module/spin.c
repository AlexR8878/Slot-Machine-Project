#include "spin.h"


// Function to simulate spinning effect
void spinEffect() {
    // Array of symbols
    char symbols[] = SYMBOLS;

    // Cycle through symbols for each column
    for (int i = 0; i < SPIN_EFFECT_CYCLE; i++) { 
        for (int j = 0; j < 3; j++) {
            printf("%c ", symbols[rand() % (NUM_SYMBOLS)]);
        }
        printf("\r"); // Return to the beginning of the line
        fflush(stdout); // Flush the output buffer
        Sleep(200); // Sleep for 200 milliseconds
    }
    printf("\n");
}

// Function to calculate the winnings
float calculateWinnings(int lines, float gambleAmount, char spinResults[3][3]) {
    // Define the values for each symbol
    float symbolValues[] = SYMBOL_VALUES;
    char symbols[] = SYMBOLS;

    // Define multipliers for different line bets
    float multipliers[] = { 1.5, // Multiplier for one line bet
                           1.2, // Multiplier for two line bet
                           1.0 }; // Multiplier for three line bet

    // Check for matching lines
    int matchingLines = 0;
    float winnings = 0.0;
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
void spin(Account* account, float gambleAmount, int lines) {

    // Array of symbols
    char symbols[] = SYMBOLS;

    // Multi-dimensional array to hold the spin results
    char spinResults[3][3];

    // Fill the spin_results array with random symbols
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int randomSymbolIndex = rand() % (NUM_SYMBOLS);
            spinResults[i][j] = symbols[randomSymbolIndex];
        }
    }

    spinEffect(); // Call the spin_effect function to simulate spinning

    // Print the slot machine interface
    printf("+-----+-----+-----+\n");
    for (int i = 0; i < 3; i++) {
        printf("| [%c] | [%c] | [%c] |\n", spinResults[i][0], spinResults[i][1], spinResults[i][2]);
        printf("+-----+-----+-----+\n");
    }

    float winnings = calculateWinnings(lines, gambleAmount, spinResults);
    if (winnings > 0) {
        printf("You won %.2f\n", winnings);
    }
    else {
        printf("Unfortunately, you didn't win this time.\n");
    }

    account->balance.winnings += winnings;
    account->balance.accountBalance += winnings - gambleAmount;

    printf("Your total winnings so far are %.2f\n", account->balance.winnings);
    printf("Your new balance is %.2f\n", account->balance.accountBalance);
}

// Function to return to main menu
void returnToMainMenu() {
    // Function to call main menu will go here
}

// Function to start the Spin module
void startSpinModule(Account account) {
    float gambleAmount;
    int lines;
    int spins;
    char continuePlaying;

    do {
        printf("Enter amount gambled per spin: ");
        scanf("%f", &gambleAmount);

        printf("Enter amount of lines: ");
        scanf("%d", &lines);

        printf("Enter number of spins: ");
        scanf("%d", &spins);

        for (int i = 0; i < spins; i++) {
            spin(&account, gambleAmount, lines);
        }

        printf("Your total winnings after %d spins are %.2f\n", spins, account.balance.winnings);
        printf("Your balance after %d spins is %.2f\n", spins, account.balance.accountBalance);

        printf("Do you want to continue playing? (Y/Any other key to stop playing): ");
        scanf(" %c", &continuePlaying); // Note the space before %c to skip any leftover newline characters

    } while (continuePlaying == 'Y' || continuePlaying == 'y');

    returnToMainMenu();
}