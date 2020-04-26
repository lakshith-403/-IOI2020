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
int mem[201*201];
int main(){
  io_setup();
  int t;
  in(t);
  while(t--){
    int a,b,q;
    cin >> a >> b >> q;
    ll MAX = a*b;
    FORZ(i,MAX+1)mem[i]=0;
    FOR(i,1,MAX){
      if((i%a)%b!=(i%b)%a)mem[i]=mem[i-1]+1;
      else mem[i]=mem[i-1];
      // prints(mem[i]);
    }
    // printl("____");
    while(q--){
      ll l,r;
      cin >> l >> r;
      l--;
      ll L = 0;
      L += (l/MAX)*mem[MAX];
      L += mem[l%MAX];
      ll R = 0;
      R += (r/MAX)*mem[MAX];
      R += mem[r%MAX];
      // what_is(R);
      // what_is(L);
      prints(R-L);
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
