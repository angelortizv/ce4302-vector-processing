# Vector Processing C Programs

This repository contains three C programs for vector processing:

1. `vector_multiplication`: A program that generates random floating-point vectors and multiplies them element-wise. It measures the execution time and demonstrates basic array operations in C.

2. `vector_multiplication_intrin`: A program that performs the same vector multiplication but utilizes Intel Intrinsics (SSE4.1) for vectorized operations. It also measures the execution time and demonstrates vectorization in C.

3. `vector_comparison`: A program that compares the execution time and performance of the above two programs. It measures the execution time for multiple runs and calculates the average time.

## Instructions for Running

### Prerequisites

To run these programs, you need to have the following:

- A C compiler (e.g., GCC) installed on your system.

### Compiling and Running

Follow these instructions to compile and run each program:

#### `vector_multiplication`

1. Open a terminal or command prompt.

2. Navigate to the directory where `vector_multiplication.c` is located.

3. Compile the program using GCC:

```bash
gcc -o vector_multiplication vector_multiplication.c
```

4. Run the program:

```bash
./vector_multiplication
```

#### `vector_multiplication_intrin`

1. Open a terminal or command prompt.

2. Navigate to the directory where `vector_multiplication_intrin.c` is located.

3. Compile the program using GCC:

```bash
gcc -o vector_multiplication_intrin vector_multiplication_intrin.c -msse4.1
```

4. Run the program:

```bash
./vector_multiplication_intrin
```


#### `vector_comparison`

1. Open a terminal or command prompt.

2. Navigate to the directory where `vector_comparison.c` is located.

3. Compile the program using GCC:

```bash
gcc -o vector_comparison vector_comparison.c -msse4.1
```

4. Run the program:

```bash
./vector_comparison
```

## Results

After running the vector_comparison program, it will display execution stats and calculate the average execution time for both vector_multiplication and vector_multiplication_intrin. You can review these results to compare the performance of the two programs.

Feel free to modify the code and experiment with different vector sizes and parameters to further explore vector processing in C.

## Execution example

![image](https://github.com/angelortizv/ce4302-vector-processing/assets/18412939/4055d630-b4ce-4bb5-bf3c-438db253412d)


