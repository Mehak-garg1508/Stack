// Given a circular integer array arr[], the task is to determine the 
// next greater element (NGE) for each element in the array.
// The next greater element of an element arr[i] is the first element 
// that is greater than arr[i] when traversing circularly. If no such element exists, return -1 for that position.
// Circular Property:
// Since the array is circular, after reaching the last element,
//  the search continues from the beginning until we have looked at all elements once.
// Input: arr[] = [1, 3, 2, 4]
// Output: [3, 4, 4, -1]
// Explanation:
// The next greater element for 1 is 3.
// The next greater element for 3 is 4.
// The next greater element for 2 is 4.
// The next greater element for 4 does not exist, so return -1.


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
  for(int i =0 ; i < 2*size; i++){
    while(!st.empty() && arr[st.top()] < arr[i%size]){
      ans[st.top()] = arr[i%size];
      st.pop();
    }
    st.push(i%size);
  }
  cout << "Output is: " ;
  for(int i = 0 ; i <size; i++){
    cout << ans[i] << " ";
  }
}