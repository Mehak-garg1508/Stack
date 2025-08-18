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
  // Method 1 with time complexity O(n^3)
  vector<int>ans(n,0);
  // Number of cases possible
  for(int i = 0; i < n; i++){
    // Kitni window banage
    for(int j = 0; j < n - i; j++){
      int num = INT16_MAX;
      // Window ka size
      for(int k = j; k < j + i + 1; k++){
       num = min(num, arr[k]);
      }
      ans[i] = max(ans[i], num);
    }
  }
  for(int i = 0; i < n; i++){
   cout << ans[i] << " ";
  }
}