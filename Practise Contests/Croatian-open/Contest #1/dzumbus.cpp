#include <bits/stdc++.h>

using namespace std;
int N,M,Q;
int D[1001];
vector<vector<int>> adjList(1001,vector<int>());
int DP[1001][1001][2];
bool visited[1001];
int start;
vector<int> S;
vector<int> chain;

int main(){
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  cin >> N >> M;
  for(int i=1;i<=N;i++)
    cin >> D[i];
  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    adjList.at(a).push_back(b);
    adjList.at(b).push_back(a);
  }
  cin >> Q;
  int MAX = INT_MIN;
  for(int i=0;i<Q;i++){
    int temp;
    cin >> temp;
    MAX = max(MAX,temp);
    S.push_back(temp);
  }
  // cout << "input" << "\n";
  for(int i=0;i<N;i++)
    if(adjList.at(i).size()==1){start = i;break;}
  int node = start;
  int Count = 0;
  chain.push_back(-1);
  while(Count<N){
    // cout << node << "\n";
    chain.push_back(node);
    visited[node] = true;
    if(!visited[adjList.at(node).at(0)])
      node = adjList.at(node).at(0);
    else if(adjList.at(node).size()>1)
      node = adjList.at(node).at(1);
    Count ++;
  }
  cout << "&" << chain.size() << endl;
  for(int i=1;i<=N;i++)
    cout << D[chain.at(i)] << "\n";
  for(int p=2;p<=N;p++){
    for(int k=0;k<=MAX;k++){
      DP[p][k][0] = max(DP[p-1][k][0],DP[p-1][k][1]);
      cout << "+" << k-D[chain.at(p)] << " " << k-D[chain.at(p)]-D[chain.at(p-1)] << "\n";
      int a=DP[p-1][k-D[chain.at(p)]][1]+1,b=DP[p-1][k-D[chain.at(p)]-D[chain.at(p-1)]][0]+2;
      if(k-D[chain.at(p)]<=0)
        a = 0;
      if(k-D[chain.at(p)]-D[chain.at(p-1)]<=0)
        b = 0;
      DP[p][k][1] = max(a,b);
    }
  }
  // for(int p=2;p<=N;p++){
  //   for(int k=0;k<=MAX;k++){
  //     DP[p][k][0] = max(DP[p-1][k][0],DP[p-1][k][1]);
  //     int a=DP[p-1][k-D[p]][1]+1,b=DP[p-1][k-D[p]-D[p-1]][0]+2;
  //     cout << "+" << k-D[p] << " " << k-D[p]-D[p-1] << "\n";
  //     if(k-D[p]<0)
  //       a = 0;
  //     if(k-D[p]-D[p-1]<0)
  //       b = 0;
  //     DP[p][k][1] = max(a,b);
  //   }
  // }
  for(int p=1;p<=N;p++){
    for(int k=0;k<=MAX;k++){
      cout << DP[p][k][0] << " "  << DP[p][k][1] << "\t";
    }
    cout << endl;
  }
  cout << "____________________________" << "\n";
  for(int i=0;i<Q;i++){
    cout << max(DP[N][S.at(i)][0],DP[N][S.at(i)][1]) << "\n";
  }
}
