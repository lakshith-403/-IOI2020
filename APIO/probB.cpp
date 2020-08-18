
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#pragma region 

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
// #define fuck cout << "fuck" << "\n";

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

#pragma endregion

int MAX = -1;
int MIN = INT_MAX;
bool circle = false;
int w[100000];
int n,m;
vector<pair<int,int>> fuck;

int sub;


inline double getRand(){
    return ((double) rand() / (RAND_MAX));
}

void init(int N, int M,std::vector<int> U, std::vector<int> V, std::vector<int> W) {
    n=N,m=M;
    int j;
    int a = 1;
    // for(j=0;j<m;j++)a &= (U[j]==0);
    sub = 2;
    // what_is(sub);
    for(int i=0;i<m;i++){
        w[V[i]] = W[i];
        fuck.pb({W[i],V[i]});
        MIN = min(MIN,W[i]);
        MAX = max(MAX,W[i]);
    }
    circle = n==m;
    sort(all(fuck));
    // shit_count
    // what_is(MIN);
}

int getMinimumFuelCapacity(int X, int Y) {
    if(sub==1){
        if(n==m)return MAX;
        else return -1;   
    }else{
        // shit
        int mm = -1;
        for(pi x:fuck){
            if(x.s!=X && x.s!=Y){mm=x.f;break;}
            // what_is(x.s);
        }
        if(mm == -1)return -1;
        return max(mm,max(w[X],w[Y]));
    }   
}

void solve(){
     int N, M;
  assert(2 == scanf("%d %d", &N, &M));
  
  std::vector<int> U(M), V(M), W(M);
  for (int i = 0; i < M; ++i) {
    assert(3 == scanf("%d %d %d", &U[i], &V[i], &W[i]));
  }

  int Q;
  assert(1 == scanf("%d", &Q));

  std::vector<int> X(Q), Y(Q);
  for (int i = 0; i < Q; ++i) {
    assert(2 == scanf("%d %d", &X[i], &Y[i]));
  }

  init(N, M, U, V, W);
  
  std::vector<int> minimum_fuel_capacities(Q);
  for (int i = 0; i < Q; ++i) {
    minimum_fuel_capacities[i] = getMinimumFuelCapacity(X[i], Y[i]);
  }

  for (int i = 0; i < Q; ++i) {
    printf("%d\n", minimum_fuel_capacities[i]);
  }

}

int main(){
//   io_setup();
  solve();
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
