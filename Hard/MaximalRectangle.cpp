// Maximal Rectangle
// Given a rows x cols binary matrix filled with 0's and 1's,
//  find the largest rectangle containing only 1's and return its area.

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int maxRect(vector<int>heights){
int ans = 0;
int n = heights.size();
stack<int>st;
for(int i = 0; i < n; i++){
  while(!st.empty() && heights[st.top()] > heights[i]){
    int index = st.top();
    st.pop();
    if(!st.empty()){
      ans = max(ans, heights[index]*(i - st.top() - 1));
    }
    else{
      ans = max(ans , heights[index]*(i));
    }
  }
  st.push(i);
}
// Stack ko empty karenga
while(!st.empty()){
  int index = st.top();
  st.pop();
  if(!st.empty()){
   ans = max(ans, heights[index]*(n - st.top() - 1));
  }
  else{
    ans = max(ans , heights[index]*n);
  }
}
return ans;
}

int main(){
  int mat[100][100];
  int row , col;
  cout << "Enter the number of rows: " << endl;
  cin >> row;
  cout << "Enter the number of column: "<< endl;
  cin >> col;
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      cin >> mat[i][j];
    }
    // cout << endl;
  }
  int ans = 0;
  vector<int>heights(col,0);
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      if(mat[i][j] == 0)
        heights[j] = 0;
      else
      heights[j]+=1;
    }
    ans = max(ans, maxRect(heights));
  }
  cout << "Largest rectangle area is: " << ans;
}