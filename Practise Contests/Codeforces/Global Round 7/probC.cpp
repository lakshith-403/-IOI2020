#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >>k;
    vector<int> vec;
    int Count = 0;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      if(a>n-k){
        vec.push_back(Count);
        Count=0;
      }else{
        Count++;
      }
    }
    long long sum = 1;
    for(int i=1;i<vec.size();i++){
      sum *= vec.at(i)+1;
      sum %= 998244353;
    }
    long long MAX = 0;
    for(int i=n;i>n-k;i--)
      MAX += i;
    cout << MAX << " " << sum << endl;
}
