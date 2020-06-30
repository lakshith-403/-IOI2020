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
  int n,a,b,c;
  cin >> n >> a >> b >> c;
  string s;
  cin >> s;
  int r=0,p=0,sc=0;
  for(char C:s)
    if(C=='R')p++;
    else if(C=='P')sc++;
    else r++;
  for(int i=0;i<n;i++)
    if(s[i]=='R')s[i]='P';
    else if(s[i]=='P')s[i]='S';
    else s[i]='R';
  int ans = 0;
  ans += min(a,r);
  ans += min(b,p);
  ans += min(c,sc);
//   what_is(n/2+((n%2==0)?0:1));
//   cout <<a << " " << b << " " << c << "\n";
//   cout << r << " " << p << " " << sc << "\n";
  if(ans<(n/2+((n%2==0)?0:1))){printl("NO");return;}
  printl("YES");
  vi Count(3);
  string S = "";
  for(int i=0;i<n;i++){
    if(s[i]=='R'&&Count[0]<min(a,r)){
      S+='R';
      Count[0]++;
    }else if(s[i]=='P'&&Count[1]<min(b,p)){
      S+='P';
      Count[1]++;
    }else if(s[i]=='S'&&Count[0]<min(c,sc)){
      S+='S';
      Count[2]++;
    }else S += '_';
  }
  string temp = "";
  while(Count[0]<=min(a,r)){
    temp += 'S';
    Count[0]++;
  }
  while(Count[1]<=min(b,p)){
    temp += 'R';
    Count[1]++;
  }
  while(Count[2]<=min(c,sc)){
    temp += 'P';
    Count[2]++;
  }
  int pos = 0;
  for(int i=0;i<n;i++){
    if(S[i]=='_'){
      S[i] = temp[pos++];
    }
  }
  printl(S);
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
