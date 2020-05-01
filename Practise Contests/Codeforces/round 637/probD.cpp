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

int n,k;

bool dp[2002][2010];

string presets[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string paterns[2002];

int getDif(string pat,int a){
  int Count = 0;
  FORZ(i,7){
    if(presets[a][i]=='0'&&pat[i]=='1')return -1;
    else if(presets[a][i]!=pat[i])Count++;
  }
  return Count;
}

int main(){
  io_setup();
  cin >> n >> k;
  FOR(i,1,n)cin >> paterns[i];
  dp[n+1][0]=true;
  for(int i=n+1;i>1;i--){
    for(int j=0;j<=k;j++){
      if(!dp[i][j])continue;
      FORZ(l,10){
        int dif = getDif(paterns[i-1],l);
        if(dif!=-1)dp[i-1][j+dif] = 1;
        // if(dif!=1){what_is(dif);what_is(l);}
      }
    }
  }
  // FORZ(j,k){FOR(i,1,n){prints(dp[i][j]);}printl("");}
  if(!dp[1][k]){cout << -1 << "\n";return 0;}
  int pos = k;
  FOR(i,1,n){
    FORZi(j,10){
      int dif = getDif(paterns[i],j);
      if(dif!=-1&&dp[i+1][pos-dif]){
        pos -= dif;
        cout << j;
        break;
      }
    }
  }
  cout << "\n";
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
