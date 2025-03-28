#include "LoShuMagicSquare.h"
#include <stdbool.h> // Include for bool type

bool isLoShuMagicSquare(int square[3][3]) {
    int rowSum, colSum, diagSum1 = 0, diagSum2 = 0;
    bool seen[10] = {false}; // To track numbers 1-9

    // Check if all numbers are 1-9 and unique
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = square[i][j];
            if (num < 1 || num > 9 || seen[num]) {
                return false;
            }
            seen[num] = true;
        }
    }

    // Check row sums, column sums, and diagonal sums
    for (int i = 0; i < 3; i++) {
        rowSum = colSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if (rowSum != 15 || colSum != 15) {
            return false;
        }
        diagSum1 += square[i][i];
        diagSum2 += square[i][2 - i];
    }

    return diagSum1 == 15 && diagSum2 == 15;
}
