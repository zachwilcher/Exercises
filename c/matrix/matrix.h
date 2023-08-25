#ifndef MATRIX_H
#define MATRIX_H
typedef double etype;

void scale_row(etype scalar, int rows, int cols, etype m[rows][cols], int row);

void scale_col(etype scalar, int rows, int cols, etype m[rows][cols], int col);

void add_rows(int rows, int cols, etype m[rows][cols], int row0, int row);

void sub_rows(int rows, int cols, etype m[rows][cols], int row0, int row);

void add_cols(int rows, int cols, etype m[rows][cols], int col0, int col);

void sub_cols(int rows, int cols, etype m[rows][cols], int col0, int col);

void swap_rows(int rows, int cols, etype m[rows][cols], int row0, int row);

void swap_cols(int rows, int cols, etype m[rows][cols], int col0, int col);

void scale_add_rows(etype scalar, int rows, int cols, etype m[rows][cols], int row0, int row);

void scale_sub_rows(etype scalar, int rows, int cols, etype m[rows][cols], int row0, int row);

void scale_add_cols(etype scalar, int rows, int cols, etype m[rows][cols], int col0, int col);

void scale_sub_cols(etype scalar, int rows, int cols, etype m[rows][cols], int col0, int col);

void scale_matrix(etype scalar, int rows, int cols, etype m[rows][cols]);

void add_matricies(int rows, int cols, etype m0[rows][cols], etype m[rows][cols]);

void sub_matricies(int rows, int cols, etype m0[rows][cols], etype m[rows][cols]);

void mult_matricies(int lrows, int lcols, etype l[lrows][lcols], int rrows, int rcols, etype r[rrows][rcols], etype result[lrows][lcols]);

void transpose(int rows, int cols, etype[rows][cols], etype[cols][rows]);

#endif
