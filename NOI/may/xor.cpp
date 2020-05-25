#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int prefArr[100001][32];
int n,k;
int main(){
  io_setup();
  cin >> n;
  for(int i=1;i<=n;i++){
    int a;
    cin >> a;
    int index = 0;
    while(a!=0) {prefArr[i][index++]=(a%2==0 ?0:1); a/=2;}
  }
  for(int i=0;i<32;i++)
    for(int j=2;j<=n;j++)
      prefArr[j][i]+=prefArr[j-1][i];
  cin >> k;
  vector<char> ans;
  while(k--){
    int l,r;
    cin >> l >> r;
    l++;  r++;
    string numS = "";
    for(int i=0;i<31;i++)
      numS = ((prefArr[r][i]-prefArr[l-1][i])%2==1?"1":"0") + numS;
    int num = (stoi(numS, nullptr, 2)%94)+33;
    ans.push_back(static_cast<char>(num));
  }
  for(char c:ans)cout << c;
  cout << "\n";
}
