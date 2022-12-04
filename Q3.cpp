/*
Consider that you are given a string that contains only parentheses, brackets, and curly braces: (), [], {}.
Write a function that takes in this string, determines if the order of the brackets follows the correct scope
order, and returns both (1) a Boolean indicating if the order was appropriate and (2) the number of successful
pairs. If the order is broken or incomplete, return a value of zero (0) for the number of successful pairs. 
You may presume that only parentheses, brackets, and curly braces will be used in the string.
*/

// Adam Salam

#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std; // Usually bad practice but useful for demo

// I know there is a built in stack. Just having fun
class myStack{

  private:
    vector<char> vec;

  public:
    void push(char c){
      vec.push_back(c);
    }
  
    void pop(){
      if(vec.size() > 0){
        vec.resize(vec.size() -1);
      }
    }
  
    char peek(){
      if(vec.size() > 0){
        return vec[vec.size()-1];
      }
      return ' ';
    }
  
    int Size(){
      return vec.size();
    }
};

// helper method that validates if an incoming char 
// is an open parentheses, bracket, or curly brace.
bool isOpen(char c){
  char open[] = {'(', '{', '['};
  for(int i = 0; i < 3; i++){
    if(c == open[i]) return true;
  }
  return false;
}

// helper method for aligning pairs.
char reverse(char c){
  switch(c){
    case ')': return '(';
    case '}': return '{';
    case ']': return '[';
  }
  return ' ';
}

// helper method for comparing like pairs.
bool hasClose(char top, char c){
  return (reverse(c) == top);
}


tuple<bool, int> scopeCheck(string s){

  // if the string length is uneven, we know the scope is invalid
  if(s.length() % 2 != 0){
    return {false, 0};
  }

  int pairs = 0;
  myStack stack; // using a stack is great for this type of problem
  
  for(int i = 0; i < s.length(); i++){
    
    // always add open parentheses, brackets, or curly braces
    // to the stack.
    if(isOpen(s[i])){
      stack.push(s[i]);
    }
    // if the stack is not empty, peek the top and 
    // see if we have a matching pair or not.
    else if(stack.Size() > 0){
      if( hasClose(stack.peek(),s[i]) ){
        stack.pop();
        pairs++;
      }
    }
      // if we are here, the stack is empty but,
      // a closing parenthese, bracket, or curly brace
      // is up next. Missing open par, brac, or brace 
      // to complete scope.
    else{
      return {false, 0};
    }
  }

  // if list is empty, scope is valid. Otherwise, scope is not valid
  if(stack.Size() == 0){
    return {true, pairs};
  }
  
  return {false, 0};
}

int main() {

  string t1 = "()";
  string t2 = "({[]})";
  string t3 = "((){}())";
  string t4 = "((}";
  string t5 = "()(";
  string t6 = "()(())";

  string tests[] = {t1,t2,t3,t4,t5,t6};

  printf("\n%-20s%-20s%-20s\n", "Category", "Input", "Output\n"); 

  for(int i = 0; i < sizeof(tests) / sizeof(string); i++){
    auto [value1, value2] = scopeCheck(tests[i]);
    string output = (value1) ? "True,"+to_string(value2): "False,"+to_string(value2);

    if(value1){
      printf("%-20s%-20s%-20s\n", "Valid", tests[i].c_str(), output.c_str());
    }
    else{
      printf("%-20s%-20s%-20s\n", "Invalid", tests[i].c_str(), output.c_str());
    }
  }
}