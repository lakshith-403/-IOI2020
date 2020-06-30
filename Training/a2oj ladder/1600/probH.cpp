#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int x = 0;
  while(n--){
    string s;
    cin >> s;
    if(s.find('+')!=string::npos)x++;
    if(s.find('-')!=string::npos)x--;
  }
  cout << x << "\n";
}
