// Next Smaller Element
// You are given an array 'ARR' of integers of length N. Your task is to find the next 
// smaller element for each of the array elements.

// Next Smaller Element for an array element is the first element to the 
// right of that element which has a value strictly smaller than that element.

// If for any array element the next smaller element does not exist, you should print -1 for that array element.

// For Example:

// If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. 
// Because for  2, 1 is the Next Smaller element. For 3, 1 is the Next Smaller 
// element and for 1, there is no next smaller element hence the answer for this element is -1.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
  int arr[100];
  int size;
  cout << "Enter size for array: " ;
  cin >> size;
  cout << "Enter elements of array: ";
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int>ans(size,-1);
  stack<int>st;
  for(int i = 0; i < size; i++){
  while(!st.empty() && arr[st.top()] > arr[i]){
    ans[st.top()] = arr[i];
    st.pop();
  }
  st.push(i);
  }
  cout << "Output is: " << endl;
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
}