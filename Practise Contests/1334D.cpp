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
#define ten5 100001
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
int sumArr[ten5+1];
pi getLower(int n,int l){
  int i = 1;
  sumArr[0]=0;
  for(i;i<n;i++){
    sumArr[i] = sumArr[i-1]+(2*(n-i));
    if(sumArr[i]>l)break;
  }
  if(sumArr[i]<l && i==n)sumArr[++i]=sumArr[i-1]++;
  else i--;
  return {i,sumArr[i]};
}

int main(){
  io_setup();
  int t;
  in(t);
  while(t--){
    int n,l,r;
    cin >> n >> l >> r;
    pi lower = getLower(n,l);
    vi ans;
    int start = 0;
    for(lower.f;lower.f<n;lower.f++){
      for(int i=lower.f+1;i<=n;i++){
        if(lower.s>r){lower.f=n;break;}
        if(lower.s>=l)
        ans.pb(lower.f);
        lower.s++;
        if(lower.s>r){lower.f=n;break;}
        if(lower.s>=l)
        ans.pb(i);
        lower.s++;
      }
    }
    for(int x:ans)prints(x);
    cout << "\n";
  }
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/

