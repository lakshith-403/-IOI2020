#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    int MAX = 0;
    int arr[n];
    for(int i=1;i<=n;i++)
      cin >> arr[i];
    for(int i=1;i<=n;i++){
      int b= arr[i];
      cout << MAX + b << " ";
      if(b>0)
        MAX+=b;
    }
    cout << endl;
  
}
