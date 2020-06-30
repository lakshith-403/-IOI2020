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

inline int Abs(int a,int b){
  return max(a,b)-min(a,b);
}

void solve(int t){
  string s;
  cin >> s;
  int m;
  cin >> m;
  int arr[m+1];
  FOR(i,1,m)cin>>arr[i];
  int Count = 0;
  string ans = "";
  FOR(i,1,m)ans+="0";
  
  int alph[26];
  FORZ(i,26)alph[i]=0;
  FORZ(i,s.length())alph[s[i]-'a']++;
  
  while(Count < m){
    vi vec;
    for(int i=1;i<=m;i++)
      if(arr[i]==0){vec.pb(i);arr[i]=-1;};
    if(vec.size()==0)break;
    int letter = -1;
    for(int i=25;i>=0;i--)
      if(alph[i]>=vec.size()){alph[i]=0;letter=i;break;}
    for(int i=letter;i<26;i++)
      alph[i]=0;
    for(int& x : vec)ans[x-1]=(char)(letter+'a');
    for(int i=1;i<=m;i++)
      for(int& x: vec)
        arr[i] -= Abs(i,x);
  }
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
