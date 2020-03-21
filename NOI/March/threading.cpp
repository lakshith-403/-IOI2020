#include <bits/stdc++.h>

using namespace std;
list<int> q;
bool mem[(int)pow(10,8)];
int main(){
  // ifstream in("input.in");
  int n;
  cin >> n;
  int i;
  for(i=1;i<=n;i++){
    string s;
    cin >> s;
    int x;
    cin >> x;
    if(s=="RUN")
    {
      if(mem[x]){cout << i << endl; break;}
      q.push_back(x);
      mem[x] = true;
    }
    if(s=="END"){
      if(q.back()==x){q.pop_back();mem[x]=false;}
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
