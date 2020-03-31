#include <bits/stdc++.h>

using namespace std;
string alph = "abcdefghijklmnopqrstuvwxyz";
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >>t;
  while(t--){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<set<int>> vec;
    bool b[n];
    for(int i=0;i<n;i++)b[i]=false;
    for(int i=0;i<n-k;i++){
      if(b[i])continue;
      set<int> temp;
      for(int j=0;i+j*k<n;j++){
          if(!b[i+j*k])
          temp.insert(i+j*k);
          if(!b[n-1-(i+j*k)])
          temp.insert(n-1-(i+j*k));
          b[n-1-(i+j*k)] = true;
          b[i+j*k] = true;
        }
      vec.push_back(temp);
    }
    int ans = 0;
    for(set<int> st : vec){
      set <int> :: iterator itr;
      int ac[27];
      for(int i=0;i<27;i++)
        ac[i]=0;
      for (itr = st.begin(); itr != st.end(); ++itr)
      {
          for(int i=0;i<27;i++)
            if(s[*itr]==alph[i]){
              ac[i]++;
              break;
            }
      }
      int MAX = INT_MIN;
      for(int i=0;i<27;i++)
        MAX = max(MAX,ac[i]);
      ans += st.size()-MAX;
    }
    cout << ans << "\n";
  }
}
