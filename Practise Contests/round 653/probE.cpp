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
pi times;

struct book{
  int t;
  int a;
  int b;
};

vi a_books;
vi b_books;
vi ab_books;

void solve(){
  int n,m,k;
  cin >> n >> m >> k;
  int al=0,bb=0;
  ll ans = 0;
  int Count = 0;
  for(int i=0;i<n;i++){
    int t,a,b;
    cin >> t >> a >> b;
    al += a;
    bb += b;
    if(a==1 && b==1)
      ab_books.pb(t);
    else if(a==1 && b==0)
      a_books.pb(t);
    else if(a==0 && b==1)
      b_books.pb(t);
  }
  if(al<k||bb<k){printl(-1);return;}
  sort(all(ab_books));
  sort(all(a_books));
  sort(all(b_books));
  for(int i=0;i<min(k,min((int)a_books.size(),(int)b_books.size()));i++)
    ans += (ll)a_books[i]+(ll)b_books[i],Count += 2;
  int index = min(k,min((int)a_books.size(),(int)b_books.size()))-1;
  if(index==-1){
    ans = 0;
    for(int i=0;i<k;i++)
      ans += (ll)ab_books[i];
    cout << ans << "\n";
    return ;
  }
//   what_is(k-index-1);
//   what_is(ans);
  for(int i=0;i<k-index-1;i++)
    ans += ab_books[i];
  int pos = k-index-1;
  for(int i=pos;i<ab_books.size();i++){
    if(index<0)break;
    if(a_books[index]+b_books[index]>ab_books[i]){
      ans -= (ll)a_books[index]+(ll)b_books[index];
      ans += (ll)ab_books[i];
//       cout << (ll)a_books[index]+(ll)b_books[index] << " " << (ll)ab_books[i] << "\n";
    }
    index--;
//     cout << (ll)a_books[index]+(ll)b_books[index] << " " << (ll)ab_books[i] << "\n";
  }
  cout << ans << "\n";
}

int main(){
  io_setup();
  int t = 1;
  while(t--)solve();
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
