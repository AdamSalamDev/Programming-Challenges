/*
Given an array of numbers, create a program that returns an array with 
(1) all duplicate elements removed and 
(2) values sorted in ascending order.
*/

// Adam Salam

#include <iostream>
#include <vector>
using namespace std; // Usually bad practice but useful for demo


int partition(int nums[], int start, int end){

  int pivot = nums[end];
  int partIndex = start;

  for(int i = start; i < end; i++){
    if(nums[i] <= pivot){
      int temp = nums[i];
      nums[i] = nums[partIndex];
      nums[partIndex] = temp;
      partIndex++;
    }
  }

  int temp = nums[partIndex];
  nums[partIndex] = nums[end];
  nums[end] = temp;

  return partIndex;
}


void QuickSort(int nums[], int L, int H){
  if(L < H){
    int partIndex = partition(nums, L, H);
    QuickSort(nums, L, partIndex-1);
    QuickSort(nums, partIndex+1, H);
  }
}

// sorts the array using a quick sort then 
// uses a linear search to filter out duplicates 
vector<int> setAndSort(int nums[], unsigned int size){

  QuickSort(nums, 0, size -1);

  vector<int> vec;
  vec.push_back(nums[0]);

  for(int i = 1; i < size; i++){
    if(vec[vec.size()-1] != nums[i]){
      vec.push_back(nums[i]);
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