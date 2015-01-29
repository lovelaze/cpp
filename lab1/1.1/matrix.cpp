#include "matrix.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cstdlib>

void Matrix::print() {

	for (Matrix::index i = 0; i < m_rows; ++i) {
		for (Matrix::index j = 0; j < m_cols; ++j) {
			std::cerr << m_vectors[i][j] << ", ";
		}
		std::cerr << std::endl;
	}

}

Matrix::Matrix() : Matrix(0,0) {
	std::cerr << "default constructor" << std::endl;
}

Matrix::~Matrix() {
	
}


/*
	SIZE INIT
*/
Matrix::Matrix( const std::size_t rows, const std::size_t cols) : m_rows(rows), m_cols(cols), m_vectors(Vector<matrix_row>(rows, matrix_row(cols))) {

	std::cerr << "size constructor" << std::endl;
	/*
		TODO:
		throw some errors, like initiating 0 rows with cols != 0
	*/
}

Matrix::Matrix( const Matrix& rhs) : m_rows(rhs.m_rows), m_cols(rhs.m_cols), m_vectors(Vector<matrix_row>(rhs.m_rows, matrix_row(rhs.m_cols))) {

	std::cerr << "copy constructor" << std::endl;
	for (std::size_t i = 0; i < m_rows; ++i) {
		m_vectors[i] = rhs.m_vectors[i];
	}
}

Matrix::Matrix(const std::size_t size) : Matrix(size, size) {
	for (index i = 0; i < size; ++i) {
		m_vectors[i][i] = 1;
	}
}

std::size_t Matrix::rows() const {
	return m_rows;
}

std::size_t Matrix::cols() const {
	return m_cols;
}

void Matrix::check_dimensions(const Matrix & rhs) const {
	if (rows() != rhs.rows() || cols() != rhs.cols()) {
		throw std::invalid_argument("Must have the same dimensions");
	}

}


Matrix& Matrix::operator= ( const Matrix& rhs) {
	std::cerr << "assignment operator" << std::endl;

	if (&rhs != this) {
		m_rows = rhs.m_rows;
		m_cols = rhs.m_cols;
		m_vectors = rhs.m_vectors;
	}
	
	return *this;
}


Matrix Matrix::operator+ ( const Matrix& rhs) const {

	check_dimensions(rhs);
	
	Matrix tmp(*this);

	for (size_t i = 0; i < tmp.rows(); ++i) {
		for (size_t j = 0; j < tmp.cols(); ++j) {
			tmp[i][j] += rhs[i][j];
		}
	}
	
	return tmp;
}



Matrix Matrix::operator* ( const Matrix& matrix) const {
	Matrix tmp(m_rows, matrix.cols());

	for (std::size_t i = 0; i < m_rows; ++i) {

		for (std::size_t j = 0; j < matrix.cols(); ++j) {
			int sum = 0;

			for (std::size_t k = 0; k < matrix.rows(); ++k) {
			    
				sum += (*this)[i][k] * matrix[k][j];
			}
			tmp[i][j] = sum;
		}
	}


	return tmp;
}



Matrix Matrix::operator* (const int x) const {

	Matrix tmp(*this);


	for (size_t i = 0; i < tmp.rows(); ++i) {
		for (size_t j = 0; j < tmp.cols(); ++j) {
			tmp[i][j] *= x;
		}
	}

	return tmp;
}



Matrix Matrix::operator-( const Matrix& rhs) const {
    
	check_dimensions(rhs);
    
	Matrix tmp(*this);

	for (size_t i = 0; i < tmp.rows(); ++i) {
		for (size_t j = 0; j < tmp.cols(); ++j) {
			tmp[i][j] -= rhs[i][j];
		}
	}
	
	return tmp;
	
}


Matrix Matrix::operator-(const int x ) const {
	Matrix tmp(*this);


	for (size_t i = 0; i < tmp.rows(); ++i) {
		for (size_t j = 0; j < tmp.cols(); ++j) {
			tmp[i][j] -= x;
		}
	}

	return tmp;
}

Matrix Matrix::operator+(const int x ) const {
	Matrix tmp(*this);


	for (size_t i = 0; i < tmp.rows(); ++i) {
		for (size_t j = 0; j < tmp.cols(); ++j) {
			tmp[i][j] += x;
		}
	}

	return tmp;
}



Matrix & Matrix::transpose() {

	Vector<matrix_row> tmp(m_cols, matrix_row(m_rows));

	for (size_t i = 0; i < m_rows; ++i) {
		for (size_t j = 0; j < m_cols; ++j) {
			tmp[j][i] = (*this)[i][j];
		}
	}

	int x = m_rows;
	m_rows = m_cols;
	m_cols = x;
	m_vectors = tmp;	

	return *this;

}




void Matrix::add_row(matrix_row row) {
	if (row.size() != m_cols && m_cols != 0) {
		throw std::invalid_argument("the row must have correct dimension");
	}

	m_vectors.push_back(row);
	++m_rows;

	if (m_cols == 0) {
		m_cols = row.size();
	}

}

Matrix::matrix_row& Matrix::operator[]( const index i ) {
	// TODO errors?
	return m_vectors[i];
}

const Matrix::matrix_row& Matrix::operator[]( const index i ) const {
	// TODO errors?
	return m_vectors[i];
}


// Användaren matar in [ 123 2 -3 ; 5 6 7 ]
std::istream& operator>> ( std::istream& is, Matrix& matrix) {

	std::string input;
	std::getline(is, input);

	Matrix::matrix_row row;

	std::size_t prev;
	std::size_t next = prev = input.find(" ");

	while ((next = input.find(" ", next + 1)) != std::string::npos) {

		std::string temp = input.substr(prev+1, next - prev - 1);
		prev = next;

		if (temp == ";") {
			matrix.add_row(row);
			row.clear();
		} else {
			row.push_back(std::stoi(temp));
		}
	}

	if (row.size() != 0) {
		matrix.add_row(row);
	}
	
	return is;
}


std::ostream& operator<< ( std::ostream& os, Matrix& matrix) {

	if (matrix.m_rows <= 0) {
		os << "[ ]";
		return os;
	}

	os << "[ ";
		
	for (Matrix::index i = 0; i < matrix.m_rows - 1; ++i) {
		for (Matrix::index j = 0; j < matrix.m_cols; ++j) {
			os << matrix.m_vectors[i][j] << " ";
		}
		os << std::endl << "; ";
	}

	for (Matrix::index j = 0; j < matrix.m_cols; ++j) {
		os << matrix.m_vectors[matrix.m_rows-1][j] << " ";
	}

	os << "]";
	return os;
}