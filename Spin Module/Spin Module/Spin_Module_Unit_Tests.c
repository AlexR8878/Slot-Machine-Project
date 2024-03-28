#include <assert.h>
#include <math.h>
#include "spin.h"

void test_calculate_winnings() {
    // Test 1: All symbols are the same
    char spin_results_same[3][3] = { {'7', '7', '7'}, {'7', '7', '7'}, {'7', '7', '7'} };
    float winnings_same = calculateWinnings(3, 10.0, spin_results_same);
    printf("Actual winnings for test 1: %.2f\n", winnings_same);
    assert(fabs(winnings_same - 3000.0) < 0.01); // Use fabs to get the absolute difference

    // Test 2: All symbols are different
    char spin_results_diff[3][3] = { {'7', '~', '!'}, {'@', '#', '$'}, {'%', '^', '&'} };
    float winnings_diff = calculateWinnings(3, 0.0, spin_results_diff);
    printf("Actual winnings for test 2: %.2f\n", winnings_diff);
    assert(fabs(winnings_diff - 0.0) < 0.01); // Use fabs to get the absolute difference

    // Test 3: Only one line matches
    char spin_results_one_match[3][3] = { {'7', '7', '7'}, {'@', '#', '$'}, {'%', '^', '&'} };
    float winnings_one_match = calculateWinnings(3, 10.0, spin_results_one_match);
    printf("Actual winnings for test 3: %.2f\n", winnings_one_match);
    assert(fabs(winnings_one_match - 1000.0) < 0.01);

    // Test 4: "X" pattern match
    char spin_results_x_pattern[3][3] = { {'7', '@', '7'}, {'#', '7', '$'}, {'7', '%', '7'} };
    float winnings_x_pattern = calculateWinnings(3, 10.0, spin_results_x_pattern);
    printf("Actual winnings for test 4: %.2f\n", winnings_x_pattern);
    assert(fabs(winnings_x_pattern - (100 * 10 * 2)) < 0.01);

    // Test 5: No lines match but there is an "X" pattern
    char spin_results_x_no_line[3][3] = { {'7', '@', '!'}, {'#', '7', '$'}, {'!', '%', '7'} };
    float winnings_x_no_line = calculateWinnings(3, 10.0, spin_results_x_no_line);
    printf("Actual winnings for test 5: %.2f\n", winnings_x_no_line);
    assert(fabs(winnings_x_no_line - 0.0) < 0.01);

    // Test 6: Edge case with minimum bet and a single line
    char spin_results_min_bet[3][3] = { {'7', '7', '7'}, {'@', '#', '$'}, {'%', '^', '&'} };
    float winnings_min_bet = calculateWinnings(1, 0.01, spin_results_min_bet);
    printf("Actual winnings for test 6: %.2f\n", winnings_min_bet);
    assert(fabs(winnings_min_bet - 1.0) < 0.01);

    // Test 7: Edge case with maximum symbols and all lines match
    char spin_results_max_symbols[3][3] = { {'>', '>', '>'}, {'>', '>', '>'}, {'>', '>', '>'} };
    float winnings_max_symbols = calculateWinnings(3, 10.0, spin_results_max_symbols);
    printf("Actual winnings for test 7: %.2f\n", winnings_max_symbols);
    assert(fabs(winnings_max_symbols - 0.3) < 0.01);

    printf("All tests passed for calculateWinnings.\n");
}


int main() {
    test_calculate_winnings();
    return 0;
}