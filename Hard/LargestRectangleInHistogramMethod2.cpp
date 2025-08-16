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
  // Method 2 with time complexity O(n) in one pass
  stack<int>st;
  int ans = 0;
  for(int i =0; i < n; i ++){
    while(!st.empty() && heights[st.top()] > heights[i]){
      int index = st.top();
      st.pop();
      if(!st.empty()){
        ans = max(ans , heights[index] * (i - st.top() - 1));
      }
      else{
        ans = max(ans, heights[index]*i);
      }
    }
    st.push(i);
  }
  // Empty karenga stack ko
  while(!st.empty()){
    int index = st.top();
    st.pop();
    if(!st.empty()){
      ans = max(ans, heights[index]*(n - st.top() - 1));
    }
    else{
      ans = max(ans, heights[index]*n);
    }
  }
  cout << "Largest Rectangle Area in histogram is: "<< ans << " ";
}