#include <bits/stdc++.h>

using namespace std;

int V,P;
vector<int> Vi;

inline int Abs(int a,int b){
  return max(a,b)-min(a,b);
}

int getDis(int l,int r){
  int sum = 0;
  for(int i=l+1;i<r;i++)
    sum += min(Abs(Vi.at(i),Vi.at(l)),Abs(Vi.at(i),Vi.at(r)));
  return sum;
}

int solve(int v,int p){
  cout << v << "\t" << p << "\n";
  if(v<=p ||v==0)return 0;
  int MIN = INT_MAX;
  for(int i=v-1;i>=0;i--){
    int Min = solve(i,p-1) + getDis(i,v);
    MIN = min(MIN,Min);
  }
  cout << "MIN" << MIN << "\n";
  return MIN;
}

int main(){
  cin >> V >> P;
  Vi.push_back(0);
  for(int i=0;i<V;i++){
    int pos;
    cin >> pos;
    Vi.push_back(pos);
  }
  cout << solve(V,P);
}
