// The Celebrity Problem
// A celebrity is a person who is known to all but does not know anyone at a party. 
// A party is being organized by some people. A square matrix mat[][] (n*n) is used
// to represent people at the party such that if an element of row i and column j is
// set to 1 it means ith person knows jth person. You need to return the index of the
// celebrity in the party, if the celebrity does not exist, return -1.
// Note: Follow 0-based indexing.

// Input: mat[][] = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]
// Output: 1
// Explanation: 0th and 2nd person both know 1st person.
// Therefore, 1 is the celebrity person.


#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
  int mat[100][100];
  int n;
  cout << "Enter the size of matrix: " << endl;
  cin >> n;
  cout << "Enter the elements of array: "<< endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> mat[i][j];
    }
  }
  int ans = 0;
  stack<int>st;
  for(int i = n - 1; i >= 0; i--){
    st.push(i);
  }

    while(st.size() > 1){
     int first = st.top();
     st.pop();
     int second = st.top();
     st.pop();
     if(!mat[first][second] && mat[second][first]){
      st.push(first);
     }
     else if(mat[first][second] && !mat[second][first]){
      st.push(second);
     }
    }

    if(st.empty()){
      cout << "No celebrity"<< endl;
      return -1;
    }

    int row = 0 , col = 0;
    int num = st.top();
    for(int i = 0; i < n; i++){
    row += mat[num][i];
    col+=mat[i][num];
    }

    if(row==0 && col== n - 1){
      cout << "Celebrity is: "<< num << endl;
    }
    else{
      cout << "No Celebrity"<< endl;
    }
}