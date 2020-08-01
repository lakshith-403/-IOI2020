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

int g[101][101];
int v[101][101];
int l,n,k;
void dfs(int i,int j,int t){
  // what_is(g[i][j]);
  // cout << i << "<>" << j << "\n";
  if(i<0||j<0)return;
  i %= n+1;
  j %= 2*k;
  if(v[i][j]==t || g[i][j]>l)return;
  v[i][j] = t;
  // cout << i << "," << j << "\n";
  // what_is(i);
  // what_is(j);
  dfs(i+1,j+1,t);
  dfs(i-1,j+1,t);
  dfs(i,j+1,t);
}

void solve(int t){
  cin >> n >> k >> l;
  int d[n+1];
  int p[2*k];
  // shit
  for(int i=0;i<k;i++)p[i] = i;
  int x = k;
  for(int i=k;i<2*k;i++)p[i] = x--;
  for(int i=0;i<n;i++)cin >> d[i+1];
  // shit
  for(int i=1;i<=n;i++)
    for(int j=0;j<2*k;j++){
      g[i][j] = d[i]+p[j];
    }
  for(int i=0;i<2*k;i++)
    g[0][i]=0;
  // shit
  // for(int i=0;i<=n;i++){
  //   for(int j=0;j<=n;j++){
  //     cout << g[i][j] << " ";
  //   }
  //   cout << "\n";}

  dfs(0,0,t);
  for(int i=0;i<2*k;i++)
    if(v[n][i]==t){cout << "Yes" << "\n";return;}

  cout << "No" << "\n";
}

int main(){
  // io_setup();
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
