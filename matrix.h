/*
  Author: Rick
  Do not modify
*/
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Matrix {
 public:
  // constructors and destructors to be implemented
  Matrix();
  Matrix(int r, int c, T d);
  Matrix(const Matrix& m);
  // Sub-matrix contructor
  Matrix(const Matrix& m, int r1, int c1, int r2, int c2);
  ~Matrix();

  // Index operators
  T& operator() (int i, int j);

  // Copy assignment operator
  Matrix& operator=(const Matrix& m);

  // Compound operators
  Matrix& operator+=(const Matrix& x);
  Matrix& operator-=(const Matrix& x);
  Matrix& operator*=(const Matrix& x);
  Matrix& operator*=(T t);

  // helpers
  void print(ostream& out);
  int ncols();       // return the number of columns
  int nrows();       // return the number of rows
  void clear();      // helper function called by destructor ~Matrix()

 private:
  int rows, cols;    // number of rows and columns
  T** data;          // 2D pointer to hold data
};

// Arithmetic operators 
template <class T>
Matrix<T> operator-(const Matrix<T>& m);
template <class T>
Matrix<T> operator+(const Matrix<T>& l, const Matrix<T>& r);
template <class T>
Matrix<T> operator-(const Matrix<T>& l, const Matrix<T>& r);
template <class T>
Matrix<T> operator*(const Matrix<T>& l, const Matrix<T>& r);
template <class T>
Matrix<T> operator*(T t, const Matrix<T>& m);
template <class T>
Matrix<T> operator*(const Matrix<T>& m, T t);

// Overload stream insertion operator
template <class T>
ostream& operator<<(ostream& out, const Matrix<T>& x);

#include "matrix.cc"
#endif
