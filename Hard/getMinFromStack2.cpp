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

// Method 2 using modulus operator 
// storing two values at one place
class Stack{
public:
stack<int>st;
void push(int x){
if(st.empty()){
  st.push(x*101 + x);
}
else{
  st.push(x*101 + min(x,st.top()%101));
}
}

void pop(){
  if(st.empty()){
    return;
  }
  else{
    st.pop();
  }
}

int peek(){
  if(st.empty()){
    return -1;
  }
  else{
    return st.top()/101;
  }
}

int getMin(){
  if(st.empty()){
    return -1;
  }
  else{
    return st.top()%101;
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