#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n,p,k;
    cin >> n >> p >> k;
    vector<int> vec;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    int lastIndex = -1;
    int mem[n+1];
    int MAX = 0;
    if(vec.at(0)>=p)MAX = 1;
    for(int i=0;i<=n;i++)
      mem[i]=0;
    for(int i=0;i<k;i++)
      if(vec.at(i)>=p)mem[i]=1;
    for(int i=0;i<n-k;i++){
      if(vec.at(i)+vec.at(i+k)<=p){
        mem[i+k] = mem[i]+k;
        MAX = max(MAX,mem[i+k]);
      }else break;
    }
    cout << MAX << "\n";
  }
}
