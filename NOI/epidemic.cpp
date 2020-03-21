#include <bits/stdc++.h>
using namespace std;
long long arr[4][91];
int main(){
  int d;
  cin >> d;
  for(int i=1;i<=5;i++)arr[3][i] = 1;
  arr[2][1] = 1;
  for(int i=6;i<=d;i++){
    arr[1][i] = arr[1][i-1] + arr[2][i-5];
    arr[2][i] = arr[1][i]*3;
    arr[3][i] = arr[3][i-1] + arr[2][i] - (arr[1][i]-arr[1][i-1]);
  }
  cout << arr[1][d] +arr[3][d] << endl;
}
