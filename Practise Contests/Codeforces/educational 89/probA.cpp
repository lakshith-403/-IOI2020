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

void solve(int t){
  int a,b;
  cin >> a >> b;
  int ans = 0;
  if(a<b)swap(a,b);
  if(a==0||b==0||a+b<3){printl(0);return;}
  while(a!=0&&b!=0&&a>=2){
//     int dif = min(a/2,b);
//     a-=dif*2;
//     b-=dif;
//     ans+=dif;
    int dif = a-b;
    if(dif>=2){
    a-=(dif/2)*2;
    b-=dif/2;
    ans += dif/2;
    }else{
      ans++;
      a-=2;
      b--;
    }
    if(a<b){cout << a << "\t" << b << "\n";}
    if(a<b)swap(a,b);
  }
  what_is(a);
  what_is(b);
//   if(a<b)swap(a,b);
//   if(a>=2){
//     ans++;
//   }
  printl(ans);
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
