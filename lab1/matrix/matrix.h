#ifndef MATRIX_H
#define MATRIX_H
#include "Vector.h"

#define private public


//using namespace std;

class Matrix {
 public:
    typedef std::size_t index; // onödigt?

    class matrix_row : private Vector< int >
    {
    public:
        matrix_row( std::size_t s = 0) : Vector< int >( s ) {}
        using Vector<int>::operator [];
    private:
        friend std::istream& operator>>( std::istream&, Matrix& );
    };


    
    Matrix( ); // default
    Matrix( const std::size_t, const std::size_t ); // size constructor
    Matrix( const Matrix& ); // copy constructor
    Matrix( const Matrix&& ); // move constructor
    explicit Matrix( const std::size_t ); // 
    ~Matrix( ); // deconstructor
    
    Matrix& operator= ( const Matrix& ); // assignment operator
    Matrix& operator= ( const Matrix&& ); // move operator
    Matrix operator+ ( const Matrix& ) const;
    Matrix operator* ( const Matrix& ) const;
    Matrix operator* ( int ) const;
    Matrix operator-( const Matrix& ) const;
    Matrix operator-( ) const;
    
    Matrix& transpose( ); // transpose function
    
    matrix_row& operator[]( const index i );
    const matrix_row& operator[]( const index i ) const;
    
    std::size_t rows() const;
    std::size_t cols() const;

public:
    void print();
    
 protected: // ?

 private:
    std::size_t                 m_rows;
    std::size_t                 m_cols;
    Vector< matrix_row >        m_vectors;
    
    void add_row( matrix_row );            // Non mandatory help function
    friend std::istream& operator>> ( std::istream&, Matrix& );
};

std::istream& operator>> ( std::istream&, Matrix& );
std::ostream& operator<< ( std::ostream&, Matrix& );
Matrix operator* ( int, const Matrix& );

#endif // MATRIX_H
