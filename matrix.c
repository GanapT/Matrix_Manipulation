#include <stdio.h>
#include <stdlib.h>
#include <matrix.h>

matrix_t* new_matrix(int r, int c) {
    matrix_t* matrix = malloc(sizeof(matrix_t));
    matrix->rows = r;
    matrix->cols = c;
    matrix->data = malloc(r * sizeof(int*));

    for (int i = 0; i < r; i++) {
        matrix->data[i] = malloc(c * sizeof(int));
    }

    return matrix;
}

matrix_t* read_matrix_from_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file\n");
        return NULL;
    }

    int rows, cols;
    fscanf(file, "%d %d", &rows, &cols);

    matrix_t* matrix = new_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%d", &matrix->data[i][j]);
        }
    }

    fclose(file);
    return matrix;
}

void print_matrix(const matrix_t* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

int get_value(const matrix_t* matrix, int row, int col) {
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
        fprintf(stderr, "Error: Invalid matrix indices\n");
        return 0;
    }

    return matrix->data[row][col];
}

void set_value(matrix_t* matrix, int row, int col, int value) {
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
        fprintf(stderr, "Error: Invalid matrix indices\n");
        return;
    }

    matrix->data[row][col] = value;
}

matrix_t* add(const matrix_t* m1, const matrix_t* m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        fprintf(stderr, "Error: Matrices have different dimensions\n");
        return NULL;
    }

    matrix_t* result = new_matrix(m1->rows, m1->cols);

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            result->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }

    return result;
}

matrix_t* transpose(const matrix_t* matrix) {
    matrix_t* result = new_matrix(matrix->cols, matrix->rows);

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->data[j][i] = matrix->data[i][j];
        }
    }

    return result;
}
