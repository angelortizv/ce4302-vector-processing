/*
 * File: vector_comparison.c
 * Author: @angelortizv
 * Date: October 18, 2023
 * Description: This C program compares the execution time, performance, and data memory alignment
 * of vector multiplication and vector multiplication using Intel Intrinsics (SSE4.1).
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

void vectorMultiplication(const float* vector1, const float* vector2, float* result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = vector1[i] * vector2[i];
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

    clock_t startingTime, endingTime;
    double totalExecutionTime;

    // Measure execution time and print results for vectorMultiplication
    printf("Execution stats for vectorMultiplication ---------------------\n\n");
    totalExecutionTime = 0.0;
    for (int i = 0; i < 5; i++) {
        generateRandomVector(vector1, N, a);
        generateRandomVector(vector2, N, a);

        startingTime = clock();
        vectorMultiplication(vector1, vector2, vector3, N);
        endingTime = clock();

        totalExecutionTime += (double)(endingTime - startingTime) / CLOCKS_PER_SEC;

        printf("Run %d: %lf seconds\n", i + 1, (double)(endingTime - startingTime) / CLOCKS_PER_SEC);
    }
    printf("\nAverage execution time: %lf seconds\n", totalExecutionTime / 5);
    printf("\nExecution stats -----------------------------------------------\n\n");

    // Reset vector3 for the next test
    for (int i = 0; i < N; i++) {
        vector3[i] = 0;
    }

    // Measure execution time and print results for vectorMultiplicationIntrin
    printf("Execution stats for vectorMultiplicationIntrin ----------------\n\n");
    totalExecutionTime = 0.0;
    for (int i = 0; i < 5; i++) {
        generateRandomVector(vector1, N, a);
        generateRandomVector(vector2, N, a);

        startingTime = clock();
        vectorMultiplicationIntrin(vector1, vector2, vector3, N);
        endingTime = clock();

        totalExecutionTime += (double)(endingTime - startingTime) / CLOCKS_PER_SEC;

        printf("Run %d: %lf seconds\n", i + 1, (double)(endingTime - startingTime) / CLOCKS_PER_SEC);
    }
    printf("\nAverage execution time: %lf seconds\n", totalExecutionTime / 5);
    printf("\nExecution stats -----------------------------------------------\n\n");

    free(vector1);
    free(vector2);
    free(vector3);

    return 0;
}
