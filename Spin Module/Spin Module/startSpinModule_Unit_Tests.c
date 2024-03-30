#define _CRT_SECURE_NO_WARNINGS

#include "spin.h"
#include "startSpinModule_Unit_Tests.h"

// Function to simulate starting the Spin module with a mock account
void simulateStartSpinModule() {
    // Create a mock account with a predefined balance
    Account mockAccount = { 0, "MockUser", 1000.0, 0.0 };

    // Display the initial balance
    printf("Starting the Spin module simulation...\n");
    printf("Initial balance for MockUser: %.2f\n", mockAccount.balance);

    // Start the Spin module with the mock account
    startSpinModule(&mockAccount);

    // Display the final balance after the simulation
    printf("Final balance for MockUser: %.2f\n", mockAccount.balance);
    printf("Total winnings for MockUser: %.2f\n", mockAccount.winnings);
}