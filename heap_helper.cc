/*
   Author : Rick Liu
    Date  : 20150206
   Source : Personal heap helpers
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

// helper: swap
void swap(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}

// helper: pow
int pow(int base, int n) {
  if (n==0) {
    return 1;
  }
  int result = 1;
  for (int i=0; i<n; ++i) {
    result *= base;
  }
  return result;
}

// helper: get height of a complete tree in array
int height(const vector<int>& vec) {
  if (vec.size()==0) {
    return 0;
  }
  int height = 1, gap=2;
  while (vec.size()>=gap) {
    ++height;
    gap*=2;
  }
  return height;
}

// helper: print int vector
void print_vec(const vector<int>& vec) {
  for (int i=0; i<vec.size(); ++i) {
    cout<<vec[i]<<"\t";
  }
  cout<<endl;
}

// helper: print array into tree
/*
h = 4
indent  : 2^(h-1-i)-1
interval: 2^(h-i)-1
       1
   1       1
 1   1   1   1
1 1 1 1 1 1 1 1
*/
void print_tree(const vector<int>& vec) {
  int h = height(vec);
  for (int i=0; i<h; ++i) {
    for (int k=0; k<(pow(2,h-1-i)-1); ++k) {
      cout<<" ";
    }
    for (int j=(pow(2,i)-1); j<vec.size() && j<(2*pow(2,i)-1); ++j) {
      cout<<vec[j];
      for(int k=0; k<(pow(2,h-i)-1); ++k) {
	cout<<" ";
      }
    }
    cout<<endl;
  }
}

// shuffle
void shuffle(vector<int>& vec) {
  int n = vec.size();
  for ( int i=0; i<n; ++i ) {
    swap(vec[i],vec[i+rand()%(n-i)]);
  }
}
