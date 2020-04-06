#include <bits/stdc++.h>

using namespace std;

int H,W,N,K;
int MIN = INT_MAX;
int MAX = INT_MIN;
double mean;
int grid[201][201];
int votes[10001];
int check[10001][10001];
int Check[10001];
int Ans[10001];
bool gridCheck[10001][10001];
vector<vector<int>> adjList(10001,vector<int>());
vector<vector<int>> adjOut(10001,vector<int>());

bool compare(int a,int b){
  return votes[a]<votes[b];
}

void DFS(int node,int dis){
  if(Ans[node]!=0)return;
  Ans[node] = dis;
  for(int x:adjOut.at(node))
    DFS(x,dis);
}

int main(){
  // ios_base::sync_with_stdio(false);
  // in.tie(NULL);
  ifstream in("in\\01.txt");
  ofstream out("01.txt");
  in >> H >> W >> N >> K;
  cout << H << " " << W << " " << N << " " << K << "\n";
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      in >> grid[i][j];
      cout << grid[i][j] << " ";
    }
    cout << "\n";
  }
  int sum = 0;
  for(int i=1;i<=N;i++){
    in >> votes[i];
    cout << votes[i] << "\n";
    sum += votes[i];
    MIN = min(votes[i],MIN);
    MAX = max(votes[i],MAX);
  }
  for(int i=1;i<=N;i++)gridCheck[i][i] = true;
  int C = 0;
  for(int i=1;i<=H;i++)
    for(int j=1;j<=W;j++){
      if(i!=1 && !gridCheck[grid[i][j]][grid[i-1][j]]){
        adjList.at(grid[i][j]).push_back(grid[i-1][j]);
        gridCheck[grid[i][j]][grid[i-1][j]] = true;
        C++;
      }
      if(i!=H && !gridCheck[grid[i][j]][grid[i+1][j]]){
        adjList.at(grid[i][j]).push_back(grid[i+1][j]);
        gridCheck[grid[i][j]][grid[i+1][j]] = true;
        C++;
      }
      if(j!=1 && !gridCheck[grid[i][j]][grid[i][j-1]]){
        adjList.at(grid[i][j]).push_back(grid[i][j-1]);
        gridCheck[grid[i][j]][grid[i][j-1]] = true;
        C++;
      }
      if(j!=W && !gridCheck[grid[i][j]][grid[i][j+1]]){
        adjList.at(grid[i][j]).push_back(grid[i][j+1]);
        gridCheck[grid[i][j]][grid[i][j+1]] = true;
        C++;
      }
    }

  cout << C << "            0000000000000\n";
  for(int i=0;i<adjList.size();i++)
    sort(adjList.at(i).begin(),adjList.at(i).end(),compare);

  for(int i=1;i<=N;i++){
    vector<int> vec = adjList.at(i);
    for(int x: vec)
      cout << x << "\t";
    cout << "\n";
  }
  // return 0;
  int k = N;
  mean = (double)sum / N;
  int pos = 0;
  int dis = 1;
  while(k>K){
    cout << k <<" <+> " << K << "\n";
    // cout << check[pos] << "\n";
    pos++;
    if(pos>=N)pos=0;
    if(Check[pos]!=0)
      dis = Check[pos];
    else
    Check[pos] = dis;
    int i;
    if(votes[pos]>=mean)
      for(i=0;i<adjList.at(pos).size();i++){
        if(check[adjList.at(pos).at(i)][pos]==0){
          check[adjList.at(pos).at(i)][pos] = dis;
          check[pos][adjList.at(pos).at(i)] = dis;
          Check[adjList.at(pos).at(i)] = dis;
          adjOut.at(pos).push_back(adjList.at(pos).at(i));
          // cout << adjList.at(pos).at(i) <<" <> " << dis << "\n";
          break;
        }
      }
    else
      for(i=adjList.at(pos).size()-1;i>=0;i--){
        if(check[adjList.at(pos).at(i)][pos]==0){
          check[adjList.at(pos).at(i)][pos] = dis;
          check[pos][adjList.at(pos).at(i)] = dis;
          Check[adjList.at(pos).at(i)] = dis;
          adjOut.at(pos).push_back(adjList.at(pos).at(i));
          // cout << adjList.at(pos).at(i) <<" <> " << dis << "\n";
          break;
        }
      }
    if(i!=-1 && i!=adjList.at(pos).size())k--;
    // out << k << "+++\n";
    dis++;
  }
  // for(int i=1;i<=N;i++)
    // if(Check[i]==0)Check[i] = dis++;
  // for(int i=1;i<=N;i++)
    // out << Check[i] << "\n";
  int col = 1;
  for(int i=1;i<=N;i++){
    if(Ans[i]!=0)continue;
    DFS(i,col);
    col++;
  }
  for(int i=1;i<=N;i++)
    out << Ans[i] << "\n";
}
