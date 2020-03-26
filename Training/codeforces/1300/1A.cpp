#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m,a;
  cin >> n >> m >> a;
  cout << (n/a + (n%a==0?0:1))*(m/a + (m%a==0?0:1)) << "\n";
}
