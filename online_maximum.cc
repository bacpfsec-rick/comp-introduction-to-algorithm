/*
   Author : Rick Liu
    Date  : 20150206
   Source : ItA P140
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#define e 2.7182818284
using namespace std;

int online_maximum(const vector<int>& vec,int k) {
  int best_score = -999999, n = vec.size();
  for (int i=0; i<k; ++i) {
    if (vec[i] > best_score) {
      best_score = vec[i];
    }
  }
  for (int i=k; i<n; ++i) {
    if (vec[i] > best_score) {
      return i;
    }
  }
  return n-1;
}
  
int main()
{
  // initialize
  srand(time(NULL));
  vector<int> vec;
  for ( int i=0; i<10; ++i ) {
    vec.push_back(rand()%100+1);
  }

  // print original score list
  cout<<"---Original---"<<endl;
  for ( int i=0; i<10; ++i ) {
    cout<<vec[i]<<'\t';
  }
  cout<<endl;

  // find the online-maximum
  int om_index = online_maximum(vec,vec.size()/e);
  cout<<"The online-maximum is the candidate with index "
      <<om_index<<" with a score of "<<vec[om_index]<<endl;

  return 0;
}
