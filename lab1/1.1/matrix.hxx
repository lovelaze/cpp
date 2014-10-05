template <class T>
Matrix<T>::Matrix() {

}

template <class T>
Matrix<T>::~Matrix() {
	
}

template <class T>
Matrix<T>::Matrix( std::size_t, std::size_t ) {

}

template <class T>
Matrix<T>::Matrix( const Matrix& ) {

}

template <class T>
Matrix<T>::Matrix(int size) {

}

template <class T>
Matrix<T>& Matrix<T>::operator= ( const Matrix<T>& ) {

}

template <class T>
Matrix<T> Matrix<T>::operator+ ( const Matrix<T>& ) const {

}

template <class T>
Matrix<T> Matrix<T>::operator* ( const Matrix<T>& ) const {
	
}

template <class T>
Matrix<T> Matrix<T>::operator* ( int ) const {
	
}

template <class T>
Matrix<T> Matrix<T>::operator-( const Matrix<T>& ) const {
	
}

template <class T>
Matrix<T> Matrix<T>::operator-( ) const {
	
}

template <class T>
Matrix<T>& Matrix<T>::transpose( ) {
	
}


template <class T>
typename Matrix<T>::matrix_row& Matrix<T>::operator[]( unsigned int i ) {

}

template <class T>
const typename Matrix<T>::matrix_row& Matrix<T>::operator[]( unsigned int i ) const {

}
