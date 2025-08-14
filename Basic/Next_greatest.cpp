// Next Greater Element
// Given an array arr[ ] of integers, the task is to find the next greater element for each element of the array 
// in order of their appearance in the array. Next greater element of an element in the array is the 
// nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for 
// current element is -1. For example, next greater of the last element is always -1.

// Input: arr[] = [1, 3, 2, 4]
// Output: [3, 4, 4, -1]
// Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void print(int arr[], int size){
  for(int i = 0; i < size; i++){
  cout << arr[i] << " ";
  }
}

void printV(vector<int>ans){
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
}

int main(){
  int arr[4] = {1,3,2,4};
 cout << "Input: ";
 int size = 4;
 print(arr,size);
 cout << endl;
 vector<int>ans(size,-1);
 stack<int>st;
 for(int i = 0; i < size; i++){
  while(!st.empty() && arr[st.top()]<arr[i]){
    ans[st.top()] = arr[i];
    st.pop();
  }
  st.push(i);
 }
 cout << "Output: ";
 printV(ans);
}