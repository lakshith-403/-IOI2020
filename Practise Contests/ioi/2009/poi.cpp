#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

struct data{
  int score;
  int num;
  int id;
};


int s[2000];
int C[2000][2000];
vector<data> vec;

bool compare(data d1,data d2){
  if(d1.score!=d2.score)return d1.score>d2.score;
  if(d1.num!=d2.num)return d1.num>d2.num;
  return d1.id < d2.id;
}

int main(){
  io_setup();
  int n,t,p;
  cin >> n >> t >> p;
  for(int i=0;i<n;i++){
    for(int j=0;j<t;j++){
      cin >> C[i][j];
      if(C[i][j]==0)s[j]++;
    }
  }
  for(int i=0;i<n;i++){
    int sum=0,Count=0;
    for(int j=0;j<t;j++)
      if(C[i][j]==1)sum += s[j],Count++;
    vec.push_back({sum,Count,i});
  }
  sort(vec.begin(),vec.end(),compare);
  p--;
  for(int i=0;i<n;i++){
    if(vec.at(i).id==p){cout <<  vec.at(i).score << " " << i+1 << "\n";break;}
  }
  return 0;
}
