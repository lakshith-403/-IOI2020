#include <bits/stdc++.h>
// #include "paint.h"

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

#pragma endregion

const int MAX = 1e5+1;

bool v[MAX];

int minimumInstructions(int n, int m, int k, std::vector<int> C,std::vector<int> A, std::vector<std::vector<int>> B) {
    //subtask 1
    vector<set<int>> b(m,set<int>());
    int i=0,j,l;
    for(vi x:B){
        for(int a:x)
            b.at(i).insert(a);
        i++;
    }
    vpi intervals;
    for(i=0;i<n-m+1;i++){
        for(j=0;j<m;j++){
            int x=j,y=i;
            for(l=0;l<m;l++)
                if(b.at((x+l)%m).count(C[y+l])==0)break;
            if(l==m)break;
        }
        if(j==m)continue;
        intervals.pb({i,i+m-1});
        
    }
    if(intervals.size()==0)return -1;
    l = -1;
    int Count = 0;
    for(i=0;i<intervals.size();i++){
        int p = -1,ma=-1;
        for(j=i;j<intervals.size();j++){
            if(intervals[j].f>l+1)break;
            if(intervals[j].s>ma)
                p = j,ma=intervals[j].s;
        }
        if(p==-1)return -1;
        l = ma;
        Count++;
        if(l==n-1)break;
    }
    if(l==n-1)
    return Count;
    else return -1;
}

void solve(){
  int N, M, K;
  assert(3 == scanf("%d %d %d", &N, &M, &K));
  
  std::vector<int> C(N);
  for (int i = 0; i < N; ++i) {
    assert(1 == scanf("%d", &C[i]));
  }

  std::vector<int> A(M);
  std::vector<std::vector<int>> B(M);
  for (int i = 0; i < M; ++i) {
    assert(1 == scanf("%d", &A[i]));
    B[i].resize(A[i]);
    for (int j = 0; j < A[i]; ++j) {
      assert(1 == scanf("%d", &B[i][j]));
    }
  }

  int minimum_instructions = minimumInstructions(N, M, K, C, A, B);
  printf("%d\n", minimum_instructions);

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
