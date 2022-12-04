/*
Given an array of numbers, create a program that returns an array with 
(1) all duplicate elements removed and 
(2) values sorted in ascending order.
*/

// Adam Salam

#include <iostream>
#include<vector>

using namespace std; // Usually bad practice but useful for demo

// only works with positive Integers.
vector<int> setAndSort(int nums[], unsigned int size){

  int max = nums[0];

  // finds max value in the area
  for(int i = 1; i < size; i++){
    if(nums[i] > max){ 
      max = nums[i]; 
    }
  }

  // creats a simple hash map with 1D array.
  int hash[max+1];

  // populates the array with -1
  for(int i = 0; i < max+1; i++){
    hash[i] = -1;
  }

  // Uses the hash array index numbers as keys.
  // assigns the values of the old array to the 
  // corresponding key position of the hash array. 
  // Example: the number 7 is assigned to index 7 of the hash array.
  for(int i = 0; i < size; i++){
    hash[nums[i]] = nums[i];
  }

  // creats a tidy array to be returned.
  vector<int> vec;
  
  for(int i = 0; i < max+1; i++){
    if(hash[i] != -1){
      vec.push_back(hash[i]);
    }
  }
 
  return vec;
}


void PrintArray(vector<int> nums){
  for (int i = 0; i < nums.size(); i++){
    cout << nums[i] << " ";
  }
  cout << endl;
}


int main() {
  int test1[] = {1, 2, 4, 3};
  int test2[] = {1, 4, 4, 4, 4, 4, 3, 2, 1, 2};
  int test3[] = {6, 7, 3, 2, 1};
  int myTest4[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

  PrintArray(setAndSort(test1, sizeof(test1) / sizeof(int)));
  PrintArray(setAndSort(test2, sizeof(test2) / sizeof(int)));
  PrintArray(setAndSort(test3, sizeof(test3) / sizeof(int)));
  PrintArray(setAndSort(myTest4, sizeof(myTest4) / sizeof(int)));
}