#include <bits/stdc++.h>

using namespace std;

int main(){

  for(int i=1;i<=9999;i++){
    string s = to_string(i);
    int j = i*4;
    string p = to_string(j);
    int k;
    if(s.length()!=p.length())continue;
    if(s.length()>4)continue;
    if(p.length()>4)continue;
    while(p.length()<4)p="0"+p;
    while(s.length()<4)s="0"+s;
    if(s[0]==p[3])
    for(k=0;k<s.length();k++){
      if(s[k]!=p[3-k])break;
    }
    if(k==4){
      cout << i << "\n";
      break;
    }
  }
  cout << "_";
}
