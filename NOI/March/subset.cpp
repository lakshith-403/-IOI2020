#include <bits/stdc++.h>

using namespace std;
int arr[1001];
int subarr[1001][1001];

int main(){
  int n,sum;
  cin >> n >> sum;
  for(int i=0;i<n;i++)
    cin >> arr[i];

  for (int i = 0; i <= n; i++)
    subarr[i][0] = 1;
   for (int i = 1; i <= n; i++)
     for (int j = 1; j <= sum; j++){
       if(j<arr[i-1])
          subarr[i][j] = subarr[i-1][j];
       if (j >= arr[i-1])
          subarr[i][j] = subarr[i-1][j] + subarr[i - 1][j-arr[i-1]];
     }

  cout << subarr[n][sum];
}
