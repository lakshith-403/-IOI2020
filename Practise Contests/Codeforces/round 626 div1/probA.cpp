#include <bits/stdc++.h>

using namespace std;

vector<char> seq;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long sum = 0;
  int tt = clock();
  for(int i=0;i<1000000000;i++)
    sum +=i;
  cout << clock()-tt;
}
