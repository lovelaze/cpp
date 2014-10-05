#include "matrix.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <algorithm>

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
Matrix::Matrix( std::size_t rows, std::size_t cols) : m_rows(rows), m_cols(cols), m_vectors(Vector<matrix_row>(rows, matrix_row(cols))) {

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


Matrix::Matrix(std::size_t size) : Matrix(size, size) {
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

void Matrix::add_row() {

}

Matrix::matrix_row& Matrix::operator[]( index i ) {
	// TODO errors?
	return m_vectors[i];
}

const Matrix::matrix_row& Matrix::operator[]( index i ) const {
	// TODO errors?
	return m_vectors[i];
}


// Användaren matar in [ 1 2 -3 ; 5 6 7 ]
std::istream& operator>> ( std::istream& is, Matrix& matrix) {
	std::string input;
	std::getline(is, input);
	input.erase(0, 1);
	input.erase(input.length()-1, input.length());

	input.erase( std::remove(input.begin(), input.end(), ' '), input.end() );

	cout << input << endl;

	
	return is;
}

/*
std::ostream& operator<< ( std::ostream&, Matrix& ) {

}*/