#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adjList(1e5,vector<pair<int,int>>());
int prefL[(int)1e5];
int prefR[(int)1e5];
int arr[(int)1e5];
bool visited[(int)1e5];
int pos = 1;

void DFS(int src,int prev){
  visited[src]=true;
  for(pair<int,int> p:adjList.at(src))
    if(p.first!=prev){
      arr[pos++] = p.second;
      DFS(p.first,src);
    }
}

int travelTime(int n,int m,int l,int a[],int b[],int t[]){
  for(int i=0;i<m;i++){
    adjList.at(a[i]).push_back({b[i],t[i]});
    adjList.at(b[i]).push_back({a[i],t[i]});
  }
  vector<int> ans;
  for(int i=0;i<n;i++){
      if(visited[i])continue;
      pos = 1;
      DFS(i,-1);
      for(int i=1;i<pos;i++){
        prefL[i] = prefL[i-1]+arr[i];
//         cout << prefL[i] << "\t";
      }
//       cout << "\n";
      for(int i=pos-2;i>=0;i--){
        prefR[i] = prefR[i+1]+arr[i+1];
//         cout << prefR[i] << "\t";
      }
//       cout << "\n";
      int MIN = INT_MAX;
      for(int i=0;i<pos;i++){
        MIN = min(MIN,max(prefL[i],prefR[i]));
      }
      ans.push_back(MIN);
//       cout << MIN << "\n";
  }
  cout << ans[0]+l+ans[1] << "\n";
  return ans[0]+l+ans[1];
}

int main(){
  int n,m,l;
  cin >> n >> m >> l;
  int a[m];
  int b[m];
  int t[m];
  for(int i=0;i<m;i++){
    cin >> a[i] >> b[i] >> t[i];
  }
  travelTime(n,m,l,a,b,t);
}
