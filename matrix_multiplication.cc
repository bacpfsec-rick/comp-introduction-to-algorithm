/*
   Author : Rick Liu
    Date  : 20150202
   Source : ItA P75~81
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "matrix.h"
using namespace std;
#define ROW 4
#define COL 4

Matrix<int> brute_force(Matrix<int>& A,Matrix<int>& B) {
  Matrix<int> result(A.ncols(),B.nrows(),0);
  for ( int i=0; i<result.ncols(); ++i ) {
    for ( int j=0; j<result.nrows(); ++j ) {
      for ( int k=0; k<A.nrows(); ++k ) {
	result(i,j) += A(i,k)*B(k,j);
      }
    }
  }
  return result;
}

// Only works on 2^n matrix
Matrix<int> simple_square_dc(Matrix<int>& A,Matrix<int> B) {
  int n = A.nrows();
  Matrix<int> C(n,n,0);
  if ( n==1 ) {
    C = A*B;
  } else {
    // Sub matrix Aij Bij
    Matrix<int> A11(A,0,0,n/2-1,n/2-1);
    Matrix<int> A12(A,0,n/2,n/2-1,n-1);
    Matrix<int> A21(A,n/2,0,n-1,n/2-1);
    Matrix<int> A22(A,n/2,n/2,n-1,n-1);
    Matrix<int> B11(B,0,0,n/2-1,n/2-1);
    Matrix<int> B12(B,0,n/2,n/2-1,n-1);
    Matrix<int> B21(B,n/2,0,n-1,n/2-1);
    Matrix<int> B22(B,n/2,n/2,n-1,n-1);
    // Sub matrix Cij
    Matrix<int> C11(simple_square_dc(A11,B11)+simple_square_dc(A12,B21));
    Matrix<int> C12(simple_square_dc(A11,B12)+simple_square_dc(A12,B22));
    Matrix<int> C21(simple_square_dc(A21,B11)+simple_square_dc(A22,B21));
    Matrix<int> C22(simple_square_dc(A21,B12)+simple_square_dc(A22,B22));
    // Copy
    for ( int i=0; i<n; ++i ) {
      for ( int j=0; j<n; ++j ) {
	C(i,j) = ( i<n/2 ) ? ( j<n/2 ? C11(i,j) : C12(i,j-n/2) ) : 
	  ( j<n/2 ? C21(i-n/2,j) : C22(i-n/2,j-n/2) );
      }
    }
  }
  return C;
}

// Only works on 2^n matrix
Matrix<int> strassen_method(Matrix<int>& A,Matrix<int> B) {
  int n = A.nrows();
  Matrix<int> C(n,n,0);
  if ( n==1 ) {
    C = A*B;
  } else {
    // Sub matrix Aij Bij
    Matrix<int> A11(A,0,0,n/2-1,n/2-1);
    Matrix<int> A12(A,0,n/2,n/2-1,n-1);
    Matrix<int> A21(A,n/2,0,n-1,n/2-1);
    Matrix<int> A22(A,n/2,n/2,n-1,n-1);
    Matrix<int> B11(B,0,0,n/2-1,n/2-1);
    Matrix<int> B12(B,0,n/2,n/2-1,n-1);
    Matrix<int> B21(B,n/2,0,n-1,n/2-1);
    Matrix<int> B22(B,n/2,n/2,n-1,n-1);
    // Calculating Si
    Matrix<int> S1(B12-B22);
    Matrix<int> S2(A11+A12);
    Matrix<int> S3(A21+A22);
    Matrix<int> S4(B21-B11);
    Matrix<int> S5(A11+A22);
    Matrix<int> S6(B11+B22);
    Matrix<int> S7(A12-A22);
    Matrix<int> S8(B21+B22);
    Matrix<int> S9(A11-A21);
    Matrix<int> S10(B11+B12);
    // Calculating Pi
    Matrix<int> P1(strassen_method(A11,S1));
    Matrix<int> P2(strassen_method(S2,B22));
    Matrix<int> P3(strassen_method(S3,B11));
    Matrix<int> P4(strassen_method(A22,S4));
    Matrix<int> P5(strassen_method(S5,S6));
    Matrix<int> P6(strassen_method(S7,S8));
    Matrix<int> P7(strassen_method(S9,S10));
    // Sub matrix Cij
    Matrix<int> C11(P5+P4-P2+P6);
    Matrix<int> C12(P1+P2);
    Matrix<int> C21(P3+P4);
    Matrix<int> C22(P5+P1-P3-P7);
    // Copy
    for ( int i=0; i<n; ++i ) {
      for ( int j=0; j<n; ++j ) {
	C(i,j) = ( i<n/2 ) ? ( j<n/2 ? C11(i,j) : C12(i,j-n/2) ) : 
	  ( j<n/2 ? C21(i-n/2,j) : C22(i-n/2,j-n/2) );
      }
    }
  }
  return C;
}


int main()
{
  // initialization and printing
  srand(time(NULL));
  Matrix<int> A(ROW,COL,1);
  cout<<"Printing matrix A:"<<endl;
  for ( int i=0; i<ROW; ++i ) {
    for ( int j=0; j<COL; ++j ) {
      A(i,j) = rand()%(ROW*COL)+1;
      cout<<A(i,j)<<'\t';
    }
    cout<<endl;
  }
  cout<<endl;
  Matrix<int> B(ROW,COL,1);
  cout<<"Printing matrix B:"<<endl;
  for ( int i=0; i<ROW; ++i ) {
    for ( int j=0; j<COL; ++j ) {
      B(i,j) = rand()%(ROW*COL)+1;
      cout<<B(i,j)<<'\t';
    }
    cout<<endl;
  }
  cout<<endl;
  // Testing
  cout<<"Using built-in A*B operation:"<<endl;
  cout<<(A*B)<<endl;
  cout<<"Using brute-force matrix multiplication:"<<endl;
  cout<<brute_force(A,B)<<endl;
  cout<<"Using simple-square-divide-and-conquer matrix multiplication:"<<endl;
  cout<<simple_square_dc(A,B)<<endl;
  cout<<"Using Strassen's matrix multiplication:"<<endl;
  cout<<strassen_method(A,B)<<endl;



  return 0;
}
