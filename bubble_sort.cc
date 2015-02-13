/*
   Author : Rick Liu
    Date  : 20150127
   Source : ItA P40
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void bubble_sort(vector<int>& vec) {
  for (int i=0; i<vec.size()-2; ++i) {
    for (int j=vec.size()-1; j>=i+1; --j) {
      if (vec[j]<vec[j-1]) {
	swap(vec[j],vec[j-1]);
      }
    }
  }
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
  bubble_sort(vec);

  // print result before sort
  cout<<"---Bubble-sorted---"<<endl;
  for ( int i=0; i<10; ++i ) {
    cout<<vec[i]<<'\t';
  }
  cout<<endl;


  return 0;
}
