
#include <cstddef>
#include <vector>

template <typename T>
class Matrix {

	public:
		
		Matrix(std::size_t rows, std::size_t cols);

		~Matrix();

		//copy ctor
		Matrix(Matrix&);

		//move ctor
		Matrix(Matrix&&);
	
		//move = operator
		Matrix& operator=(Matrix&&);
	
		//elementwise addition
		Matrix&& operator+(Matrix&);

		//matrix mult
		Matrix&& operator*(Matrix&);

		//scale matrix
		Matrix&& operator*(T&);

		//get element
		T& at(std::size_t row, std::size_t col) const;

		//elem row operations and col versions of them
		void scale_col(T& scalar, std::size_t col);
		void swap_cols(std::size_t col0, std::size_t col);
		void scale_row(T& scalar, std::size_t row);
		void swap_rows(std::size_t row0, std::size_t row);
		void add_row_multiple(T& scalar, std::size_t row0, std::size_t row);
		void add_col_multiple(T& scalar, std::size_t col0, std::size_t col);
		
	private:
		std::size_t rows;
		std::size_t cols;
		//1D array for elements
		T contents[];
};



