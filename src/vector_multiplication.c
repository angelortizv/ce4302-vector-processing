/*
 * File: vector_multiplication.c
 * Author: @angelortizv
 * Date: October 18, 2023
 * Description: This C program generates random floating-point vectors, multiplies
 * them element-wise, and measures the execution time. It demonstrates basic array
 * operations and timing in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 6000

void generateRandomVector(float* vector, int size, float scalingFactor) {
    for (int i = 0; i < size; i++) {
        vector[i] = ((float)rand()) / ((float)RAND_MAX) * scalingFactor;
    }
}

void elementWiseMultiplication(const float* vector1, const float* vector2, float* result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = vector1[i] * vector2[i];
    }
}

int main() {
    float a = 2;
    float* vector1 = (float*)malloc(sizeof(float) * N);
    float* vector2 = (float*)malloc(sizeof(float) * N);
    float* vector3 = (float*)malloc(sizeof(float) * N);

    srand(time(NULL));

    generateRandomVector(vector1, N, a);
    generateRandomVector(vector2, N, a);

    clock_t time1, time2;
    time1 = clock();

    elementWiseMultiplication(vector1, vector2, vector3, N);

    time2 = clock();

    printf("Execution stats -------------------------------------\n\n");

    printf("\033[0;31m");
    printf("Time 1 %ld,", time1);   // Print the starting time
    printf(" Time 2 %ld.\n", time2);   // Print the ending time
    printf("\033[0m");

    printf("\033[0;33m");
    printf("Total time %ld.\n", (time2 - time1));   // Print the total execution time
    printf("\033[0m");

    printf("\nExecution stats -------------------------------------\n");

    free(vector1);
    free(vector2);
    free(vector3);

    return 0;
}
