#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n,m;
  // cin >> n >> m;
  n = 2*(long long)pow(10,5);
  long long sum = 0;
  for(int i=0;i<n;i++)
    sum += n-i;
  cout << (long long)pow(n,2) - sum;
}
