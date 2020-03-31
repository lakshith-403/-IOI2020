#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >>t;
  while(t--){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    bool A,B,C,D;
    int x,y,x1,y1,x2,y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    A = x+(b-a) >= x1 && x+(b-a) <= x2;
    B = y+(d-c) >= y1 && y+(d-c) <= y2;
    C = (x-x1!=0 || x-x2!=0) || (a==0 || b==0);
    D = (y-y1!=0 || y-y2!=0) || (d==0 && c==0);
    if(A&&B&&C&&D)
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }
}
