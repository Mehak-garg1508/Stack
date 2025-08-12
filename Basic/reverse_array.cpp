// Reversing the element using stack

#include <iostream>
#include <stack>
using namespace std;

void print(char ch[], int size){
for(int i = 0; i < size; i++){
  cout << ch[i] << " ";
}
}

int main(){
  char ch[5] = {'h','e','l','l','o'};
  cout << "Input: ";
  print(ch,5);
  cout << endl;
  int n = 5; //size
  // Reversing it
  // Create a stack
  stack<char>s;
  for(int i = 0 ; i < n; i++){
  s.push(ch[i]);
  }
  int i =0;
  while(!s.empty()){
    ch[i] = s.top();
    s.pop();
    i++;
  }
  cout << "Output: ";
  print(ch,5);
}