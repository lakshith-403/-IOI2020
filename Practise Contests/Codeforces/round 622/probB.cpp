#include <bits/stdc++.h>

using namespace std;
int n,x,y;
int main(){
  int t;
  cin >> t;
  while(t--){
    cin >> n >> x >> y;
    int MAX = min(n,x-1+y-1+1);
    int MIN = min(x,y)-(n-max(x,y));
    MIN++;
    if(MIN < 1) MIN=1;
    cout << MIN << " " << MAX << endl;
  }
}
