#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: Two file names must be provided\n");
        return 1;
    }

    char* filename1 = argv[1];
    char* filename2 = argv[2];

    matrix_t* matrix1 = read_matrix_from_file(filename1);
    if (matrix1 == NULL) {
        fprintf(stderr, "Error: Failed to read matrix from file\n");
        return 1;
    }

    matrix_t* matrix2 = read_matrix_from_file(filename2);
    if (matrix2 == NULL) {
        fprintf(stderr, "Error: Failed to read matrix from file\n");
        return 1;
    }

    printf("Matrix 1:\n");
    print_matrix(matrix1);

    printf("\nMatrix 2:\n");
    print_matrix(matrix2);

    matrix_t* matrixSum = add(matrix1, matrix2);
    if (matrixSum == NULL) {
        fprintf(stderr, "Error: Matrix addition failed\n");
        return 1;
    }

    printf("\nSum of Matrix 1 and Matrix 2:\n");
    print_matrix(matrixSum);

    matrix_t* matrixTranspose = transpose(matrix1);
    if (matrixTranspose == NULL) {
        fprintf(stderr, "Error: Matrix transpose failed\n");
        return 1;
    }

    printf("\nTranspose of Matrix 1:\n");
    print_matrix(matrixTranspose);

    // Free dynamically allocated memory
    for (int i = 0; i < matrix1->rows; i++) {
        free(matrix1->data[i]);
    }
    free(matrix1->data);
    free(matrix1);

    for (int i = 0; i < matrix2->rows; i++) {
        free(matrix2->data[i]);
    }
    free(matrix2->data);
    free(matrix2);

    for (int i = 0; i < matrixSum->rows; i++) {
        free(matrixSum->data[i]);
    }
    free(matrixSum->data);
    free(matrixSum);

    for (int i = 0; i < matrixTranspose->rows; i++) {
        free(matrixTranspose->data[i]);
    }
    free(matrixTranspose->data);
    free(matrixTranspose);

    return 0;
}
