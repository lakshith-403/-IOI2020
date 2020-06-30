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
bool grid[100][100];
void solve(int t){
  int n,m,x;
  cin >> n >> x >> m;
  vpi vec;
  vpi alt;
  for(int i=0;i<m;i++){
    int l,r;
    cin >> l >> r;
    if(x>=l&&x<=r)
    vec.pb({l,r});
    else{
      for(pi b:vec){
        if((l>=b.f && l<=b.s)||(r>=b.f && r<=b.s))
        {vec.pb({l,r});break;}
      }
    }
  }
  
  if(vec.size()==0){printl(0);return;}
//     bool flag = true;
//     for(int i=0;i<alt.size();i++){
//     pi a =alt[i];
//     if(a.f==-1)continue;
//     for(pi b:vec){
//       if((a.f>=b.f && a.f<=b.s)||(a.s>=b.f && a.s<=b.s)){vec.pb(alt.at(i));alt.at(i).f=-1;flag =false;break;}
//     }
//     }
//     if(flag)break;
//     what_is(flag);
//   }
//   sort(all(vec));
//   ll ans = 0;
//   int prev = vec.at(0).f;
//   for(pi a:vec){
//     ans+=a.s-prev;
//     prev = a.s;
//   }
  sort(all(vec));
  int prev = vec.at(0).f;
  ll ans = 0;
  for(pi a:vec){
    if(a.f>prev || a.s<=prev)continue;
//     cout << a.f << "\t" << a.s << "\n";
    ans += a.s-prev;
    prev= a.s;
  }
  printl(++ans);
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
