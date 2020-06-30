#include <bits/stdc++.h>

using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  for(int i=0;i<a.length();i++){
    a[i] = tolower(a[i]);
    b[i] = tolower(b[i]);
  }
  int ans;
  if(a==b)ans = 0;
  else if(a<b)ans = -1;
  else ans = 1;
  cout << ans << "\n";
}
