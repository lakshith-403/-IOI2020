#include <bits/stdc++.h>
using namespace std;
bool checkPrime(long n){
  if(n<=1)return false;
  if(n<=3)return true;
  if(n%2==0 || n%3==0)return false;
  for(int i=5;i<=(int)sqrt(n);i+=6)
    if(n%i==0 || n%(i+2)==0)return false;
  return true;
}
vector<long> vec;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long a,b;
  cin >> a >> b;
  if(a!=2 && b!=2)
  vec.push_back(2);
  int A,B;
  for(int i=-2;i<=2;i+=2){
    if(i==0)
      A = vec.size(),B = vec.size()+1;
    if(checkPrime(a+i))
      vec.push_back(a+i);
    if(checkPrime(b+i))
    vec.push_back(b+i);
  }
  bool graph[vec.size()][vec.size()];
  bool visited[vec.size()];
  for(int i=0;i<vec.size();visited[i++]=false);
  for(int i=0;i<vec.size();i++)
    for(int j=0;j<vec.size();j++)
      if(checkPrime(max(vec.at(i),vec.at(j))-min(vec.at(i),vec.at(j))))
        graph[i][j] = true;
      else
        graph[i][j] = false;
  queue<pair<int,string>> q;
  q.push({A,to_string(vec.at(A))+" "});
  string path = "-1";
  int Count = 0;
  while(!q.empty()){
    Count ++;
    pair<int,string> p = q.front();
    if(p.first==B){path=p.second;break;}
    visited[p.first]=true;
    q.pop();
    for(int i=0;i<vec.size();i++)
      if(graph[p.first][i] && !visited[i])q.push({i,p.second+to_string(vec.at(i))+" "});
  }
  if(path=="-1"){
    cout << -1 << "\n";
  }else{
    cout << Count << "\n" << path << "\n";
  }
}
