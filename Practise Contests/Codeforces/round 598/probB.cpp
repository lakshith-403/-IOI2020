#include <bits/stdc++.h>

using namespace std;

int arr[101];
int ans[101];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
      cin >> arr[i];
    }
    int cur=1,l=0;
    for(int i=l;i<n;i++){
      if(arr[i]==cur){
        ans[l]=cur;
        l=i;
      }else
      ans[i+1] = arr[i];
    }
    for(int i=l+1;i<n;i++){
      if(arr[i]==cur){
        arr[l]=cur
      }
    }
    for(int i=0;i<n;i++)
      cout << ans[i] << "\t";
    cout << "\n";
  }
}
