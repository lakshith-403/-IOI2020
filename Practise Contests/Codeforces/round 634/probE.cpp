#include <bits/stdc++.h>
#define ll long long

using namespace std;

int arr[201][2001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i=0;i<=201;i++)
      for(int j=0;j<=n;j++)
        arr[i][j] = 0;
    for(int i=1;i<=n;i++){
      int a;
      cin >> a;
      for(int j=1;j<=201;j++)
        arr[j][i]=arr[j][i-1];
      arr[a][i]++;
    }
    // cout << "___\n";
    // for(int i=1;i<=201;i++){
    //   for(int j=1;j<=n;j++)
    //     cout << arr[i][j] << "\t";
    //   cout << "\n";
    // }
    int MAX = 0;
    // int a = 1;
    for(int a=1;a<=201;a++)
    for(int i=1;i<=n;i++){
      for(int j=i+2;j<=n;j++){
        int x = min(arr[a][i],arr[a][n]-arr[a][j-1]);
        int localM = 0;
        for(int k=1;k<=201;k++){
          if(k==a)continue;
          localM = max(arr[k][j-1]-arr[k][i],localM);
        }
        // if(i==2 && j==7)
        // cout << localM << "+\n";
        MAX = max(MAX,localM+x+x);
      }
    }
    cout << MAX << "\n";
  }
}
