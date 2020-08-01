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
#define what_is(x) cout << #x << " is " << x << "\n"
#define shit cout << "shit" << "\n";
#define fuck cout << "fuck" << "\n";

#define printl(a) cout << a << "\n"
#define prints(a) cout << a << " "
#define printall(x) FORZ(i,sz(x))prints(x[i])
#define nextl cout << "\n"

#define in(a) cin >> a;

// === Debug macro starts here ===
int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
  os<<"[";
  for(auto& x:v){os<<x<<", ";}
  return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
  return os<<"{"<<p.first<<", "<<p.second<<"}";
}
// === Debug macro ends here ===

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

const int SIZE = 10e5 + 5;
int n;
pi space[SIZE];
vector<vector<int>> adjList(SIZE,vector<int>());
int h[SIZE];
int p[SIZE];

int dfs_h(int node,int src){
    int r = h[node];
    for(int x:adjList.at(node))
      if(x!=src)
        r += dfs_h(x,node);
    space[node].f = r;
    return r;
}

int dfs_p(int node,int src){
  int r = p[node];
  for(int x:adjList.at(node))
      if(x!=src)
        r += dfs_p(x,node);
  space[node].s = r;
  return r;
}

bool dfs(int node,int m,int src){
  if(space[node].f>space[node].s)return false;
  if(m>=space[node].f){
    m = min(m,space[node].f);
    for(int x:adjList.at(node)){
      if(x==src)continue;
      bool b = dfs(x,m,node);
      if(!b)return b;
      m -= space[x].f;
    }
    if(m%2==0)return true;
    else return false;
  }else return false;
}

void solve(int t){
  for(int i=0;i<=n;i++)
  {
    vector<int> temp;
    adjList.at(i) = temp;
  }
  cin >> n;
  int m;
  cin >> m;
  for(int i=1;i<=n;i++){
    cin >> p[i];
  }
  for(int i=1;i<=n;i++){
    cin >> h[i];
  }
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    adjList.at(a).pb(b);
    adjList.at(b).pb(a);
  }
  dfs_h(1,0);
  dfs_p(1,0);
  if(dfs(1,m,0))printl("YES");
  else printl("NO");
}

int main(){
  io_setup();
  int t;
  cin >> t;
  while(t--)solve(t+1);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
