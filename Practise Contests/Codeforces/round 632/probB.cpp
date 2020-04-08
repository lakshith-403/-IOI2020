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
    int a[n];
    int b[n];
    int minNeg = INT_MAX;
    int minPos = INT_MAX;
    for(int i=0;i<n;i++){
      cin >> a[i];
      if(a[i]==-1)
        minNeg = min(minNeg,i);
      else if(a[i]==+1)
        minPos = min(minPos,i);
    }
    bool flag = true;
    for(int i=0;i<n;i++){
      cin >> b[i];
      if(b[i]>a[i] && minPos>=i)flag = false;
      else if(b[i]<a[i] && minNeg>=i)flag = false;
    }
    if(flag)cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}
