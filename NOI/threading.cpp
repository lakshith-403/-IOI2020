#include <bits/stdc++.h>

using namespace std;
list<int> q;
int main(){
  int n;
  cin >> n;
  int i;
  for(i=1;i<=n;i++){
    string s;
    cin >> s;
    int x;
    cin >> x;
    if(s=="RUN")
      q.push_back(x);
    if(s=="END"){
      if(q.back()==x)q.pop_back();
      else{
        cout << i << endl;
        break;
      }
    }
  }
  if(i==n+1)
    if(q.size()==0)cout << 0 << endl;
    else cout << n+1 << endl;
}
