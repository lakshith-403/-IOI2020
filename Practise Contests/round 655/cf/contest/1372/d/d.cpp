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

ll max(ll a,ll b){return a<b?b:a;}

void solve(int t){
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++)cin >> arr[i];
  ll MAX = 0;
  ll sum = 0;
  int a[2*n];
  int pos = 0;
  for(int i=0;i<n;i+=2)a[pos++] = arr[i];
  for(int i=1;i<n;i+=2)a[pos++] = arr[i];
  for(int i=0;i<n;i++)a[i+n] = a[i];
  for(int i=0;i<(n+1)/2;i++)sum += a[i];
  MAX = sum;
  for(int i=(n+1)/2;i<2*n;i++){
    sum -= a[i-(n+1)/2];
    sum += a[i];
    MAX = max(sum,MAX);
  }
  cout << MAX << "\n";
}

int main(){
  io_setup();
  int t =1;
  while(t--)solve(t+1);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
