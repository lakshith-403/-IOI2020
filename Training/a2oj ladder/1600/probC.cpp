#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main(){
  io_setup();
  int n;
  cin >> n;
  int C = 0;
  while(n--){
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b+c >= 2)C++;
  }
  cout << C << "\n";
}
