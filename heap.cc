/*
   Author : Rick Liu
    Date  : 20150206
   Source : ItA P152~165
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "heap_helper.cc"
using namespace std;


// Used to accompany the index style of ItA
int& visit(vector<int>& vec, int i) {
  return vec[i-1];
}
int peep(const vector<int>& vec, int i) {
  return vec[i-1];
}

// parent, left, right
int parent(int i) {
  return i/2;
}
int left(int i) {
  return 2*i;
}
int right(int i) {
  return 2*i+1;
}
  
// heapify
void max_heapify(vector<int>& vec, int i) {
  int l = left(i);
  int r = right(i);
  int largest;
  if (l<=vec.size() && visit(vec,l)>visit(vec,i)) {
    largest = l;
  } else {
    largest = i;
  }
  if (r<=vec.size() && visit(vec,r)>visit(vec,largest)) {
    largest = r;
  }
  if (largest != i) {
    swap(visit(vec,i),visit(vec,largest));
    max_heapify(vec,largest);
  }
}

// build max heap
void build_max_heap(vector<int>& vec) {
  for ( int i=vec.size()/2; i>=1; --i) {
    max_heapify(vec,i);
  }
}

// using the idea of decreasing size
void heapsort(vector<int>& vec) {
  vector<int> copy = vec;
  build_max_heap(copy);
  for (int i=copy.size(); i>=2; --i) {
    swap(visit(copy,1),visit(copy,i));
    visit(vec,i) = visit(copy,i);   // copy the discard value to original vec
    copy.pop_back();
    max_heapify(copy,1);
  }
  // copy back the first cell
  visit(vec,1) = visit(copy,1);
}

// show the current max
int heap_maximum(const vector<int>& vec) {
  return peep(vec,1);
}

// extract the current max
int heap_extract_max(vector<int>& vec) {
  int max = -99999;
  if (vec.size()<1) {
    cout<<"Heap is empty!"<<endl;
    return max;
  }
  max = peep(vec,1);
  visit(vec,1) = visit(vec,vec.size());
  vec.pop_back();
  max_heapify(vec,1);
  return max;
}

// increase key
void heap_increase_key(vector<int>& vec, int i, int key) {
  if (key < peep(vec,i)) {
    cout<<"New key is too small!"<<endl;
  }
  visit(vec,i) = key;
  while ( (i>1) && peep(vec,parent(i))<peep(vec,i) ) {
    swap(visit(vec,i),visit(vec,parent(i)));
    i = parent(i);
  }
}

// insert key
void max_heap_insert(vector<int>& vec, int key) {
  vec.push_back(-99999);
  heap_increase_key(vec,vec.size(),key);
}

int main()
{
  // initialize
  srand(time(NULL));
  vector<int> vec;
  vector<int> vec_copy,vec_sorted;
  for ( int i=0; i<20; ++i ) {
    vec.push_back(rand()%10);
  }
  vec_copy = vec;
  vec_sorted = vec;

  // print result before heapify
  cout<<"---Original---"<<endl;
  print_vec(vec);

  // print as a tree
  cout<<"---Tree---"<<endl;
  print_tree(vec);

  // height
  cout<<"The height of heap tree is : "<<height(vec)<<endl;

  // build-max-heap and print the tree
  cout<<"---Build max heap---"<<endl;
  build_max_heap(vec_copy);
  print_tree(vec_copy);
  
  // heapsort
  cout<<"---Heapsort---"<<endl;
  heapsort(vec_sorted);
  print_tree(vec_sorted);

  // heap-max
  cout<<"---Current max of heap---"<<endl;
  cout<<heap_maximum(vec_copy)<<endl;

  // extract-max
  cout<<"---Extract max of heap---"<<endl;
  cout<<"Max : "<<heap_extract_max(vec_copy)<<endl;
  print_tree(vec_copy);

  // increase key
  cout<<"---Increase last key to 99---"<<endl;
  heap_increase_key(vec_copy,vec_copy.size(),99);
  print_tree(vec_copy);

  // insert key
  cout<<"---Insert a key key as 100---"<<endl;
  max_heap_insert(vec_copy,100);
  print_tree(vec_copy);

  return 0;
}
