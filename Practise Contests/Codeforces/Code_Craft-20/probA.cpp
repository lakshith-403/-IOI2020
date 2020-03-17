#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
      int n,m;
      cin >> n>> m;
      int sum = 0;
      for(int i=0;i<n;i++){
        int s;
        cin >> s;
        sum += s;
      }
      cout << min(sum,m) << endl;
    }
}
