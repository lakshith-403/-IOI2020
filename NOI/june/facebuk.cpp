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

const int MAX = 1e6;
map<int,int> m;

struct subset{
  int parent;
  int rank;
};

struct subset subsets[MAX+1000];

int find(int i){
  if(subsets[i].parent != i)
    subsets[i].parent = find(subsets[i].parent);
  return subsets[i].parent;
}

void Union(int x,int y){
  int xroot = find(x);
  int yroot = find(y);
  if(subsets[xroot].rank < subsets[yroot].rank)
    subsets[xroot].parent = yroot;
  else if(subsets[xroot].rank > subsets[yroot].rank)
    subsets[yroot].parent = xroot;
  else{
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}


void solve(int t){
  int n;
  cin >> n;
  FORZ(i,MAX+1000){
    subsets[i].parent = i;
    subsets[i].rank = 0;
  }
  FORZ(i,n){
    int h,s;
    cin >> h >> s;
    Union(i,MAX+h);
    Union(i,MAX+500+s);
  }
  int ans = 0;
  FORZ(i,n){
    int root = find(i);
    if(m.count(root)==0)m.insert({root,1});
    else{
      m.at(root)++;
    }
    ans = max(ans,m.at(root));
  }
  cout << ans << "\n";
}

int main(){
  io_setup();
  solve();
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
