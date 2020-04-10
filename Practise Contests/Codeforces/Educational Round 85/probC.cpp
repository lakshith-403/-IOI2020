#include <bits/stdc++.h>
#define INF 1000000000001

using namespace std;

long long A[300001];
long long a[300001];
long long B[300001];
long long C[300001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
      cin >> A[i];
      cin >> B[i];
      a[i] = A[i];
    }
    int minIndex = 0;
    long long MIN = INF;
    long long sum = 0;
    for(int i=0;i<n;i++){
      if(i==n-1){
        B[i] = min(B[i],A[0]);
        A[0]-=B[i];
        if(a[0]-A[0]<MIN){
          MIN = a[0]-A[0];
          minIndex = 0;
        }
        sum+=A[0];
      }
      else{
        B[i] = min(B[i],A[i+1]);
        A[i+1]-=B[i];
        if(a[i+1]-A[i+1]<MIN){
          MIN = a[i+1]-A[i+1];
          minIndex = i+1;
        }
        sum+=A[i+1];
      }
    }
    sum+=a[minIndex]-A[minIndex];
    cout << sum << "\n";
  }
}
/*
Attention:
LONG LONG
*/
