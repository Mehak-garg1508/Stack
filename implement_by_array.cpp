// Implementation using array

#include <iostream>
using namespace std;

class Stack{
public:
int *arr;
int size;
int top;
Stack(int s){
arr = new int[5];
size = s;
top = -1;
}

// Pushing the value
void push(int value){
  if(top == size){
    cout << "Stack Overflow" << endl;
    return;
  }
  else{
    top++;
    arr[top] = value;
    cout << "Pushing " << arr[top] << " into stack" << endl;
  }
}

// Popping the element
void pop(){
  if(top == -1){
    cout << "Stack Underflow"<< endl;
    return;
  }
  else{
    top--;
  }
}

// Top Element
int peek(){
  if(top == -1){
    return -1;
  }
  else{
    return arr[top];
  }
}

// whether the stack is empty or not
bool isEmpty(){
  return (top == -1);
}

// size
int isSize(){
  return top+1;
}

};

int main(){
Stack s(5);
s.push(2);
s.push(4);
s.push(6);
s.push(8);
// s.pop();
// s.pop();
// cout << s.isSize() << endl;
s.pop();
s.pop();
cout << s.isEmpty() << endl;
if(s.isEmpty() == 0)
cout << s.peek() << endl;
cout << s.isSize() << endl;
}