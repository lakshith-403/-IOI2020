#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

long long arr[2*(int)pow(10,5)+1];
long long tenthPow[2*(int)pow(10,5)+1];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  tenthPow[0] = 1;
  for(int i=1;i<=n;i++){
    tenthPow[i] = tenthPow[i-1]*10;
    tenthPow[i] %=MOD;
  }
  for(int i=1;i<n;i++){
    arr[i]=2*10*9*tenthPow[n-i-1];
    arr[i]%=MOD;
    arr[i]+=(n-i-1)*10*9*9*tenthPow[n-i-2];
    arr[i]%=MOD;
    cout << arr[i] << " ";
  }
  cout << 10 << "\n";
}
