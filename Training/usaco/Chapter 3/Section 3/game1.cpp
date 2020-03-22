#include <bits/stdc++.h>

using namespace std;

ifstream in("game1.in");
ofstream out("game1.out");

int arr[201];
int dp[2][201][201];

int getMax(int l,int r,int sum,int ab){
  if(l==r)return sum;
  if(dp[ab][l][r]!=0)return sum + dp[ab][l][r];
  int ans;
  if(ab==0)
    ans =  max(getMax(l,r-1,arr[r],1),getMax(l+1,r,arr[l],1));
  else
    ans =  max(getMax(l,r-1,0,0),getMax(l+1,r,0,0));
  dp[ab][l][r] = ans;
  return sum + ans;
}

int main(){
  int n;
  in >> n;
  int total = 0;
  for(int i=0;i<n;i++){
    in >> arr[i];
    total += arr[i];
  }
  int MAX = getMax(0,n-1,0,0);
  out << MAX << " " << total-MAX << endl;
}
