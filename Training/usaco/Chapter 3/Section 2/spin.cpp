/*
ID: lakshit4
PROG: spin
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int s[5];
std::vector<std::vector<pair<int,int>>>  w;

bool checklight(int n){
  int mem[360];
  for(int i=0;i<360;i++)
    mem[i] = 0;
  for(int i=0;i<5;i++)
    for(pair<int,int> p : w.at(i))
      for(int j=(s[i]*n)+p.first;j<=(s[i]*n)+p.first+p.second;j++){
        int temp = j % 360;
        mem[temp]++;
      }
  for(int i=0;i<360;i++)
    if(mem[i]==5)return true;
  return false;
}

int main(){
  ifstream in("spin.in");
  ofstream out("spin.out");
  for(int i=0;i<5;i++){
    in >> s[i];
    int t;
    in >> t;
    vector<pair<int,int>> vec;
    while(t--){
      int start,width;
      in >> start >> width;
      vec.push_back({start,width});
    }
    w.push_back(vec);
  }
  for(int i=0;i<=360;i++)
    if(checklight(i)){out << i << endl; return 0;}
  out << "none" << endl;
}
