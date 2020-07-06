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

int Count[10000];
void solve(int t){
  int n;
  cin >> n;
  for(int i=0;i<2*n;i++)Count[i]=0;
  int arr[n];
  arr[0]=-1;
  arr[n+1]=INT_MAX;
  for(int i=1;i<=n;i++)cin >> arr[i],Count[arr[i]]++;
  set<int> st;
  for(int i=0;i<=n*2;i++)st.insert(i);
  for(int i=1;i<=n;i++){
    st.erase(arr[i]);
//     cout << *st.begin() << "\n";
  }
  vector<int> ans;
  for(int k=0;k<2*n;k++){
    int mex = *st.begin();
//     what_is(mex);
    for(int i=1;i<=n;i++){
      if(mex<arr[i+1]){
        st.erase(mex);
        Count[mex]++;
        Count[arr[i]]--;
        if(Count[arr[i]]==0)st.insert(arr[i]);
        arr[i]=mex;
        ans.pb(i);
        break;
      }
    }
  }cout << "++" << "\n";
  for(int i=1;i<=n;i++)prints(arr[i]);
  cout << "\n";
  cout << ans.size() << "\n";
  for(int x:ans)prints(x);
  cout << "\n";
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
