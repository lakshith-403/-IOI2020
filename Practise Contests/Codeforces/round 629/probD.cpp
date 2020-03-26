#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >>t;
  while(t--){
    int n;
    cin >> n;
    char c;
    int m;
    int first;
    int prev = -1;
    int prevC = -1;
    string s = "";
    int C = 0;
    int MAX = 1;
    cin >> m;
    if(m!=prev){
      C++;
    }else{
      C=1;
    }
    prev = m;
    first = m;
    prevC= C;
    s += to_string(C) + " ";
    for(int i=1;i<n-1;i++){
        cin >> m;
        if(m!=prev){
          if(prevC!=1)
            C=1;
          else
            C++;
        }
        if(m==prev){
          C=1;
        }
        prev = m;
        prevC = C;
        MAX = max(C,MAX);
        s += to_string(C) + " ";
    }
    cin >> m;
    if(m!=prev){
      C++;
    }else{
      C=1;
    }
    if(C==1 && m!=first){s += "2"; MAX = max(MAX,2);}
    else if(m==first && prevC!=1){s += "1";}
    else{
      s += to_string(C);
      MAX = max(C,MAX);
    }
    cout << MAX << "\n";
    cout << s;
    cout << "\n";
  }
}
