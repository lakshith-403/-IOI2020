/*
ID: lakshit4
PROG: fence
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

ifstream in("fence.in");
ofstream out("fence.out");

vector<vector<int>> graph(501,vector<int>());

vector<int> path;

void deleteNode(int a,int b){
  int i;
  for(i=0;i<graph.at(a).size();i++)
    if(graph.at(a).at(i)==b)
      break;
  graph.at(a).erase(graph.at(a).begin()+i);
  for(i=0;i<graph.at(b).size();i++)
    if(graph.at(b).at(i)==a)
      break;
  graph.at(b).erase(graph.at(b).begin()+i);
}

void etour(int src){
  if(graph.at(src).empty()){
    path.push_back(src);
    return;
  }
  while(!graph.at(src).empty()){
    int j = graph.at(src).front();
    deleteNode(src,j);
    etour(j);
  }
  path.push_back(src);
}

int F;
int main(){
  in >> F;
  int f = F;
  while(f--){
    int i,j;
    in >> i >> j;
    graph.at(i).push_back(j);
    graph.at(j).push_back(i);
  }
  int i;
  for(i=0;i<graph.size();i++){
    sort(graph.at(i).begin(),graph.at(i).end());
  }
  for(i=0;i<graph.size();i++){
    if(graph.at(i).size()%2==1)break;
  }
  if(i==graph.size())i=1;
  etour(i);
  cout << path.size() << " shit";
  for(i=path.size()-1;i>=0;i--)
    out << path.at(i) << endl;
}
