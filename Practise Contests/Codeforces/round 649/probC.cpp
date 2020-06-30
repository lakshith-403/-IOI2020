#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORi(i,a,b) for(int i=(a);i>=(b);i--)
#define FORZ(i,a) for(int i=0;i<(a);i++)
#define FORZi(i,a) for(int i=(a)-1;i>=0;i--)
#define trav(a,x) for (auto& a: x)
#define what_is(x) cout << #x << " is " << x << "\n";

#define printl(a) cout << a << "\n";
#define prints(a) cout << a << " ";
#define printall(x) FORZ(i,sz(x))prints(x[i])
#define nextl cout << "\n"

#define in(a) cin >> a;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

set<int> Set;

void solve(int t){
  int n;
  cin >> n;
  int arr[n];
  int MAX = 0;
  
  FORZ(i,n){cin >> arr[i];MAX = max(MAX,arr[i]+1);}
  FORZ(i,MAX+1)Set.insert(i);
  FORZ(i,n){if(Set.find(arr[i])!=Set.end())
    Set.erase(arr[i]);}
//   what_is(n);
  int mex = -1;
  int ans[n];
  FORZ(i,n){
    if(Set.find(arr[i])!=Set.end())
    Set.erase(arr[i]);
    if(!Set.empty())
    mex = *Set.begin();
    ans[i]=mex;
    if(!Set.empty())
    Set.erase(Set.begin());
    Set.insert(arr[i]);
  }
  FORZ(i,n)prints(ans[i]);
}

int main(){
  io_setup();
  solve(0);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
