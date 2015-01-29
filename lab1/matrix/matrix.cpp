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

Matrix::Matrix( const Matrix&& ) {
	
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


Matrix& Matrix::operator= ( const Matrix& rhs) {

	std::cerr << "assignment operator" << std::endl;

	if (&rhs != this) {
		m_rows = rhs.m_rows;
		m_cols = rhs.m_cols;
		m_vectors = rhs.m_vectors;
	}
	
	return *this;
}

/*

Matrix& Matrix::operator= ( const Matrix&& ) {

}

Matrix Matrix::operator+ ( const Matrix& ) const {

}

Matrix Matrix::operator* ( const Matrix& ) const {
	
}

Matrix Matrix::operator* ( int ) const {
	
}

Matrix Matrix::operator-( const Matrix& ) const {
	
}

Matrix Matrix::operator-( ) const {
	
}

Matrix& Matrix::transpose( ) {
}


*/

void Matrix::add_row(matrix_row row) {
	if (row.size() != m_cols) {
		throw std::invalid_argument("the row must have correct dimension");
	}
	m_vectors.push_back(row);
	++m_rows;

}

Matrix::matrix_row& Matrix::operator[]( const index i ) {
	// TODO errors?
	return m_vectors[i];
}

const Matrix::matrix_row& Matrix::operator[]( const index i ) const {
	// TODO errors?
	return m_vectors[i];
}


// Användaren matar in [ 1 2 -3 ; 5 6 7 ]
std::istream& operator>> ( std::istream& is, Matrix& matrix) {
	
	std::string input;
	std::getline(is, input);

	Matrix::matrix_row temp_row;

	input.erase(0, 1);
	input.pop_back();

	size_t pos = 0;
	std::string token;

	while (token != input){
		token = input.substr(0, input.find_first_of(";"));
		input = input.substr(input.find_first_of(";") + 1);


		stringstream ss(token);
		int n;
		while (ss >> n) {
			temp_row.push_back(n);
		}
		matrix.add_row(temp_row);
		temp_row.clear();

	}





	
	/*
	input.erase(0, 1);
	input.erase(input.length()-1, input.length());

	

	for (char & c : input) {
		if (isdigit(c)) {
			temp_row.push_back(std::atoi(&c));
		}

		if (c == ';') {
			matrix.add_row(temp_row);
			temp_row.clear();
		}
	}

	*/
	//std::cerr << input << std::endl;

	
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