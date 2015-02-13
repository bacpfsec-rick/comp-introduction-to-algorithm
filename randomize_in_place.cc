/*
   Author : Rick Liu
    Date  : 20150206
   Source : ItA P126
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

void randomize_in_place(vector<int>& vec) {
  int n = vec.size();
  for ( int i=0; i<n; ++i ) {
    swap(vec[i],vec[i+rand()%(n-i)]);
  }
}
  
int main()
{
  // initialize
  srand(time(NULL));
  vector<int> vec;
  for ( int i=0; i<10; ++i ) {
    vec.push_back(i+1);
  }

  // print result before randomized
  cout<<"---Original---"<<endl;
  for ( int i=0; i<10; ++i ) {
    cout<<vec[i]<<'\t';
  }
  cout<<endl;


  // randoization
  randomize_in_place(vec);

  // print result before sort
  cout<<"---Randomized---"<<endl;
  for ( int i=0; i<10; ++i ) {
    cout<<vec[i]<<'\t';
  }
  cout<<endl;


  return 0;
}
