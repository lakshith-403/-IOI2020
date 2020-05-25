#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
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

int one[200000];
int two[200000];
int three[200000];

int absMin(int a,int b){
  if(a<0)a*=-1;
  if(b<0)b*=-1;
  return min(a,b);
}

void solve(int t){
  string str;
  cin >> str;
  int n = str.length();
  int prevOne = INT_MAX;
  int prevTwo = INT_MAX;
  int prevThree = INT_MAX;
  for(int i=0;i<n;i++){
    if(str[i]=='1'){
      one[i] = 0;
      prevOne = i;
    }else if(str[i]=='2'){
      two[i]=0;
      prevTwo = i;
    }else{
      three[i]=0;
      prevThree = i;
    }
    one[i] = (prevOne-i);
    two[i] = (prevTwo-i);
    three[i] = prevThree-i;
  }
  prevOne = INT_MAX;
  prevTwo = INT_MAX;
  prevThree = INT_MAX;
  bool O = false,T = false,TH = false;
  for(int i=n-1;i>=0;i--){
    if(str[i]=='1'){
      one[i] = 0;
      prevOne = i;
      O = true;
    }else if(str[i]=='2'){
      two[i]=0;
      prevTwo = i;
      T = true;
    }else{
      three[i]=0;
      prevThree = i;
      TH = true;
    }
    one[i] = absMin(prevOne-i,one[i]);
    two[i] = absMin(prevTwo-i,two[i]);
    three[i] = absMin(prevThree-i,three[i]);
    if(one[i]==prevOne-i)one[i]*=-1;
    if(two[i]==prevTwo-i)two[i]*=-1;
    if(three[i]==prevThree-i)three[i]*=-1;
  }
  if(!(T && TH && O)){cout << 0 << "\n";return;}
  int MIN = INT_MAX;
  for(int i=0;i<n;i++){
//     cout << one[i] << "\t" << two[i] << "\t" << three[i] << "\n";
    int MAXP = 0;
    int MAXN = 0;
    if(one[i]<0)MAXN = min(MAXN,one[i]);
    else MAXP = max(MAXP,one[i]);
    if(two[i]<0)MAXN = min(MAXN,two[i]);
    else MAXP = max(MAXP,two[i]);
    if(three[i]<0)MAXN = min(MAXN,three[i]);
    else MAXP = max(MAXP,three[i]);
//     cout << MAXN << "\t" << MAXP << "\n";
    MIN = min(MIN,MAXP-MAXN);
  }
//   cout << "\n";
  cout << ++MIN << "\n";
}

int main(){
  io_setup();
  int t;
  cin >> t;
  while(t--){
    solve(t);
  }
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
