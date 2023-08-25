#include "matrix.h"

void scale_row(etype scalar, int rows, int cols, etype m[rows][cols], int row) {
	for(int j = 0; j < cols; j++) {
		m[row][j] *= scalar;
	}
}

void scale_col(etype scalar, int rows, int cols, etype m[rows][cols], int col){
	for(int i = 0; i < cols; i++) {
		m[i][col] *= scalar;
	}
}

void add_rows(int rows, int cols, etype m[rows][cols], int row0, int row){
	for(int j = 0; j < cols; j++) {
		m[row0][j] += m[row][j];
	}
}

void sub_rows(int rows, int cols, etype m[rows][cols], int row0, int row){
	for(int j = 0; j < cols; j++) {
		m[row0][j] -= m[row][j];
	}
}

void add_cols(int rows, int cols, etype m[rows][cols], int col0, int col){
	for(int i = 0; i < cols; i++) {
		m[i][col0] += m[i][col];
	}
}

void sub_cols(int rows, int cols, etype m[rows][cols], int col0, int col){
	for(int i = 0; i < cols; i++) {
		m[i][col0] -= m[i][col];
	}
}

void swap_rows(int rows, int cols, etype m[rows][cols], int row0, int row){

	for(int j = 0; j < cols; j++) {
			etype temp = m[row0][j];
			m[row0][j] = m[row][j];
			m[row][j] = temp;
	}
}

void swap_cols(int rows, int cols, etype m[rows][cols], int col0, int col) {
	for(int i = 0; i < rows; i++) {
			etype temp = m[i][col0];
			m[i][col0] = m[i][col];
			m[i][col] = temp;
	}

}

void scale_add_rows(etype scalar, int rows, int cols, etype m[rows][cols], int row0, int row){

	for(int j = 0; j < cols; j++) {
		m[row0][j] += (m[row][j] * scalar);
	}

}

void scale_sub_rows(etype scalar, int rows, int cols, etype m[rows][cols], int row0, int row){
	for(int j = 0; j < cols; j++) {
		m[row0][j] -= (m[row][j] * scalar);
	}
}

void scale_add_cols(etype scalar, int rows, int cols, etype m[rows][cols], int col0, int col){
	for(int i = 0; i < rows; i++) {
		m[i][col0] += (m[i][col] * scalar);
	}
}

void scale_sub_cols(etype scalar, int rows, int cols, etype m[rows][cols], int col0, int col){
	for(int i = 0; i < rows; i++) {
		m[i][col0] -= (m[i][col] * scalar);
	}
}

void scale_matrix(etype scalar, int rows, int cols, etype m[rows][cols]) {

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			m[i][j] *= scalar;
		}
	}
}

void add_matricies(int rows, int cols, etype m0[rows][cols], etype m[rows][cols]){
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			m0[i][j] += m[i][j];
		}
	}
}

void sub_matricies(int rows, int cols, etype m0[rows][cols], etype m[rows][cols]){
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			m0[i][j] -= m[i][j];
		}
	}
}

void mult_matricies(int lrows, int lcols, etype l[lrows][lcols], int rrows, int rcols, etype r[rrows][rcols], etype result[lrows][rcols]){
	
	if(lcols == rrows) {
	
		for(int i = 0; i < lrows; i++) {
			for(int j = 0; j < rcols; j++) {
				result[i][j] = 0.0;
				for(int k = 0; k < lcols; k++) {
					result[i][j] += l[i][k] * r[k][j];
				}
			}
		}
	}
}


void transpose(int rows, int cols, etype m[rows][cols], etype result[cols][rows]) {

		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				
				result[j][i] = m[i][j];
				
			}
		}
}
