//
// Created by leen on 7/5/23.
//

#include <stdio.h>

#define ROWS 4
#define COLS 3

void createMatrix(int matrix[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Enter an element: ");
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int computeSum(int matrix[ROWS][COLS]) {
    int sum = 0;
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

float computeAverage(int matrix[ROWS][COLS]) {
    int sum = computeSum(matrix);
    int totalElements = ROWS * COLS;
    float average = (float)sum / totalElements;
    return average;
}

int findMaximum(int matrix[ROWS][COLS]) {
    int maximum = matrix[0][0];
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (matrix[i][j] > maximum) {
                maximum = matrix[i][j];
            }
        }
    }
    return maximum;
}

int findMinimum(int matrix[ROWS][COLS]) {
    int minimum = matrix[0][0];
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (matrix[i][j] < minimum) {
                minimum = matrix[i][j];
            }
        }
    }
    return minimum;
}

void sortMatrixDescending(int matrix[ROWS][COLS]) {
    int i, j, k;
    int flattenedMatrix[ROWS * COLS];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            flattenedMatrix[i * COLS + j] = matrix[i][j];
        }
    }
    int temp;
    for (i = 0; i < ROWS * COLS; i++) {
        for (j = 0; j < ROWS * COLS - 1; j++) {
            if (flattenedMatrix[j] < flattenedMatrix[j + 1]) {
                temp = flattenedMatrix[j];
                flattenedMatrix[j] = flattenedMatrix[j + 1];
                flattenedMatrix[j + 1] = temp;
            }
        }
    }
    k = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] = flattenedMatrix[k++];
        }
    }
}

int main() {
    int matrix[ROWS][COLS];

    printf("Creating a %dx%d matrix:\n", ROWS, COLS);
    createMatrix(matrix);

    printf("\nMatrix:\n");
    printMatrix(matrix);

    printf("\nSum of all elements: %d\n", computeSum(matrix));
    printf("Average of all elements: %.2f\n", computeAverage(matrix));
    printf("Maximum element: %d\n", findMaximum(matrix));
    printf("Minimum element: %d\n", findMinimum(matrix));

    sortMatrixDescending(matrix);
    printf("\nSorted Matrix (Descending Order):\n");
    printMatrix(matrix);

    return 0;
}

