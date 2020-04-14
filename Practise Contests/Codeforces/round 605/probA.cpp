#include <bits/stdc++.h>
#define ll long long

using namespace std;

// int abs(int a,int b){
//   return max(a-b,b-a);
// }

ll minL(ll a , ll b){
  if(a>b)
  return b;
  else return a;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int a,b,c;
    cin >> a >> b >> c;
    int A,B,C;
    ll MIN = 10000000000;
    for(int i=-1;i<=1;i++)
      for(int j=-1;j<=1;j++)
        for(int k=-1;k<=1;k++){
          A=a+i;
          B=b+j;
          C=c+k;
          MIN = minL(MIN,abs(A-B)+abs(B-C)+abs(A-C));
        }
    cout << MIN << "\n";
  }
}

/*
ATTENTION
*
*/
