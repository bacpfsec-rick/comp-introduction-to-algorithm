/*
   Author : Rick Liu
    Date  : 20150129
   Source : ItA P71
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

int find_max_crossing_subarray(vector<int>& A, int low, int mid, int high,
			       int& max_left, int& max_right) {
  int left_sum = -999999;    // -infty
  int sum = 0;
  for (int i=mid; i>=low; --i) {
    sum += A[i];
    if (sum>left_sum){
      left_sum = sum;
      max_left = i;
    }
  }
  int right_sum = -999999;
  sum = 0;
  for (int i=mid+1; i<=high; i++) {
    sum += A[i];
    if (sum>right_sum){
      right_sum = sum;
      max_right = i;
    }
  }
  return left_sum+right_sum;
}
  
int find_maximum_subarray(vector<int>& A, int low, int high,
			  int& left_max, int& right_max) {
  if (high==low) {
    left_max = low;
    right_max = high;
    return A[high];
  } else {
    int mid = (low+high)/2;
    int left_low,left_high,right_low,right_high,cross_low,cross_high;
    int left_sum = find_maximum_subarray(A,low,mid,
					 left_low,left_high);
    int right_sum = find_maximum_subarray(A,mid+1,high,
					  right_low,right_high);
    int cross_sum = find_max_crossing_subarray(A,low,mid,high,
					       cross_low,cross_high);
    // compare the result
    if ( (left_sum > right_sum) && (left_sum > cross_sum) ) {
      left_max = left_low;
      right_max = left_high;
      return left_sum;
    } else if ( (right_sum > left_sum) && (right_sum > cross_sum) ) {
	left_max = right_low;
	right_max = right_high;
	return right_sum;
    } else {
      left_max = cross_low;
      right_max = cross_high;
      return cross_sum;
    }
  }
}

int find_maximum_subarray(vector<int>& A, int& left, int& right){
  find_maximum_subarray(A,0,A.size()-1,left,right);
}

int main()
{
  // initialize
  srand(time(NULL));
  vector<int> vec;
  for ( int i=0; i<10; ++i ) {
    vec.push_back(rand()%11-5);
  }

  // print initial vector
  cout<<"---Data---"<<endl;
  for ( int i=0; i<10; ++i ) {
    cout<<vec[i]<<'\t';
  }
  cout<<endl;


  // sort
  int left_index,right_index;
  find_maximum_subarray(vec,left_index,right_index);

  // print result before sort
  cout<<"---Maximum-subarray---"<<endl;
  cout<<"Left index: "<<left_index<<endl;
  cout<<"Right index: "<<right_index<<endl;
  for ( int i=left_index; i<=right_index; ++i ) {
    cout<<vec[i]<<'\t';
  }
  cout<<endl;


  return 0;
}
