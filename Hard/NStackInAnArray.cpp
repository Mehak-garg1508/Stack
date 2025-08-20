// Problem statement
// Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support the following operations:

// push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.

// pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.
// Two types of queries denote these operations :

// Type 1: for push(X, M) operation.
// Type 2: for pop(M) operation.

// Sample Input 1 :
// 3 6 5
// 1 10 1
// 1 20 1
// 1 30 2
// 2 1
// 2 2
// Sample Output 1 :
// True 
// True
// True
// 20
// 30

#include <iostream>
#include<stack>
#include<vector>
using namespace std;

class Node{
public:
int index;
Node *next;
Node(int i){
  index = i;
  next = NULL;
}
};

class NStack{
public:
// Original array
int *arr;
// size of array
int size;
// top indexes of particular stack
Node **Top;
stack<int>st;
NStack(int N, int S){
  arr = new int[S];
  size = S;
  Top = new Node*[N];
  for(int i = 0; i < N; i++){
    Top[i] = NULL;
  }
  for(int i = 0; i < S; i++){
    st.push(i);
  }
}

bool push(int x, int m){
  if(st.empty())
  return 0;

  arr[st.top()] = x;
  Node *temp = new Node(st.top());
  temp->next = Top[m-1];
  Top[m-1] = temp;
  st.pop();
  return 1;
}

int pop(int m){
if(Top[m-1] == NULL)
return -1;

int element = arr[Top[m-1]->index];
st.push(Top[m-1]->index);
Top[m-1] = Top[m-1]->next;
return element;
}
};

int main(){
NStack nst(3,6);
// "10 is pushed into 1st stack, will return true ie 1"
cout << nst.push(10,1) << endl;
// "20 is pushed into 1st stack, will return true ie 1"
cout << nst.push(20,1) << endl;
// "30 is pushed into 2nd stack, will return true ie 1"
cout << nst.push(30,2) << endl;
// will return 20 as output
cout << nst.pop(1) << endl;
// Will return 30 as output
cout << nst.pop(2) << endl;
}