#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n;
    int u=0,d=0,l=0,r=0;
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
      char c = s[i];
      if(c=='L')l++;
      else if(c=='R')r++;
      else if(c=='U')u++;
      else d++;
    }
    u = min(u,d);
    d=u;
    l = min(l,r);
    r=l;
    if(d!=0&&l!=0){
      cout << d+l+l+d << "\n";
      for(int i=0;i<d;i++)
        cout << "D";
      for(int i=0;i<l;i++)
        cout << "L";
      for(int i=0;i<u;i++)
        cout << "U";
      for(int i=0;i<r;i++)
        cout << "R";
      cout << "\n";
    }else if(l==0 && d!=0){
      cout << "2 \nUD\n";
    }else if(l!=0 && d==0){
      cout << "2 \nLR\n";
    }else
      cout << "0" << "\n";
  }
}

/*
ATTENTION
*
*/
