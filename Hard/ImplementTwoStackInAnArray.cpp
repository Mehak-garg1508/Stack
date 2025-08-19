// Two Stacks in an Array
// Your task is to implement  2 stacks in one array efficiently. 
// You need to implement 4 methods.
// twoStacks : Initialize the data structures and variables to
//  be used to implement  2 stacks in one array.
// push1 : pushes element into the first stack.
// push2 : pushes element into the second stack.
// pop1 : pops an element from the first stack and returns the
//  popped element. If the first stack is empty, it should return -1.
// pop2 : pops an element from the second stack and returns 
// the popped element. If the second stack is empty, it should return -1.

// Input:
// push1(2)
// push1(3)
// push2(4)
// pop1()
// pop2()
// pop2()
// Output: [3, 4, -1]
// Explanation: push1(2) the stack1 will be [2]
// push1(3) the stack1 will be [2,3]
// push2(4) the stack2 will be [4]
// pop1()   the poped element will be 3 from stack1 and stack1 will be {2}
// pop2()   the poped element will be 4 from stack2 and now stack2 is empty
// pop2()   the stack2 is now empty hence returned -1.

#include<iostream>
#include <vector>
#include<stack>
using namespace std;

class Stack{
  public:
  int *arr;
  int size;
  int top1, top2;
  Stack(int n){
    size = n;
    arr = new int[n];
    top1 = -1;
    top2 = n;
  }

  void push1(int x){
    if(top1 + 1 == top2){
      return;
    }
    else{
      top1++;
      arr[top1] = x;
    }
  }

  void push2(int x){
    if(top2 - 1  == top1){
      return;
    }
    else{
      top2--;
      arr[top2] = x;
    }
  }

  int pop1(){
    if(top1==-1){
      return -1;
    }
    else{
      int element = arr[top1];
      top1--;
      return element;
    }
  }

  int pop2(){
    if(top2 == size){
      return -1;
    }
    else{
      int element = arr[top2];
      top2++;
      return element;
    }
  } 
};

int main(){
  Stack s(8);
  s.push1(2);
  s.push1(3);
  s.push2(4);
  cout << s.pop1() << endl;
  cout << s.pop2() << endl;
  cout << s.pop2() << endl;
}