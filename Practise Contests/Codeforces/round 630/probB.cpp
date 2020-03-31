#include <bits/stdc++.h>

using namespace std;
bool mem[1001];
int Count[1001];
int temp[1001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  int C = 1;
  int GG = 0;
  for(int i=2;i<=500;i++){
    bool flag = false;
    for(int j=2;j*i<=1000;j++){
      if(Count[j*i]==0)
      {
        Count[j*i]=C;
        flag = true;
      }

    }
    if(flag)C++;
  }
  while(t--){
    int n;
    cin >> n;
    vector<int> vec;
    map<int,int> M;
    int CC = 1;
    int MAX = INT_MIN;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      if(M.count(Count[a])==0){
        M.insert(pair<int,int>(Count[a],CC));
        CC++;
      }
      MAX = max(M.at(Count[a]),MAX);
      vec.push_back(M.at(Count[a]));
    }
    cout << MAX << "\n";
    for(int i=0;i<vec.size()-1;i++)
      cout << vec.at(i) << " ";
    cout << vec.at(vec.size()-1) << "\n";
  }
}
