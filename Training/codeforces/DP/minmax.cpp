/*
 *Problem 1288 D
 *Binary Search and Bitmask
 * ~ Lakshith_ 
*/


#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int arr[300001][8];
int masks[300001];
bool flag[1<<8];
int n,m;
vector<int> vec;

void setupMasks(int x){
  vec.clear();
  memset(flag,false,sizeof(flag));
  for(int i=0;i<n;i++){
    int mask = 0;
    for(int j=0;j<m;j++)
      if(arr[i][j]>=x)mask+=(int)pow(2,j);
    masks[i]=mask;
    if(!flag[mask])vec.push_back(i);
    flag[mask]=true;
  }
}

int main(){
  cin >> n >> m;
  int A = INT_MIN;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      cin >> arr[i][j];
      A = max(A,arr[i][j]);
    }
  int lo = 0;
  int hi = A;
  pair<int,int> ans;
  while(lo<=hi){
    int mid = lo+(hi - lo)/2;
    setupMasks(mid);
    bool checker = false;
    for(int i=0;i<vec.size();i++)
      for(int j=0;j<vec.size();j++){
        if((masks[vec.at(i)]|masks[vec.at(j)])==((1<<m)-1)){
          ans = {vec.at(i),vec.at(j)};
          checker = true;
        }
      }
      
    if(checker)lo=mid+1;
    if(!checker) hi = mid-1;
  }
  cout << ans.first+1 << " " << ans.second+1 << "\n";
  return 0;
}
