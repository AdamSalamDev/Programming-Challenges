/* 
Create a program that takes an array of numbers 
and returns the sum of the two lowest, positive numbers.
*/

// Adam Salam

#include <iostream>
using namespace std; // Usually bad practice but useful for demo

long sumLowestPositives(long nums[], unsigned int size){

  int i = 0;
  long sum = 0;
  int count =0;
  
  while(count < 2 && i < size){

    // skips all starting negative numbers
    if(nums[i] >= 0){
      
      // linear search for the index with the smallest number
      int minIndex = i;
      for(int j = i+1; j < size; j++){

        // skips all following negative numbers
        if(nums[j] >= 0){
          if(nums[j] < nums[minIndex]){
            minIndex = j;
          }
        }
      }
      
      // swaps the lowest number with i and adds to total
      int temp = nums[i];
      nums[i] = nums[minIndex];
      nums[minIndex] = temp;
      sum += nums[i];
        
      count++;
    }
    
    i++;
  }

  return sum;
}

int main() {
  
  long test1[] = {19, 5, 42, 2, 77};
  long test2[] = {10, 343445353, 3453445, 3453545353453};
  long test3[] = {2, 9, 6, -1};
  long test4[] = {879, 953, 694, -847, 342, 221, -91, -723, 791, -587};
  long test5[] = {3683, 2902, 3951, -475, 1617, -2385};
  long myTest6[] = {-4, -77, -11, -165};
  long myTest7[] = {-4, -77, 11, -33};

  cout <<"Sum of Test 1:\t"<< sumLowestPositives(test1, (sizeof(test1) / sizeof(long)) ) << endl;
  cout <<"Sum of Test 2:\t"<< sumLowestPositives(test2, (sizeof(test2) / sizeof(long)) ) << endl;
  cout <<"Sum of Test 3:\t" << sumLowestPositives(test3, (sizeof(test3) / sizeof(long)) ) << endl;
  cout <<"Sum of Test 4:\t"<< sumLowestPositives(test4, (sizeof(test4) / sizeof(long)) ) << endl;
  cout <<"Sum of Test 5:\t"<< sumLowestPositives(test5, (sizeof(test5) / sizeof(long)) ) << endl;
  cout <<"Sum of Test 6:\t"<< sumLowestPositives(myTest6, (sizeof(myTest6) / sizeof(long)) ) << endl;
  cout <<"Sum of Test 7:\t"<< sumLowestPositives(myTest7, (sizeof(myTest7) / sizeof(long)) ) << endl;
}