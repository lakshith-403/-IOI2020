#include <bits/stdc++.h>

using namespace std;
int N,M,Q
vector<pair<int,int>> E(100001,pair<int,int>());
int D[200001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ifstream in("in\\01-01.txt");
  ofstream out("01-01.txt");
  in >> N >> M >> Q;
  for(int i=1;i<N;i++){
    int x,y;
    in >> x >> y;
    E.at(i)={x,y};
  }
  for(int i=1;i<M;i++)
    in >> D[i];
  in >> Q;
  
}
