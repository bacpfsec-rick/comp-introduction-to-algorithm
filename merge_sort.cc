/*
   Author : Rick Liu
    Date  : 20150127
   Source : ItA P31
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

void merge(vector<int>& A, int p, int q, int r) { // q is the left end
  int n1 = q-p+1;
  int n2 = r-q;
  vector<int> L,R;
  for (int i=0; i<n1; ++i) {
    L.push_back(A[p+i]);
  }
  for (int j=0; j<n2; ++j) {
    R.push_back(A[q+j+1]);
  }
  L.push_back(10000); // infty value
  R.push_back(10000); // infty value
  int i = 0, j = 0;
  for (int k=p; k<=r; ++k) {
    if (L[i]<=R[j]) {
      A[k] = L[i];
      ++i;
    } else {
      A[k] = R[j];
      ++j;
    }
  }
}

void merge_sort(vector<int>& A,int p, int r) {
  if (p<r) {
    int q = (p+r)/2;
    merge_sort(A,p,q);
    merge_sort(A,q+1,r);
    merge(A,p,q,r);
  }
}

void merge_sort(vector<int>& A) {
  merge_sort(A,0,A.size()-1);
}
  
int main()
{
  // initialize
  srand(time(NULL));
  vector<int> vec;
  for ( int i=0; i<10; ++i ) {
    vec.push_back(rand()%10+1);
  }

  // print result before sort
  cout<<"---Unsorted---"<<endl;
  for ( int i=0; i<10; ++i ) {
    cout<<vec[i]<<'\t';
  }
  cout<<endl;


  // sort
  merge_sort(vec);

  // print result before sort
  cout<<"---Merge-sorted---"<<endl;
  for ( int i=0; i<10; ++i ) {
    cout<<vec[i]<<'\t';
  }
  cout<<endl;


  return 0;
}
