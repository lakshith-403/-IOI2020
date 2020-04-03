#include <bits/stdc++.h>

using namespace std;
bool place[500];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    for(int i=0;i<500;i++)
      place[i]=false;
    int n,x;
    cin >> n >>x;
    vector<int> vec;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      place[a] = true;
    }
    int i;
    for(i=1;i<=500;i++){
      if(!place[i] && x>0){
        x--;
      }else if(!place[i] && x<=0){
        break;
      }
    }
    cout << i-1 << "\n";
  }
}
