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

bool Nb[200001];
int M[200001];
int N[200001];

int main(){
  // io_setup();
  int n,k;
  cin >> n >> k;
  // what_is(n);
  // what_is(k);
  for(int i=1;i<=n;i++){cin >>N[i];}
  for(int i=1;i<=k;i++){cin >> M[i];}
  // what_is(M[1]);
  // return 0;
  // sort(N,N+n);
  vector<vector<int>> vecList;
  while(true){
    vi vec;
    int i;
    int sum = 0;
    for(i=0;i<n;i++){
      if(Nb[i])continue;
      what_is(M[N[i]]);
      if(M[N[i]]-sum<=0)break;
      Nb[i]=true;
      vec.pb(N[i]);
      sum++;
    }
    what_is(i);
    vecList.pb(vec);
    if(i==n)break;
  }
  printl(vecList.size());
  for(vi vec : vecList){
    prints(vec.size());
    for(int x : vec){
      prints(x);
    }
    printl("");
  }
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
