
#include <bits/stdc++.h>

using namespace std;

int n,x;
int main(){
  int tc;
  cin >> tc;
  while(tc--){
      cin >> n >> x;
      int num;
      vector<int> vec;
      for(int i=0;i<n;i++){
        cin >> num;
        vec.push_back(num);
      }
      // sort(vec.begin(),vec.end());
      int count = 1;
      int MAX = INT_MIN;
      int i;
      for(i=0;i<n;i++){
        // if(vec.at(i) + sum >= x)break;
        // sum += vec.at(i);
        // count++;
        if(vec.at(i)==x){
          std::cout << 1 << '\n';
          break;
        }
        MAX = max(vec.at(i),MAX);
      }

      if(i!=n)
        continue;

      if(x/MAX<=1)
        cout << 2 << endl;
      else
        cout << ((x%MAX==0) ? (x/MAX) : (x/MAX)+1) << endl;
  }
}
