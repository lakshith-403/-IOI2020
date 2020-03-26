#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int m;
    char c;
    string s1="";
    string s2="";
    int i;
    for(i=0;i<n;i++){
      cin >> c;
      m = c-'0';
      if(m==0){
        s1+="0";
        s2+="0";
      }else if(m==2){
        s1+="1";
        s2+="1";
      }else if(m==1){
        s1+="1";
        s2+="0";
        break;
      }
    }
    for(i=i+1;i<n;i++){
      cin >> c;
      m = c-'0';
      if(m==0){
        s1+="0";
        s2+="0";
      }else if(m==2){
        s1+="0";
        s2+="2";
      }else if(m==1){
        s1+="0";
        s2+="1";
      }
    }
    cout << s1 << "\n" << s2 << "\n";
  }
}
