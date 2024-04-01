#define _CRT_SECURE_NO_WARNINGS

#include "spin.h"
#include "spin_Unit_Tests.h"

void testSpin1() {
    // Mock an account with a known balance
    Account testAccount = { 0, "testUser", 100.0, 0.0 };

    // Mock inputs for the spin function
    double gambleAmount = 10.0;
    int lines = 1;

    // Redirect stdout to a buffer to suppress output
    freopen("test_output_spin.txt", "w", stdout);

    // Call the spin function
    spin(&testAccount, gambleAmount, lines);

    // Redirect stdout back to the console
    freopen("CONOUT$", "w", stdout);

    // Check if the account balance and winnings have been updated correctly
    assert(testAccount.balance != 100.0);
    assert(testAccount.winnings >= 0.0);

    printf("Spin Test Passed.\n");

    // Clean up
    if (remove("test_output_spin.txt") != 0) {
        perror("Error deleting test output file");
    }
    else {
        printf("Test output file successfully deleted.\n");
    }
}
