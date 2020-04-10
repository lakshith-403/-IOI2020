#include <bits/stdc++.h>

using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    long long n,x;
    cin >> n >> x;
    vector<int> vec;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    int Count = 0;
    long double mean = 0;
    long long sum = 0;
    for(int i=n-1;i>=0;i--){
      sum += vec.at(i);
      Count++;
      mean = sum/Count;
      if(mean < x)break;
    }
    if(mean<x)Count--;
    cout << Count << "\n";
  }
}

/*
Attention:
LONG LONG
*/
