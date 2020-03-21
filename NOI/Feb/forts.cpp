#include <bits/stdc++.h>

using namespace std;
int N;

//(M)(M+1)(N)(N+1)/4
int getSquares(int n , int m){
      return (m * n* (m+1) * (n+1)) / 4;
}

int check(int n){
  int MAX = INT_MIN;
  for(int i=1;i<n;i++){
    if(n%i!=0) continue;
    MAX = max(getSquares(i,n%i),MAX);
  }
  return MAX;
}

int main(){
  cin >> n;
  for(int i=1;i<n;i++){
    int a = check(i);
    if(a>=n){
      cout << a << endl;
      break;
    }
  }
  return 0;
}
