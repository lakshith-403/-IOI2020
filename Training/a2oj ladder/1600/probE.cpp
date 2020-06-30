#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int Count = 0;
  string prev = "";
  while(n--){
    string s;
    cin >> s;
    if(s!=prev)Count++,prev=s;
  }
  cout << Count << "\n";
}
