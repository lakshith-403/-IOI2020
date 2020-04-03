#include <bits/stdc++.h>

using namespace std;
int Left[2*(int)pow(10,5)+1];
int Right[2*(int)pow(10,5)+1];

bool memL[2*(int)pow(10,5)+1];

bool memR[2*(int)pow(10,5)+1];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i=0;i<=n;i++)
      memL[i] = false,memR[i]=false;
    int Count = 0;
    int total = 0;
    int sum = 0;
    vector<int> vec;
    bool b = false;
    for(int i=1;i<=n;i++){
      int a;
      cin >> a;
      vec.push_back(a);
      if(Left[a]==t+1)b = true;
      if(b)continue;
      sum += a;
      total += i;
      Left[a]=t+1;
      if(a<=i && sum==total)
      {
          memL[i]=true;}
    }
    total =0;
    sum = 0;
    for(int i=1;i<=n;i++){
      int j=n-i;
      int a = vec.at(j);
      if(Right[a]==t+1)break;
      sum += a;
      total += i;
      Right[a]=t+1;
      if(a<=i && sum==total)
      {
        // cout << j+1 << "\n";
        memR[j+1]=true;}
    }
    string s = "";
    for(int i=1;i<n;i++){
      if(memL[i] && memR[i+1]){
        Count ++;
        s += to_string(i) + " " + to_string(n-i) + "\n";
      }
    }
    cout << Count << "\n";
    cout << s;
  }
}
