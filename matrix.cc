/*
  Author:Rick Liu
*/

// Default construction
template <class T>
Matrix<T>::Matrix() {
  rows = 0;
  cols = 0;
  clear();
}

// Constructor
template <class T>
Matrix<T>::Matrix(int r, int c, T t) : rows(r), cols(c) {
  data = new T*[rows];
  for ( int i = 0; i < rows; i++ ) {
    data[i] = new T[cols];
    for ( int j=0; j < rows; j++ ) {
      data[i][j] = t;
    }
  }
}

// Copy constructor
template <class T>
Matrix<T>::Matrix(const Matrix& m) : rows(m.rows), cols(m.cols) {
  data = new T*[rows];
  for ( int i = 0; i < rows; i++ ) {
    data[i] = new T[cols];
    for ( int j = 0; j < cols; j++ ) {
      data[i][j] = m.data[i][j];
    }
  }
}

// Submatrix constructor
template <class T>
Matrix<T>::Matrix(const Matrix<T>& m, 
			    int r1, int c1, int r2, int c2) {
  rows = r2-r1+1;
  cols = c2-c1+1;
  data = new T*[rows];
  for ( int i=0; i<rows; i++ ) {
    data[i] = new T[cols];
    for ( int j=0; j < cols; j++ ) {
      data[i][j] = m.data[r1+i][c1+j];
    }
  }
}

// Destructor
template <class T>
Matrix<T>::~Matrix() {
  clear();
}

// Index operators
template <class T>
T& Matrix<T>::operator()(int i, int j) {
  if ( (i>=0 && i<rows) && (j>=0 && j<cols) ) {
    return data[i][j];
  } else {
    cout<<"Index out of range! Calling "<<i<<" "<<j<<
      " while max index is "<<rows-1<<" "<<cols-1<<"."<<endl;
    return data[0][0];
  }
}

// Copy assigment
template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m) {
  clear();
  rows = m.rows;
  cols = m.cols;
  data = new T*[rows];
  for ( int i = 0; i < rows; i++ ) {
    data[i] = new T[cols];
    for ( int j=0; j < cols; j++ ) {
      data[i][j] = m.data[i][j];
    }
  }
  return *this;
}

// Compound operators
template <class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& x) {
  for ( int i=0; i<rows; i++ ) {
    for ( int j=0; j<rows; j++ ) {
      data[i][j] += x.data[i][j];
    }
  }
  return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& x) {
  for ( int i=0; i<rows; i++ ) {
    for ( int j=0; j<rows; j++ ) {
      data[i][j] -= x.data[i][j];
    }
  }
  return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& x) {
  Matrix result(rows,x.cols,T());
  for ( int i=0; i<rows; i++ ) {
    for ( int j=0; j<cols; j++ ) {
      for ( int k=0; k<cols; k++ ) {
	result.data[i][j] += ( data[i][k] * x.data[k][j] );
      }
    }
  }
  clear();
  cols = x.cols;
  data = new T*[rows];
  for ( int i=0; i<rows; i++ ) {
    data[i] = new T[cols];
    for ( int j=0; j<cols; j++ ) {
      data[i][j] = result.data[i][j];
    }
  }
  return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator*=(T t) {
  for ( int i=0; i<rows; i++ ) {
    for ( int j=0; j<cols; j++ ) {
      data[i][j] *= t;
    }
  }
  return *this;
}

//helpers
template <class T>
void Matrix<T>::print(ostream& out) {
  // check for empty matrix
  if ( rows==0 || cols==0 ) {
    out<<"Empty matrix!"<<endl;
    return ;
  }
  for ( int i=0; i<rows; i++ ) {
    for ( int j=0; j<cols; j++ ) {
      out<<data[i][j]<<'\t';
    }
    out<<endl;
  }
}

template <class T>
int Matrix<T>::ncols() {
  return cols;
}
template <class T>
int Matrix<T>::nrows() {
  return rows;
}

template <class T>
void Matrix<T>::clear() {
 if ( rows != 0 && cols != 0 ) {
    for ( int i = 0; i < rows; i++ ) {
      delete [] data[i];
    }
    delete [] data;
  }
}

// Arithmetic operators are not members
template <class T>
Matrix<T> operator-(const Matrix<T>& m) {
  Matrix<T> result(m);
  result *= -1.0;
  return result;
}
template <class T>
Matrix<T> operator+(const Matrix<T>& l, const Matrix<T>& r) {
  Matrix<T> result(l);
  result += r;
  return result;
}
template <class T>
Matrix<T> operator-(const Matrix<T>& l, const Matrix<T>& r) {
  Matrix<T> result(l);
  result -= r;
  return result;
}
template <class T>
Matrix<T> operator*(const Matrix<T>& l, const Matrix<T>& r) {
  Matrix<T> result(l);
  result *= r;
  return result;
}
template <class T>
Matrix<T> operator*(T t, const Matrix<T>& m) {
  Matrix<T> result(m);
  result *= t;
  return result;
}
template <class T>
Matrix<T> operator*(const Matrix<T>& m, T t) {
  Matrix<T> result(m);
  result *= t;
  return result;
}

// Overload stream insertion operator
template <class T>
ostream& operator<<(ostream& out, const Matrix<T>& x) {
  Matrix<T> temp(x);
  if ( temp.nrows()==0 || temp.ncols()==0 ) {
    out<<"Empty matrix!"<<endl;
    return out;
  }
  for ( int i=0; i<temp.nrows(); i++ ) {
    for ( int j=0; j<temp.ncols(); j++ ) {
      out<<temp(i,j)<<'\t';
    }
    out<<endl;
  }
  return out;
}

