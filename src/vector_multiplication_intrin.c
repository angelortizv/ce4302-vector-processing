/*
 * File: vector_multiplication_intrin.c
 * Author: @angelortizv
 * Date: October 18, 2023
 * Description: This C program generates random floating-point vectors, multiplies
 * them element-wise using Intel Intrinsics, and measures the execution time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <immintrin.h>

#define N 6000

void generateRandomVector(float* vector, int size, float scalingFactor) {
    for (int i = 0; i < size; i++) {
        vector[i] = ((float)rand()) / ((float)RAND_MAX) * scalingFactor;
    }
}

void vectorMultiplicationIntrin(const float* vector1, const float* vector2, float* result, int size) {
    for (int i = 0; i < size; i += 4) {
        __m128 vec1 = _mm_loadu_ps(&vector1[i]);
        __m128 vec2 = _mm_loadu_ps(&vector2[i]);
        __m128 res = _mm_dp_ps(vec1, vec2, 0xFF);
        _mm_storeu_ps(&result[i], res);
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

    clock_t startingTime, endingTime;
    startingTime = clock();

    vectorMultiplicationIntrin(vector1, vector2, vector3, N);

    endingTime = clock();

    printf("Execution stats -------------------------------------\n\n");

    printf("\033[0;31m");
    printf("Time 1 %ld,", startingTime);   // Print the starting time
    printf(" Time 2 %ld.\n", endingTime);   // Print the ending time
    printf("\033[0m");

    printf("\033[0;33m");
    printf("Total time %ld.\n", (endingTime - startingTime));   // Print the total execution time
    printf("\033[0m");

    printf("\nExecution stats -------------------------------------\n");

    free(vector1);
    free(vector2);
    free(vector3);

    return 0;
}
