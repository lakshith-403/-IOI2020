#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  bool alph[26];
  for(int i=0;i<26;i++)alph[i]=false;
  int Count = 0;
  for(char c:s)
    if(!alph[c-'a'])alph[c-'a']=true,Count++;
  cout << (Count&1?"IGNORE HIM!":"CHAT WITH HER!") << "\n";
}
