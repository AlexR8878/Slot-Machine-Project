#include <assert.h>
#include <math.h>
#include "spin.h"

void test_calculate_winnings() {
    // Test 1: All symbols are the same
    char spin_results_same[3][3] = { {'7', '7', '7'}, {'7', '7', '7'}, {'7', '7', '7'} };
    float winnings_same = calculateWinnings(3, 10.0, spin_results_same);
    printf("Actual winnings for test 1: %.2f\n", winnings_same);
    assert(fabs(winnings_same - 900.0) < 0.01); // Use fabs to get the absolute difference

    // Test 2: All symbols are different
    char spin_results_diff[3][3] = { {'7', '~', '!'}, {'@', '#', '$'}, {'%', '^', '&'} };
    float winnings_diff = calculateWinnings(3, 0.0, spin_results_diff);
    printf("Actual winnings for test 2: %.2f\n", winnings_diff);
    assert(fabs(winnings_diff - 0.0) < 0.01); // Use fabs to get the absolute difference

    printf("All tests passed for calculate_winnings.\n");
}


int main() {
    test_calculate_winnings();
    return 0;
}
