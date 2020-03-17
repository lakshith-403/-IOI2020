/*
ID: lakshit4
PROG: fact4
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int convert(int n){
  string s = to_string(n);
  int i;
  for(i=s.length()-1;i>=0;i--)
    if(s[i]!='0')break;
  return stoi(s.substr(i,1));
}
int n;
int main(){
  ifstream in("fact4.in");
  ofstream out("fact4.out");
  in >> n;
  int digit,n2,n5,i,j;
  digit = 1;
  n2 = n5 = 0;
  for(i=2; i<=n; i++) {
    j = i;
    while(j%2 == 0) {
      n2++;
      j /= 2;
    }
    while(j%5 == 0) {
      n5++;
      j /= 5;
    }
    digit = (digit * j) % 10;
  }

  for(i=0; i<n2-n5; i++)
    digit = (digit * 2) % 10;
    out << digit << endl;
}
