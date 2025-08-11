// Implementation using SQL

#include<iostream>
#include<stack>
using namespace std;
int main(){
  stack<int>s;
  s.push(5);
  s.push(15);
  s.push(20);
  // Size of stack
  cout << "Size of stack: " << s.size() << endl;
  // top of stack
  cout << "top element of stack: "<< s.top() << endl;
  s.pop();
  cout << "top element of stack after pop: "<< s.top() << endl;
  cout << "Stack is empty or not: " <<  s.empty() << endl;
}