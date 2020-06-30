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
bool in[1000001];
bool ever[1000001];
void solve(int t){
  int n;
  cin >> n;
  FORZ(i,n)in[i]=false,ever[i]=false;
  int d = 0;
  vector<vi> days;
  vi vec;
  int tc = 0;
  FORZ(i,n){
    int a;
    cin >> a;
    vec.pb(a);
    if(a>0){
      if(in[a]||ever[a]){printl(-1);return;}
      in[a]=true;
      ever[a] = true;
      tc++;
      continue;
    }
    a*=-1;
    if(in[a]){
      in[a]=false;
      tc--;
      if(tc!=0)continue;
      for(int x:vec)if(x>=0)ever[x]=false;
      days.pb(vec);
      vi temp;
      vec = temp;
    }else{
      printl("-1");
      return;
    }
  }
  if(tc!=0){printl(-1);return;}
  if(days.size()==0){printl(-1);return;}
  printl(days.size());
  for(vi vec:days){
    prints(vec.size());
  }
  cout << "\n";
}

int main(){
  io_setup();
  int t = 1;
  while(t--)solve(t+1);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
