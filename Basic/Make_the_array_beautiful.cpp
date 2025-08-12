// Make the array beautiful
// Given an array of negative and non-negative integers. 
// You have to make the array beautiful. An array is 
// beautiful if two adjacent integers, arr[i] and arr[i+1] are 
// either negative or non-negative. And you can do the following operation any number of times until the array becomes beautiful.

// If two adjacent integers are different i.e. one of them is negative and other is 
// non-negative, remove them.
// Return the beautiful array after performing the above operation.

// Note:An empty array is also a beautiful array. There can be many adjacent integers which are different as stated above. So remove different 
// adjacent integers as described above from left to right.

// Input: 4 2 -2 1
// Output: 4 1
// Explanation: As at indices 1 and 2 , 2 and -2 have
// different sign, they are removed. And the  the final
// array is: 4 1.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void print(int arr[], int size){
  for(int i = 0; i < size; i++){
  cout << arr[i] << " ";
  }
}

void printV(vector<int>v){
  for(int i = 0; i < v.size(); i++){
  cout << v[i] << " ";
  }
}

int main(){
  // Positive Array
  int arr[4] = {4,2,-2,1};
  // Negative Array
  int brr[4] = {-4,-2,-2,1};
  // array size
  int size = 4;
  stack<int>st;
  for(int i = 0; i < size; i++){
    // For positive array
    if(st.empty()){
      st.push(arr[i]);
    }
    else if(arr[i]>=0){
      if(st.top() >= 0){
        st.push(arr[i]);
      }
      else{
        st.pop();
      }
    }
    // For negative array
    else{
     if(st.top() < 0){
      st.push(arr[i]);
     }
     else{
      st.pop();
     }
    }
  }

  vector<int>ans(st.size());
  for(int i = ans.size() - 1; i >= 0; i--){
    ans[i] = st.top();
    st.pop();
  }
  printV(ans);
}