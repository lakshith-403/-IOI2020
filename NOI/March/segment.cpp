#include <bits/stdc++.h>

using namespace std;

int totalSize = 0;
int sizes[100001];
int arr[100001][1001];

int main(){
  int n;
  cin >> n;
  int MAX = INT_MIN;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    sizes[i] = a;
    MAX = max(MAX,a);
  }
  cout << MAX << "\n";
  for(int i=0;i<n*MAX;i+=MAX)
    cout << i << " ";
    cout << endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<sizes[i];j++){
      int a;
      cin >> a;
      cout << a << " ";
    }
    for(int j=0;j<MAX-sizes[i];j++){
      cout << 0 << " ";
    }
  }
}
