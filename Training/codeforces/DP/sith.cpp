#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

std::string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

int n;

double prob[19][19];

double dp[262144][19];
//dp[i][j]  ~ i'th bitmask of siths have fought and j left alive

double fight(int mask,int i){
  double ans = 0.0;
  for(int j=0;j<n;j++){
    if((mask & (1<<j))!=0)continue;
    if(i==j)continue;
    double localMax = (fight(mask|(1<<j),i)*prob[i][j])+(fight(mask|(1<<j),j)*prob[j][i]);
    ans = max(ans,localMax);
    cout << localMax << "\n";
  }
  if(ans==0.0)ans=1.0;
  return ans;
}

int main(){
  io_setup();
  cin >> n;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)cin >> prob[i][j];
  cout << fight(0,0);
}
