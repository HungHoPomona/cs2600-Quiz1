#include <stdio.h>
#include <stdbool.h> // Include for bool type
#include "LoShuMagicSquare.h"

int main() {
    int validSquare[3][3] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };

    int invalidSquare[3][3] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 5}
    };

    printf("Testing valid square: %s\n", isLoShuMagicSquare(validSquare) ? "True" : "False");
    printf("Testing invalid square: %s\n", isLoShuMagicSquare(invalidSquare) ? "True" : "False");

    return 0;
}
