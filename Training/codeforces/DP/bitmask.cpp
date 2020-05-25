#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

const vector<int> PRIMES = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
int n;
int arr[101];

int Abs(int a, int b){
  return max(a,b) - min(a,b);
}

int getPrimeFact(int n){
  vector<bool> flag(PRIMES.size(),false);
  while(n>1)
    for(int i=0;i<PRIMES.size();i++){
      int p = PRIMES[i];
      if(n%p==0){
        n/=p;
        flag[i]=true;
        break;
      }
    }
  int ans = 0;
  for(int i=0;i<PRIMES.size();i++)if(flag[i])ans += (int)pow(2,i);
  return ans;
}

int dp[131073][61];
int mem[131073][61];

int solve(int prevMask , int pos){
  if(pos==n)return 0;
  if(dp[prevMask][pos]!=-1){return dp[prevMask][pos];}
  int Min = INT_MAX;
  for(int i=1;i<61;i++){
    int primeMask = getPrimeFact(i);
    if((primeMask & prevMask) != 0)continue;
    int temp = Abs(arr[pos],i)+solve(primeMask^prevMask,pos+1);
    if(Min>temp){
      Min = temp;
      mem[prevMask][pos] = i;
    }
  }
  return dp[prevMask][pos]=Min;
}

int main(){
  io_setup();
  cin >> n;
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i++)cin >> arr[i];
  cout << solve(0,0) << "\n";
  int cur = 0;
  for(int i=0;i<n;i++){
    cout << mem[cur][i] << " ";
    cur = getPrimeFact(mem[cur][i]);
  }
  cout << "\n";
}
