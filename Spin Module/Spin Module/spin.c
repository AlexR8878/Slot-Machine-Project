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
float calculateWinnings(int lines, float gamble_amount, char spin_results[3][3]) {
    // Define the values for each symbol
    float symbol_values[] = SYMBOL_VALUES;
    char symbols[] = SYMBOLS;

    // Check for matching lines
    int matching_lines = 0;
    float winnings = 0.0;
    for (int i = 0; i < lines; i++) { // Only consider the number of lines the user has bet on
        if (spin_results[i][0] == spin_results[i][1] && spin_results[i][1] == spin_results[i][2]) {
            // Find the value of the matching symbol and add it to the winnings
            for (int k = 0; k < NUM_SYMBOLS; k++) {
                if (spin_results[i][0] == symbols[k]) {
                    winnings += symbol_values[k] * gamble_amount;
                    break; // Break out of the loop once the symbol is found
                }
            }
            matching_lines++;
        }
    }

    // Calculate winnings for "X" pattern separately if no matching lines
    if (matching_lines == 0 && lines == 3) {
        if (spin_results[0][0] == spin_results[1][1] && spin_results[1][1] == spin_results[2][2] &&
            spin_results[0][2] == spin_results[1][1] && spin_results[1][1] == spin_results[2][0]) {
            for (int k = 0; k < NUM_SYMBOLS; k++) {
                if (spin_results[1][1] == symbols[k]) {
                    winnings = symbol_values[k] * gamble_amount * 2; // Apply 2x bonus for "X" pattern
                    break; // Break out of the loop once the symbol is found
                }
            }
        }
    }

    return winnings;
}


// Spin function
void spin(Account* account, float gamble_amount, int lines) {

    // Array of symbols
    char symbols[] = SYMBOLS;

    // Multi-dimensional array to hold the spin results
    char spin_results[3][3];

    // Fill the spin_results array with random symbols
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int random_symbol_index = rand() % (NUM_SYMBOLS);
            spin_results[i][j] = symbols[random_symbol_index];
        }
    }

    spinEffect(); // Call the spin_effect function to simulate spinning

    // Print the slot machine interface
    printf("+-----+-----+-----+\n");
    for (int i = 0; i < 3; i++) {
        printf("| [%c] | [%c] | [%c] |\n", spin_results[i][0], spin_results[i][1], spin_results[i][2]);
        printf("+-----+-----+-----+\n");
    }

    float winnings = calculateWinnings(lines, gamble_amount, spin_results);
    if (winnings > 0) {
        printf("You won %.2f\n", winnings);
    }
    else {
        printf("Unfortunately, you didn't win this time.\n");
    }

    account->balance.winnings += winnings;
    account->balance.account_balance += winnings - gamble_amount;

    printf("Your total winnings so far are %.2f\n", account->balance.winnings);
    printf("Your new balance is %.2f\n", account->balance.account_balance);
}

// Function to return to main menu
void returnToMainMenu() {
    // Function to call main menu will go here
}

// Function to start the Spin module
void startSpinModule(Account account) {
    float gamble_amount;
    int lines;
    int spins;
    char continue_playing;

    do {
        printf("Enter amount gambled per spin: ");
        scanf("%f", &gamble_amount);

        printf("Enter amount of lines: ");
        scanf("%d", &lines);

        printf("Enter number of spins: ");
        scanf("%d", &spins);

        for (int i = 0; i < spins; i++) {
            spin(&account, gamble_amount, lines);
        }

        printf("Your total winnings after %d spins are %.2f\n", spins, account.balance.winnings);
        printf("Your balance after %d spins is %.2f\n", spins, account.balance.account_balance);

        printf("Do you want to continue playing? (Y/Any other key to stop playing): ");
        scanf(" %c", &continue_playing); // Note the space before %c to skip any leftover newline characters

    } while (continue_playing == 'Y' || continue_playing == 'y');

    returnToMainMenu();
}