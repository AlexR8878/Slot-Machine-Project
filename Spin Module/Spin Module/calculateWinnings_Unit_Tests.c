#include <assert.h>
#include <math.h>
#include "spin.h"

void testCalculateWinnings() {
    // Test 1: One line bet on the middle line with multiplier
    char spinResultsOneLine[3][3] = { {'@', '#', '$'}, {'7', '7', '7'}, {'%', '^', '&'} };
    float winningsOneLine = calculateWinnings(1, 10.0, spinResultsOneLine);
    printf("Actual winnings for test 1: %.2f\n", winningsOneLine);
    assert(fabs(winningsOneLine - (1000.0 * 1.5)) < 0.01); // 1.5x multiplier for one line

    // Test 2: Two line bet on the top and middle lines with multiplier
    char spinResultsTwoLines[3][3] = { {'7', '7', '7'}, {'7', '7', '7'}, {'%', '^', '&'} };
    float winningsTwoLines = calculateWinnings(2, 10.0, spinResultsTwoLines);
    printf("Actual winnings for test 2: %.2f\n", winningsTwoLines);
    assert(fabs(winningsTwoLines - (2000.0 * 1.2)) < 0.01); // 1.2x multiplier for two lines

    // Test 3: Three line bet with all lines matching
    char spinResultsThreeLines[3][3] = { {'7', '7', '7'}, {'7', '7', '7'}, {'7', '7', '7'} };
    float winningsThreeLines = calculateWinnings(3, 10.0, spinResultsThreeLines);
    printf("Actual winnings for test 3: %.2f\n", winningsThreeLines);
    assert(fabs(winningsThreeLines - 3000.0) < 0.01); // No multiplier for three lines

    // Test 4: "X" pattern with matching symbols and no line matches
    char spinResultsXMatch[3][3] = { {'$', '@', '$'}, {'#', '$', '&'}, {'$', '%', '$'} };
    float winningsXMatch = calculateWinnings(3, 10.0, spinResultsXMatch);
    printf("Actual winnings for test 4: %.2f\n", winningsXMatch);
    assert(fabs(winningsXMatch - (10.0 * 10.0 * 2)) < 0.01); // 2x bonus for "X" pattern

    // Test 5: No lines match and no "X" pattern
    char spinResultsNoMatchNoX[3][3] = { {'7', '~', '!'}, {'@', '#', '$'}, {'%', '^', '&'} };
    float winningsNoMatchNoX = calculateWinnings(3, 10.0, spinResultsNoMatchNoX);
    printf("Actual winnings for test 5: %.2f\n", winningsNoMatchNoX);
    assert(fabs(winningsNoMatchNoX - 0.0) < 0.01);

    // Test 6: Edge case with minimum bet and a single line with multiplier
    char spinResultsMinBetEdge[3][3] = { {'@', '#', '$'}, {'7', '7', '7'}, {'%', '^', '&'} };
    float winningsMinBetEdge = calculateWinnings(1, 0.01, spinResultsMinBetEdge);
    printf("Actual winnings for test 6: %.2f\n", winningsMinBetEdge);
    assert(fabs(winningsMinBetEdge - (1.0 * 1.5)) < 0.01); // 1.5x multiplier for one line

    // Test 7: Edge case with min symbol value and all lines match
    char spinResultsMinSymbolsEdge[3][3] = { {'>', '>', '>'}, {'>', '>', '>'}, {'>', '>', '>'} };
    float winningsMinSymbolsEdge = calculateWinnings(3, 10.0, spinResultsMinSymbolsEdge);
    printf("Actual winnings for test 7: %.2f\n", winningsMinSymbolsEdge);
    assert(fabs(winningsMinSymbolsEdge - 0.3) < 0.01);

    // Test 8: One line bet with "X" pattern (should not apply for one line bet)
    char spinResultsOneLineX[3][3] = { {'$', '@', '$'}, {'$', '$', '$'}, {'$', '%', '$'} };
    float winningsOneLineX = calculateWinnings(1, 10.0, spinResultsOneLineX);
    printf("Actual winnings for test 8: %.2f\n", winningsOneLineX);
    assert(fabs(winningsOneLineX - (100.0 * 1.5)) < 0.01); // 1.5x multiplier for one line, "X" pattern ignored

    // Test 9: Two line bet with "X" pattern (should not apply for two line bet)
    char spinResultsTwoLinesX[3][3] = { {'$', '$', '$'}, {'$', '$', '$'}, {'$', '%', '$'} };
    float winningsTwoLinesX = calculateWinnings(2, 10.0, spinResultsTwoLinesX);
    printf("Actual winnings for test 9: %.2f\n", winningsTwoLinesX);
    assert(fabs(winningsTwoLinesX - (200.0 * 1.2)) < 0.01); // 1.2x multiplier for two lines, "X" pattern ignored

    // Test 10: One line bet with no matches and "X" pattern
    char spinResultsOneLineNoMatchX[3][3] = { {'$', '#', '$'}, {'@', '$', '$'}, {'$', '^', '$'} };
    float winningsOneLineNoMatchX = calculateWinnings(1, 10.0, spinResultsOneLineNoMatchX);
    printf("Actual winnings for test 10: %.2f\n", winningsOneLineNoMatchX);
    assert(fabs(winningsOneLineNoMatchX - 0.0) < 0.01); // No winnings, "X" pattern ignored for one line

    // Test 11: Two line bet with no matches and "X" pattern
    char spinResultsTwoLinesNoMatchX[3][3] = { {'$', '@', '$'}, {'@', '$', '$'}, {'$', '^', '$'} };
    float winningsTwoLinesNoMatchX = calculateWinnings(2, 10.0, spinResultsTwoLinesNoMatchX);
    printf("Actual winnings for test 11: %.2f\n", winningsTwoLinesNoMatchX);
    assert(fabs(winningsTwoLinesNoMatchX - 0.0) < 0.01); // No winnings, "X" pattern ignored for two lines

    // Test 12a: One line bet with matching symbols but not in the middle line
    char spinResultsOneLineTop[3][3] = { {'7', '7', '7'}, {'@', '#', '$'}, {'%', '^', '&'} };
    float winningsOneLineTop = calculateWinnings(1, 10.0, spinResultsOneLineTop);
    printf("Actual winnings for test 12a: %.2f\n", winningsOneLineTop);
    assert(fabs(winningsOneLineTop - 0.0) < 0.01); // No winnings, bet on middle line only

    // Test 12b: One line bet with matching symbols but not in the middle line
    char spinResultsOneLineBottom[3][3] = { {'%', '^', '&'}, {'@', '#', '$'}, {'7', '7', '7'} };
    float winningsOneLineBottom = calculateWinnings(1, 10.0, spinResultsOneLineBottom);
    printf("Actual winnings for test 12b: %.2f\n", winningsOneLineBottom);
    assert(fabs(winningsOneLineBottom - 0.0) < 0.01); // No winnings, bet on middle line only

    // Test 13a: Two line bet with second and third lines matching
    char spinResultsTwoLinesBottom[3][3] = { {'@', '#', '$'}, {'7', '7', '7'}, {'7', '7', '7'} };
    float winningsTwoLinesBottom = calculateWinnings(2, 10.0, spinResultsTwoLinesBottom);
    printf("Actual winnings for test 13a: %.2f\n", winningsTwoLinesBottom);
    assert(fabs(winningsTwoLinesBottom - (1000.0 * 1.2)) < 0.01); // 1.2x multiplier for two lines, only bottom line considered

    // Test 13b: Two line bet with second and third lines matching
    char spinResultsTwoLinesTop[3][3] = { {'7', '7', '7'}, {'@', '#', '$'}, {'7', '7', '7'} };
    float winningsTwoLinesTop = calculateWinnings(2, 10.0, spinResultsTwoLinesTop);
    printf("Actual winnings for test 13b: %.2f\n", winningsTwoLinesTop);
    assert(fabs(winningsTwoLinesTop - (1000.0 * 1.2)) < 0.01); // 1.2x multiplier for two lines, only top line considered

    // Test 14a: Three line bet with "X" pattern and top line match
    char spinResultsThreeLinesXTop[3][3] = { {'$', '$', '$'}, {'@', '$', '&'}, {'$', '%', '$'} };
    float winningsThreeLinesXTop = calculateWinnings(3, 10.0, spinResultsThreeLinesXTop);
    printf("Actual winnings for test 14a: %.2f\n", winningsThreeLinesXTop);
    assert(fabs(winningsThreeLinesXTop - 100.0) < 0.01); // Only top line considered, "X" pattern will not apply

    // Test 14b: Three line bet with "X" pattern and top line match
    char spinResultsThreeLinesXBottom[3][3] = { {'$', '$', '$'}, {'@', '$', '&'}, {'$', '%', '$'} };
    float winningsThreeLinesXBottom = calculateWinnings(3, 10.0, spinResultsThreeLinesXBottom);
    printf("Actual winnings for test 14b: %.2f\n", winningsThreeLinesXBottom);
    assert(fabs(winningsThreeLinesXBottom - 100.0) < 0.01); // Only top line considered, "X" pattern will not apply

    printf("All tests passed for calculateWinnings.\n");

}

int main() {
    testCalculateWinnings();
    return 0;
}