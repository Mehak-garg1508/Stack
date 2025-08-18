// Max of min for every window size

// Given an array of integers arr[], the task is to 
// find the maximum of the minimum values for every 
// possible window size in the array, where the window 
// size ranges from 1 to arr.size().

// More formally, for each window size k, determine the
//  smallest element in all windows of size k, and then 
// find the largest value among these minimums 
// where 1<=k<=arr.size().

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
  int arr[100];
  int n;
  cout << "Enter the size of array: " << endl;
  cin >> n;
  cout << "Enter the elements for array: " << endl;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  // Method 2 with time complexity O(n)
  // The most effective method
  vector<int>ans(n,0);
  stack<int>st;
  for(int i = 0; i < n; i++){
    while(!st.empty() && arr[st.top()] > arr[i]){
      int index = st.top();
      st.pop();
      if(st.empty()){
        int range = i;
        ans[range - 1] = max(ans[range - 1] , arr[index]);
      }
      else{
        int range = i - st.top() - 1;
        ans[range-1] = max(ans[range - 1], arr[index]);
      }
    }
    st.push(i);
  }

  while(!st.empty()){
    int index = st.top();
    st.pop();
    if(st.empty()){
      int range = n;
      ans[range - 1] = max(ans[range - 1], arr[index]);
    }
    else{
      int range = n - st.top() - 1;
      ans[range - 1] = max(ans[range - 1], arr[index]);
    }
  }
  for(int i = n - 2; i >= 0; i--){
    ans[i] = max(ans[i] , ans[i + 1]);
  }
  
  cout << "Output is: " << endl;
  for(int i = 0; i < n; i++){
    cout << ans[i] << " ";
  }
}