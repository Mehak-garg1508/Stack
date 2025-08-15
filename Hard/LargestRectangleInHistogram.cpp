// Largest Rectangle in Histogram
// Given an array of integers heights representing the
//  histogram's bar height where the width of each bar 
// is 1, return the area of the largest rectangle in the histogram.
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
  int heights[100];
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  cout << "Enter the elements of array: ";
  for(int i = 0; i < n; i++){
  cin >> heights[i];
  }
  // Method 1 with time complexity O(n) in three pass
  // For Next smallest right
  vector<int>right(n);
  // For next smallest left
  vector<int>left(n);
  stack<int>st;
  // Finding next smallest right index
  for(int i = 0; i < n ; i++){
    while(!st.empty() && heights[st.top()] > heights[i]){
      right[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  // Stack ko empty karo
  while(!st.empty()){
  right[st.top()] = n;
  st.pop();
  }
  // finding next largest element index
  for(int i = n - 1; i >= 0 ; i--){
    while(!st.empty() && heights[st.top()] > heights[i]){
      left[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  // Stack ko empty karo
  while(!st.empty()){
  left[st.top()] = -1;
  st.pop();
  }
  // because area can't be negative
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans = max(ans, heights[i]*(right[i] - left[i] - 1));
  }
  cout << "Largest Rectangle has area: " << ans;
}