#include <bits/stdc++.h>

using namespace std;
int Count[4*(int)pow(10,5)];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q,x;
  cin >> q >> x;
  // Count[0]=-1;
  // int prevMin = 0;
  set<pair<int, int>> vals;
	for (int i = 0; i < x; ++i) {
		vals.insert(make_pair(Count[i], i));
	}
  for(int i=0;i<q;i++){
    int a;
    cin >> a;
    int ans = 0;
    // int MIN = INT_MAX;
    int b = a%x;
    vals.erase(make_pair(Count[b], b));
    Count[b]++;
		vals.insert(make_pair(Count[b], b));
    // for(int j=0;j<x;j++){
    //   MIN = min(MIN,Count[j]);
    //   if(MIN==pevMin)break;
    // }
    // prevMin = MIN;
    int MIN = vals.begin()->first;
    // if(MIN==-1){
    //   cout << 0 << "\n";
    //   continue;
    // }
    ans = x*MIN;
    // int j;
    // for(j=1;j<x;j++){
    //   if(Count[j]-MIN==0)break;
    // }
    ans += vals.begin()->second;
    cout << ans << "\n";
  }
}
