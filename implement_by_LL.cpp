// Implement by Linked List

#include <iostream>
using namespace std;

class Node{
public:
int data;
Node *next;
Node(int value){
  data = value;
  next = NULL;
}
};

class Stack{
public:
Node *top;
int size;
Stack(){
  top = NULL;
  size = 0;
}
// Pushing element into stack
void push(int value){
  Node *temp = new Node(value);
  if(temp == NULL){
    cout << "Stack Overflow\n" << endl;
    return;
  }
  else{
  temp->next = top;
  top = temp;
  size++;
  cout << "Pushed "<<top->data << " into stack" << endl;
}
}

// Popping element into stack
void pop(){
  if(top==NULL){
    cout << "Stack Underflow" << endl;
    return;
  }
  else{
    Node *temp = top;
    cout << "Popped " << top->data<< " from the stack" << endl;
    top = top->next;
    delete temp;
    size--;
  }
}

// Peek element of stack
int Peek(){
  if(top == NULL){
    cout << "Stack is empty" << endl;
    return -1;
  }
  else{
    return top->data;
  }
}

// IsEmpty()
bool isEmpty(){
  return top==NULL;
}

// isSize
int isSize(){
return size;
}
};

int main(){
Stack s;
s.push(4);
s.push(8);
s.push(12);
s.push(16);
s.pop();
s.pop();
cout << s.isSize() << endl;
cout << s.isEmpty() << endl;
cout << s.Peek() << endl;
}