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

void solve(int t){
	int n,k;
 cin >> n >> k;
 
//  if(k==0){
//    cout << 0 << "\n";
//    for(int i=0;i<n;i++){
//    for(int j=0;j<n;j++)cout << 0;
//    cout << "\n";
//  }
//  return;
// }
//  
 
 int f = (k%n==0?0:1);
 int r[n],c[n];
 int expR[n],expC[n];
 for(int i=0;i<n;i++)r[i]=0,c[i]=0;
 for(int i=0;i<n;i++)expR[i]=k/n;
 for(int i=0;i<k%n;i++)expR[i]++;
 for(int i=0;i<n;i++)expC[i]=k/n;
 for(int i=0;i<k%n;i++)expC[i]++;
 
 int ans[n][n];
 for(int i=0;i<n;i++)
   for(int j=0;j<n;j++){
      if(r[i]<expR[i] && c[j]<expC[j])ans[i][j]=1,r[i]++,c[j]++;
      else ans[i][j] = 0;
  }
cout << f*f*2 << "\n";
 for(int i=0;i<n;i++){
   for(int j=0;j<n;j++)cout << ans[i][j];
   cout << "\n";
 }
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
