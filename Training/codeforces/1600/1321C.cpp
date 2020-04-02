#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int t = 100;
  int Count = 0;
  while(t--){
    if(s.length()==1)break;
    int MAX = -1;
    int index = 0;
    if(s[s.length()-1]-s[s.length()-2]==1){
      if(s[s.length()-1]>MAX){
        MAX = s[s.length()-1];
        index = s.length()-1;
      }
    }
    if(s[0]-s[1]==1){
      if(s[0]>MAX){
        MAX = s[0];
        index = 0;
      }
    }
    for(int i=1;i<s.length()-1;i++){
      if(s[i]-s[i-1]==1 || s[i]-s[i+1]==1){
        if(s[i]>MAX){
          MAX = s[i];
          index = i;
        }
      }
    }
    if(MAX!=-1){
      s.erase(index,1); Count++;
    }
  }
  cout << Count << "\n";
}
