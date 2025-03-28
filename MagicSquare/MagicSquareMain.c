#include <stdio.h>
#include <stdbool.h> // Include for bool type
#include <stdlib.h>  // For rand() and srand()
#include <time.h>    // For seeding random number generator
#include "LoShuMagicSquare.h"

// Function to generate a random 3x3 square with unique numbers from 1-9
void generateRandomSquare(int square[3][3]) {
    int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 8; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            square[i][j] = numbers[index++];
        }
    }
}

// Function to print a 3x3 square in the specified format
void printSquare(int square[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("[%d %d %d]\n", square[i][0], square[i][1], square[i][2]);
    }
}

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

    printf("Valid square:\n");
    printSquare(validSquare);
    printf("\nTesting valid square: %s\n", isLoShuMagicSquare(validSquare) ? "True" : "False");

    printf("\nInvalid square:\n");
    printSquare(invalidSquare);
    printf("\nTesting invalid square: %s\n", isLoShuMagicSquare(invalidSquare) ? "True" : "False");

    // New functionality to generate and test random squares
    srand(time(NULL)); // Seed the random number generator

    printf("\n");

    int square[3][3];
    int count = 0;

    do {
        generateRandomSquare(square);
        count++;
    } while (!isLoShuMagicSquare(square));

    printf("\nTotal number of squares generated and tested: %d\n", count);
    printf("Successful Lo Shu Magic Square:\n");
    printSquare(square);

    return 0;
}
