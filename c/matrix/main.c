
#include <stdio.h>
#include "matrix.h"

void init_hm(int rows, int cols, etype hm[rows][cols]);

void print_matrix(int rows, int cols, etype m[rows][cols]);

void rref(int rows, int cols, etype m[rows][cols], int row, int col);

void gauss_elim(int rows, int cols, etype m[rows][cols]);

void invert(int rows, int cols, etype m[rows][cols]);

int in_range(int val, int start, int end) {

	if((val >= start) && (val < end)) {
		return 1;
	} else {
		return 0;
	}

}

int main() {
	

	//rref, transpose, rref, transpose != gauss_elim
	int rows = 4;
	int cols = 4;
	etype hm[rows][cols];

	hm[0][0] = -5;
	hm[0][1] = 0;
	hm[0][2] = -10;
	hm[0][3] = -10;

	hm[1][0] = -2;
	hm[1][1] = 5;
	hm[1][2] = 0;
	hm[1][3] = -5;

	hm[2][0] = -1;
	hm[2][1] = -4;
	hm[2][2] = -10;
	hm[2][3] = -5;

	hm[3][0] = 1;
	hm[3][1] = 1;
	hm[3][2] = -1;
	hm[3][3] = 0;

	printf("initial matrix\n");
	print_matrix(rows, cols, hm);

	gauss_elim(rows, cols, hm);
	printf("matrix after gaussian elimination\n");
	print_matrix(rows, cols, hm);


	return 0;
}

void init_hm(int rows, int cols, etype hm[rows][cols]) {

	for(int i = 0; i < rows; i++ ) { 

		for(int j = 0; j < cols; j++) {
			hm[i][j] = 1.0 / (i + j + 1.0);
		}

	}

}


void print_matrix(int rows, int cols, etype m[rows][cols]) {


	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols - 1; j++) {
			if(m[i][j] >= 0)
			{
				printf(" %f, ", m[i][j]);
			}
			else
			{
				printf("%f, ", m[i][j]);
			}

		}
		printf("%f\n", m[i][cols - 1]);
	}

}

void gauss_elim(int rows, int cols, etype m[rows][cols]) {
	
	//put matrix in rref
	rref(rows, cols, m, 0, 0);
	
	for(int j = cols - 1; j >= 0; j--) {

		for(int i = j - 1; i >= 0; i--) {
			scale_sub_rows(m[i][j], rows, cols, m, i, j);
		}
	}
}

void rref(int rows, int cols, etype m[rows][cols], int row, int col) {


	if((rows > row) && (cols > col)) {
		
		//scale each row if first element is not 0 or 1 by 1 / first element
		for(int i = row; i < rows; i++) {
			if((m[i][col] != 0.0) && (m[i][col] != 1.0)) {
				scale_row(1.0 / m[i][col], rows, cols, m, i);
			}
		}

		//swap the first row with a leading 1 to be the first
		for(int i = row; i < rows; i++) {
			if(m[i][col] != 0.0) {
				if(i > row) {
					swap_rows(rows, cols, m, row, i);
				}
				break;
			}
		}

		//subtract off extra leading ones
		if(rows > row + 1) {

			for(int i = row + 1; i < rows; i++) {
				if(m[i][col] != 0.0) {
					sub_rows(rows, cols, m, i, row);
				}
			}
		}
	
		rref(rows, cols, m, row + 1, col + 1);

	}

}

void invert(int rows, int cols, etype m[rows][cols]) {
		
	if(rows == cols) {

		etype temp[rows][cols * 2];

		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols * 2; j++) {

				if(j < cols) {
					temp[i][j] = m[i][j];
				} else if(j - cols == i) {
					temp[i][j] = 1.0;
				} else {
					temp[i][j] = 0.0;
				}
			}
		}
			
		gauss_elim(rows, cols * 2, temp);
		
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				m[i][j] = temp[i][j + cols];
			}
		}
	}
}

