// Smaller on Left
// Given an array arr[] of integers, for each element in the array, 
// find the nearest smaller element on its left. If there is no such smaller element, return -1 for that position.
// Input: arr[] = [1, 6, 2]
// Output: [-1, 1, 1]
// Explaination: 
// There is no number to the left of 1, so we return -1. 
// After that, the number is 6, and the nearest smaller number on its left is 1. 
// Next, the number is 2, and the nearest smaller number on the left is also 1.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
  int arr[100];
  int size;
  cout << "Enter the size of array: ";
  cin >> size;
  cout << "Enter Elements for array: ";
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int>ans(size,-1);
  stack<int>st;
  for(int i = size - 1; i>=0; i--){
  while(!st.empty() && arr[st.top()] > arr[i]){
   ans[st.top()] = arr[i];
   st.pop();
  }
  st.push(i);
  }
  cout << "Ans is: "<< endl;
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
}