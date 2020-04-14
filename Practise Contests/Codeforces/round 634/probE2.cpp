#include <bits/stdc++.h>
#define ll long long

using namespace std;

int arr[201][200001];

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
    int maxA = 1;
    int M = 0;
    for(int i=1;i<=n;i++){
      int a;
      cin >> a;
      for(int j=1;j<=201;j++)
        arr[j][i]=arr[j][i-1];
      arr[a][i]++;
      M = max(arr[a][i],M);
      maxA = max(a,maxA);
    }
    // cout << "___\n";
    // for(int i=1;i<=201;i++){
    //   for(int j=1;j<=n;j++)
    //     cout << arr[i][j] << "\t";
    //   cout << "\n";
    // }
    int MAX = 0;
    // int a = 1;
    for(int a=1;a<=maxA;a++)
    for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        int x = min(arr[a][i],arr[a][n]-arr[a][j-1]);
        if(x==0 || x+M < MAX)continue;
        int localM = 0;
        for(int k=1;k<=maxA;k++){
          // if(k==a)continue;
          localM = max(arr[k][j-1]-arr[k][i],localM);
        }
        // if(i==2 && j==7)
        // cout << localM << "+\n";
        MAX = max(MAX,localM+x+x);
      }
    }
    if(MAX==0&&n!=0)MAX = 1;
    cout << MAX << "\n";
  }
}
