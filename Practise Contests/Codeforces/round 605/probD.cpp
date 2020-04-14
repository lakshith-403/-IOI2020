#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a[200001];
int S[200001];
int E[2000001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int prev = -1;
  int s=0,e=-1;
  int MAX = INT_MIN;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  int Count = 0;
  s=0;
  for(int i=0;i<n;i++){
    if(i==0){
      Count++;
    }else if(a[i]>a[i-1]){
      Count++;
      // cout << Count << "+ " << i<<"\n";
    }else{
      MAX = max(MAX,Count);
      S[s]=Count;
      E[s+Count-1]=Count;
      s+=Count;
      Count=1;
    }
  }
  S[s]=Count;
  E[n-1]=Count;
  MAX = max(MAX,Count);
  // for(int i=0;i<n;i++)
  //   cout << S[i] << "\t";
  // cout << "\n";
  // for(int i=0;i<n;i++)
  //   cout << E[i] << "\t";
  // cout << "\n";
  for(int i=0;i<n-2;i++){
    if(a[i]>=a[i+2])continue;
    // cout << i << "\n";
    MAX = max(MAX,E[i+1] - (a[i]<a[i+1]?1:0)+S[i+2]);
    MAX = max(MAX,E[i] - (a[i+1]<a[i+2]?1:0) + S[i+1]);
  }
  cout << MAX << "\n";
}

/*
ATTENTION
*
*/
