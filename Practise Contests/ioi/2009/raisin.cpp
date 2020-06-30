#include <bits/stdc++.h>
#define pi pair<int,int>
#define f first
#define s second

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

const int MAX = 51;

int arr[MAX][MAX];
int pref[MAX][MAX];
int mem[MAX][MAX][MAX][MAX];

int getSum(pi a,pi b){
  return pref[b.f][b.s]-pref[a.f-1][b.s]-pref[b.f][a.s-1]+pref[a.f-1][a.s-1];
}

int solve(pi a,pi b){
  if(a.f==b.f && b.s==a.s)return 0;
  if(mem[a.f][a.s][b.f][b.s]!=0)return mem[a.f][a.s][b.f][b.s];
  int MIN = INT_MAX;
  int sum = getSum(a,b);
  //check all possible cuts recursively
  for(int i=a.f;i<b.f;i++){
    int temp = solve({a.f,a.s},{i,b.s}) + solve({i+1,a.s},{b.f,b.s});
    MIN = min(MIN,temp);
  }
  for(int i=a.s;i<b.s;i++){
    int temp = solve({a.f,a.s},{b.f,i}) + solve({a.f,i+1},{b.f,b.s});
    MIN = min(MIN,temp);
  }
  mem[a.f][a.s][b.f][b.s] = MIN+sum;
  return MIN+sum;
}

int main(){
  io_setup();
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin >> arr[i][j];
  //calculate pref sum
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + arr[i][j];
  
  cout << solve({1,1},{n,m}) << "\n";
}
