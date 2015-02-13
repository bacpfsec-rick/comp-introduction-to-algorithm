/*
   Author : Rick Liu
    Date  : 20150127
   Source : ItA P18
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;


void insertion_sort(vector<int>& vec) {
  for (int j = 1; j<vec.size(); ++j) {
    int key = vec[j];
    int i = j-1;
    while ( i>=0 && vec[i]>key ) {
      vec[i+1] = vec[i];
      --i;
    }
    vec[i+1] = key;
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

  // print result
  cout<<"---Unsorted---"<<endl;
  for ( int i=0; i<10; ++i ) {
    cout<<vec[i]<<'\t';
  }
  cout<<endl;


  // sort
  insertion_sort(vec);

  // print result
  cout<<"---Insertion-sorted---"<<endl;
  for ( int i=0; i<10; ++i ) {
    cout<<vec[i]<<'\t';
  }
  cout<<endl;


  return 0;
}
