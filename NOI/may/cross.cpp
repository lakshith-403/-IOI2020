#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int arr[2000001];
int mem[1000000];

int main(){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++)
    cin >> mem[i];
  for(int i=0;i<m;i++){
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += 1000000;
    x2 += 1000000;
    if(max(x1,x2)-min(x1,x2)<=1)continue;
    arr[min(x1,x2)+1] += 1;
    arr[max(x1,x2)] -= 1;
  }
  for(int i=1;i<2000001;i++)
    arr[i] += arr[i-1];
  long long ans = 0;
  for(int i=0;i<n;i++)
    ans += arr[mem[i]+1000000];
  cout << ans << "\n";
}
