#include <bits/stdc++.h>
#define ll long long

using namespace std;
int Count[200001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int MAX = INT_MIN;
    for(int i=0;i<=n;i++){
      Count[i]=0;
    }
    int index = -1;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      Count[a]++;
      MAX = max(Count[a],MAX);
    }
    int singles = 0;
    for(int i=0;i<=n;i++){
      if(Count[i]>0)singles++;
    }
    cout << max(min(singles,MAX-1),min(singles-1,MAX)) << "\n";
  }
}

/*
    `-.    .-'
       :  :
    --:--:--
     :  :
  .-'    `-.  ~LaKsHiTh_
*/
