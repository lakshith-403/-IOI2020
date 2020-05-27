
#include <bits/stdc++.h> 
#define ll long long

using namespace std; 

bool compare(pair<int,int> p1, pair<int,int> p2){
  return p1.first<p2.first;
}

 
ll answerQueries(ll a[][2], int n, ll queries[], int q) { 
  ll Count = 0;

    vector<ll> v; 

    unordered_map<ll, ll> mpp; 
 
    for (int i = 0; i < n; i++) { 
        v.push_back(a[i][0]); 
        mpp[a[i][0]] = 1; 
        v.push_back(a[i][1]); 
        mpp[a[i][1]] = 2; 
    } 
 
    sort(v.begin(), v.end()); 
    for (int i = 0; i < q; i++) { 
        ll num = queries[i]; 
        int ind = lower_bound(v.begin(), v.end(), num) - v.begin(); 
        if (v[ind] == num) { 
            Count ++;
        } 
        else { 
            if (mpp[v[ind]] == 2) {
              Count++;
            }
        } 
    }
    return Count;
} 
int main() 
{ 
  int n,m;
  cin >> n >> m;
  ll q[n];
  vector<pair<ll,ll>> M;
  vector<ll> SHIT;
  for(int i=0;i<n;i++)cin >> q[i];
  for(int i=0;i<m;i++){
    ll a,b,c,d;
    cin >> a >> c >>b >> d;
    if(a>b)swap(a,b);
    a++;
    b--;
    if(a==b){
      SHIT.push_back(a);
      continue;
    }
    if(a>b)continue;
    M.push_back({a,b});
  }
  sort(M.begin(),M.end(),compare);
  m = M.size();
  ll total = 0;
  ll arr[m][2];
//   cout << "____" << "\n";
  while(true){
    int size = 0;
    if(M.size()==0)break;
    vector<pair<ll,ll>> next;
    ll prev = LLONG_MIN;
    for(pair<ll,ll> p :M){
      if(p.first>prev){
//         cout << p.first << "," << p.second << "\t";
        arr[size][0] = p.first;
        arr[size++][1] = p.second;
        prev = p.second;
      }else{
        next.push_back(p);
      }
    }
    M = next;
    int cur = answerQueries(arr,size,q,n);
//     cout << cur << "\n";
    total += cur;
  }
  for(int x:SHIT)
    for(int i=0;i<n;i++)
      if(x==q[i])total++;
  cout << total << "\n";

    return 0;  
} 

/*
 4 8
-5 -3 2 3
-2 5 5 -6
-5 -2 -3 -5
-2 3 -6 1
-1 -3 4 2
2 5 2 1
4 5 4 -5
-2 -4 5 3
1 2 -2 1
-7 0 7 0
 */
