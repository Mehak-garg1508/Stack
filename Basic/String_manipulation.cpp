// String Manipulation
// Tom is a string freak. He has got sequences of words arr[] to manipulate. If in a sequence,
//  two same words come together then Tom destroys each other. Find the number of words left in 
// the sequence after this pairwise destruction.

// Input: arr[] = ["ab", "aa", "aa", "bcd", "ab"]
// Output: 3
// Explanation: After the first iteration, we'll have: ab bcd ab. We can't further destroy more strings 
// and hence we stop and the result is 3.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void print(string arr[], int size){
  for(int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
}

int main(){
  string arr[5] = {"ab","aa","aa","bcd","ab"};
  cout << "Input: ";
  print(arr,5);
  cout << endl;
  int size = 5;
  stack<string>st;
  for(int i = 0; i < size; i++){
    if(st.empty()){
      st.push(arr[i]);
    }
    else if(st.top() == arr[i]){
      st.pop();
    }
    else{
      st.push(arr[i]);
    }
  }
  int n = st.size();
  vector<string>ans(n);
  int i = st.size() - 1;
  while(!st.empty()){
   ans[i] = st.top();
   st.pop();
   i--;
  }
  cout << "Output: ";
  for(int i =0; i <ans.size(); i++){
    cout << ans[i] << " ";
  }
}