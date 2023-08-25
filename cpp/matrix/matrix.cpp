#include "matrix.h"
#include <stdexcept>


template<typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols) : rows{rows}, cols{cols}
{
	this->contents = new T[rows * cols];
}

template<typename T>
Matrix<T>::~Matrix() 
{
	delete[] this->contents;
}

template<typename T>
Matrix<T>::Matrix(Matrix& other) :
	rows{other.rows},
	cols{other.cols}
{
	for(std::size_t i = 0; i < (rows * cols); i++)
	{
		this->contents[i] = other->contents[i];
	}
}

template<typename T>
Matrix<T>::Matrix(Matrix&& other) :
	rows{other.rows},
	cols{other.cols},
	contents{std::move(other.contents)}
{}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other) 
{
	this->rows = other.rows;
	this->cols = other.cols;
	this->contents = std::move(other.contents);
}

template<typename T>
Matrix<T>&& Matrix<T>::operator+(Matrix& other)
{

	if((other.rows == this->rows) && (other.cols == this->cols)) {
		Matrix<T> result(rows, cols);
		for(std::size_t i = 0; i < (rows * cols); i++) {
			result.contents[i] = this->contents[i] + other.contents[i];
		}
		return result;
	} else {
		throw std::domain_error("Dimension mismatch");
	}
}

template<typename T>
Matrix<T>&& Matrix<T>::operator*(Matrix& other)
{
	//matrix mult is only defined if the number of cols in the left matrix is equal to the number of rows in the right...
	if(this->cols == other.rows) {
		Matrix<T> result(this->rows, other.cols);
		for(std::size_t row = 0; row < this->rows; row++) {
			for(std::size_t col = 0; col < other.cols; col++) {
				for(std::size_t i = 0; i < this->cols; i++) {
					//dot product of this's row and other's col
					result.at(row, col) += this->at(row, col + i) * other.at(row + i, col);
				}
			}
		}
	} else {
		throw std::domain_error("Dimension mismatch");
	}
}

template<typename T>
Matrix<T>&& Matrix<T>::operator*(T& scalar)
{
	Matrix<T> result(rows, cols);
	for(std::size_t i = 0; i < (rows * cols); i++) {
		result.contents[i] = this->contents[i] * scalar;
	}
	return result;
}


template<typename T>
T& Matrix<T>::at(std::size_t row, std::size_t col) const
{
	if((row < rows) && (col < cols)) {
		return this->contents[row * cols + col];
	} else {
		throw std::out_of_range("Attempt to access undefined element.");
	}
}

template<typename T>
void Matrix<T>::scale_col(T& scalar, std::size_t col)
{
	if(col < cols) {
		for(std::size_t row = 0; row < rows; row++) {
			this->at(row, col) *= scalar;
		}
	} else {
		throw std::out_of_range("Attempt to modify undefined elements.");
	}
}

template<typename T>
void Matrix<T>::scale_row(T& scalar, std::size_t row)
{
	if(row < rows) {
		for(std::size_t col = 0; col < cols; col++) {
			this->at(row, col) *= scalar;
		}
	} else {
		throw std::out_of_range("Attempt to modify undefined elements.");
	}
}

template<typename T>
void Matrix<T>::swap_cols(std::size_t col0, std::size_t col)
{
	if((col0 < cols) && (col < cols)) {
		for(std::size_t row = 0; row < rows; row++) {
			std::swap(this->at(row, col0), this->at(row, col));
		}
	} else {
		throw std::out_of_range("Attempt to modify undefined elements.");
	}
}

template<typename T>
void Matrix<T>::swap_rows(std::size_t row0, std::size_t row)
{
	if((row0 < rows) && (row < rows)) {
		for(std::size_t col = 0; col < cols; col++) {
			std::swap(this->at(row0, col), this->at(row, col));
		}
	} else {
		throw std::out_of_range("Attempt to modify undefined elements.");
	}
}

template<typename T>
void Matrix<T>::add_row_multiple(T& scalar, std::size_t row0, std::size_t row)
{
	if((row0 < rows) && (row < rows)) {
		for(std::size_t col = 0; col < cols; col++) {
			this->at(row, col) += scalar * this->at(row0, col);
		}
	} else {
		throw std::out_of_range("Attempt to modify undefined elements.");
	}
}
template<typename T>
void Matrix<T>::add_col_multiple(T& scalar, std::size_t col0, std::size_t col)
{
	if((col0 < cols) && (col < cols)) {
		for(std::size_t row = 0; row < rows; row++) {
			this->at(row, col) += scalar * this->at(row, col0);
		}
	} else {
		throw std::out_of_range("Attempt to modify undefined elements.");
	}
}






