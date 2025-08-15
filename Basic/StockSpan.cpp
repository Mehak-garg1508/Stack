// Stock span problem
// The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days. 
// The span arr[i] of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock
//  on the given day is less than or equal to its price on the current day.

// Input: arr[] = [100, 80, 60, 70, 60, 75, 85]
// Output: [1, 1, 1, 2, 1, 4, 6]
// Explanation: Traversing the given input span
//  100 is greater than equal to 100 and there are no more
//  elements behind it so the span is 1, 80 is greater than equal to 80 
// and smaller than 100 so the span is 1, 60 is greater than equal to 60 
// and smaller than 80 so the span is 1, 70 is greater than equal to 60,70 
// and smaller than 80 so the span is 2 and so on.  
// Hence the output will be 1 1 1 2 1 4 6.


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
  vector<int>ans(size,1);
  stack<int>st;
  for(int i = size - 1; i >= 0; i--){
    while(!st.empty() && arr[st.top()] < arr[i]){
    ans[st.top()] = st.top() - i;
    st.pop();
    }
    st.push(i);
  }
  // Jab stack empty nahi hua
  while(!st.empty()){
    ans[st.top()] = st.top() + 1;
    st.pop();
  }
  for(int i = 0; i < size; i++){
    cout << ans[i] << " ";
  }
}