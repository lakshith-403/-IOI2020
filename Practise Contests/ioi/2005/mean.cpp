#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const int MAX = 1e6+5;
int arr[MAX];
int main(){
  io_setup();
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
    cin >> arr[i];
  for(int i=1;i<n;i++){
    if(arr[i]<arr[i-1]){cout << 0 << "\n";return 0;}
  }
  int a = arr[1]-arr[0]*2;
  if(a<0)a=0;
  cout << arr[0]+1+a << "\n";
}
