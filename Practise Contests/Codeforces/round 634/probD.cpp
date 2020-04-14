#include <bits/stdc++.h>
#define ll long long

using namespace std;
int arr[10][10];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    for(int i=1;i<=9;i++)
      for(int j=1;j<=9;j++){
        char c;
        cin >> c;
        arr[i][j] = c-'0';
        // cout << arr[i][j] << "+\n";
      }
    arr[1][1] = arr[1][3];
    arr[4][2] = arr[4][3];
    arr[7][3] = arr[7][1];

    arr[2][5] = arr[2][6];
    arr[5][6] = arr[5][4];
    arr[8][4] = arr[8][5];

    arr[3][9] = arr[3][7];
    arr[6][7] = arr[6][9];
    arr[9][8] = arr[9][7];

    for(int i=1;i<=9;i++){
      for(int j=1;j<=9;j++){
        cout << arr[i][j];
      }
      cout << "\n";
    }
  }
}
