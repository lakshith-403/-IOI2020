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
#define FORi(i,a,b) for(int i=(a);i>=(a);i--)
#define FORZ(i,a) for(int i=0;i<(a);i++)
#define FORZi(i,a) for(int i=(a)-1;i>=0;i--)
#define trav(a,x) for (auto& a: x)

#define printl(a) cout << a << "\n";
#define prints(a) cout << a << " ";
#define printall(x) FORZ(i,sz(x))prints(x[i])
#define nextl cout << "\n"

#define in(a) cin >> a;

int N,R,M;
vector<vi> adjList(20001,vi());
int P[20001];
int p[20001];
int D[20001];
int visited[20001];

int maxD=INT_MIN;

struct triple{
  int a;
  int b;
  int c;
};

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main(){
  io_setup();
  cin >> N >> R;
  FORZ(i,R){
    int a,b;
    cin >> a >> b;
    adjList.at(a).pb(b);
    adjList.at(b).pb(a);
  }
  in(M);
  FORZ(i,M){
    int a,b;
    cin >> a >> b;
    P[a]=b;
  }
  FORZ(i,N){
    if(P[i]==0||P[i]<p[i])continue;
    list<triple> Q;
    visited[i] = i+1;
    Q.pb({i,P[i],1});
    while(!Q.empty()){
      int a = Q.ft.a;
      int b = Q.ft.b;
      int c = Q.ft.c;
      Q.pop_front();
      if(b>p[a]){
        p[a]=b;
        D[a]=c;
      }else
      continue;
      for(int j:adjList.at(a)){
        if(visited[j]!=i+1){
            visited[j]=i+1;
            Q.pb({j,b/2,c+1});
        }
      }
    }
  }
  long long sum = 0;
  FORZ(i,N){
    sum += p[i];
    maxD = max(maxD,D[i]);
  }
  prints(maxD);
  printl(sum);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
