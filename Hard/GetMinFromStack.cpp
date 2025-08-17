// Get Min from Stack
// Given q queries, You task
// is to implement the following four functions for a stack:

// push(x) – Insert an integer x onto the stack.
// pop() – Remove the top element from the stack.
// peek() - Return the top element from the stack. If the stack is empty, return -1.
// getMin() – Retrieve the minimum element from
// the stack in O(1) time. If the stack is empty, return -1.

// Input: q = 7, queries = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]
// Output: [3, 2, 1]
// Explanation: 
// push(2): Stack is [2]
// push(3): Stack is [2, 3]
// peek(): Top element is 3
// pop(): Removes 3, stack is [2]
// getMin(): Minimum element is 2
// push(1): Stack is [2, 1]
// getMin(): Minimum element is 1
// 1 <= value <= 100 => value is element's value that we are pushing
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Stack{
public:
stack<int>st1;
stack<int>st2;

void push(int x){
  if(st1.empty()){
  st1.push(x);
  st2.push(x);
  }
  else{
    st1.push(x);
    st2.push(min(x,st2.top()));
  }
}

void pop(){
if(st1.empty()){
  return;
}
else{
  // int element = st1.top();
  st1.pop();
  st2.pop();
  // return element;
}
}

int peek(){
  if (st1.empty())
  {
  return -1;
  }
  return st1.top();
}

int getMin(){
  if(st2.empty()){
    return -1;
  }
  else{
    return st2.top();
  }
}
};

int main(){
  Stack s;
  s.push(2);
  s.push(3);
cout << s.peek() << " is top element." << endl;
s.pop();
cout <<"Minimum is: "<< s.getMin() << endl;
s.push(1);
cout << "Minimum is: " << s.getMin() << endl;

Stack s1;
s1.push(4);
s1.push(2);
cout << s1.getMin() << endl;
cout << s1.peek() << " is top element." << endl; 
}