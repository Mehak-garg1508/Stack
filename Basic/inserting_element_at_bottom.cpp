// We need to insert the element at the bottom of stack 
// Input :-  s= [1 2 3 4 5], x = 6
// Output:- [1 2 3 4 5 6]

#include<iostream>
#include<stack>
using namespace std;

void print(stack<int>s){
  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
}

int main(){
  stack<int>s;
  // Creating input stack;
  s.push(5);
  s.push(4);
  s.push(3);
  s.push(2);
  s.push(1);
  cout << "Input: ";
  print(s);
  cout << endl;
  // Element that is need to be inserted
  int x = 6;
  // created new stack
  stack<int>temp;
  while(!s.empty()){
  temp.push(s.top());
  s.pop();
  }
  temp.push(x);
  while(!temp.empty()){
    s.push(temp.top());
    temp.pop();
  }
  cout << "Output: ";
  print(s);
}
