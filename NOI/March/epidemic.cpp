#include <bits/stdc++.h>
using namespace std;
long long arr[4][91];
//arr[1] = grown cells
//arr[2] = new born cells
//arr[3] = total children
//same as the table given in the problem statement

int main(){
  int d;
  cin >> d;

  //first 5 columns of the rray is predefined.
  //as in the given table
  //fill the children row by 1
  for(int i=1;i<=5;i++)arr[3][i] = 1;

  //in the first day i child is born
  arr[2][1] = 1;

  //loops for each next day
  for(int i=6;i<=d;i++){
    //grown cells in a day = grown cells so far + children who was born 5 days ago
    arr[1][i] = arr[1][i-1] + arr[2][i-5];
    //new children in a day = grown cells at that day * 3
    arr[2][i] = arr[1][i]*3;
    //total children in a day = no of children so far + new children in that day - newly grown men
    arr[3][i] = arr[3][i-1] + arr[2][i] - (arr[1][i]-arr[1][i-1]);
  }
  //total cells of day d = grown cells + total children
  cout << arr[1][d] +arr[3][d] << endl;
}
