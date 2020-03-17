#include <bits/stdc++.h>

using namespace std;
int n,d;
int a[101];
int main(){
  int tc;
  cin >> tc;
  while(tc--){
      cin >> n >>d;
      for(int i=0;i<n;i++){
        cin >> a[i];
      }

      for(int i=1;i<n;i++){
        while(true){
          if(a[i]==0){
            break;
          }
          if(d-i<0)break;
          a[i]--;
          a[0]++;
          d = d - i;
        }
      }
      cout << a[0] << endl;
  }
}
