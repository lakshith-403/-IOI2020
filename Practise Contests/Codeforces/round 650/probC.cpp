#include <bits/stdc++.h>

#define shit cout << "shit i'm here" << "\n";

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

int arr[2000001];

void solve(int t){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  for(int i=0;i<n;i++){
    if(s[i]=='1')
      for(int j=0;j<=k;j++)
        if(i+j>=n)break;
        else arr[i+j]=t;
  }
  for(int i=0;i<n;i++){
    if(s[i]=='1')
      for(int j=0;j<=k;j++)
        if(i-j<0)break;
        else arr[i-j]=t;
  }
  int C = 0;
  for(int i=0;i<n;i++)
    if(arr[i]!=t){
      C++;
      for(int j=0;j<=k;j++)
        if(i-j<0)break;
        else arr[i-j]=t;
      for(int j=0;j<=k;j++)
        if(i+j>=n)break;
        else arr[i+j]=t;
    }
  printl(C);
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