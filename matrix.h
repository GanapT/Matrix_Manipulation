typedef struct {
    int rows;
    int cols;
    int** data;
} matrix_t;

matrix_t* new_matrix(int r, int c);
matrix_t* read_matrix_from_file(char* filename);
void print_matrix(const matrix_t* matrix);
int get_value(const matrix_t* matrix, int row, int col);
void set_value(matrix_t* matrix, int row, int col, int value);
matrix_t* add(const matrix_t* m1, const matrix_t* m2);
matrix_t* transpose(const matrix_t* matrix);
