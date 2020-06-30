#include <bits/stdc++.h>

using namespace std;

int main(){
  int x,y;
  for(int i=1;i<=5;i++)
    for(int j=1;j<=5;j++)
    {
      int a;
      cin >> a;
      if(a==1){x=i,y=j;break;}
    }
  cout << max(x,3)-min(x,3) + max(y,3) - min(y,3) << "\n";
}
