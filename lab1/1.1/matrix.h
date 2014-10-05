#ifndef MATRIX_H
#define MATRIX_H
//#include <vector>
#include <iostream>
#include <stdexcept>
#include "../Vector.h"

template <class T>
class Vec : Vector< T > {
public:
    explicit Vec <T> (std::size_t size  = 0, T data = T()) : Vector< T >(size, data) {}
    const T& operator[](unsigned int i) const throw(std::out_of_range) {
        return this->at( i );
    }
    T& operator[](unsigned int i) throw(std::out_of_range) {
        return this->at( i );
    }    
};

//using namespace std;

template <class T>
class Matrix {
 public:
    //typedef unsigned int index;
    
    class matrix_row : private Vector< T >
    {
    public:
        matrix_row( std::size_t s = 0) : Vector< T >( s ) {}
        using Vector<T>::operator [];
    private:
        friend std::istream& operator>>( std::istream&, Matrix& );
    };
    
    Matrix( );
    Matrix( std::size_t, std::size_t );
    Matrix( const Matrix& );
    Matrix(int size);
    ~Matrix( );
    
    Matrix& operator= ( const Matrix& );
    Matrix operator+ ( const Matrix& ) const;
    Matrix operator* ( const Matrix& ) const;
    Matrix operator* ( int ) const;
    Matrix operator-( const Matrix& ) const;
    Matrix operator-( ) const;
    
    Matrix& transpose( );
    
    matrix_row& operator[]( unsigned int i );
    const matrix_row& operator[]( unsigned int i ) const;
    
    std::size_t rows() const;
    std::size_t cols() const;
    
 protected:
 private:
    Vector< matrix_row >        m_vectors;
    std::size_t                 m_rows;
    std::size_t                 m_cols;
    
    void add_row( );            // Non mandatory help function
    friend std::istream& operator>> ( std::istream&, Matrix& );
};

#include "matrix.hxx"

template <class T>
std::istream& operator>> ( std::istream&, Matrix<T>& );
template <class T>
std::ostream& operator<< ( std::ostream&, Matrix<T>& );
template <class T>
Matrix<T> operator* ( int, const Matrix<T>& );





#endif // MATRIX_H
