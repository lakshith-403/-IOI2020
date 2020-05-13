
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
string r;
std::string toBinary(int n)
{
    r=(n%2==0 ?"0":"1")+r;
    if (n / 2 != 0) {
        toBinary(n / 2);
    }
    return r;
}

int main(){
  io_setup();
  int t;
  cin >> t;
  while(t--){
    int n;
    in(n);
    int MAX = -1;
    int a,prev;
    cin >> a;
    prev = a;
    FORZ(i,n-1){
      cin >> a;
      if(a>=prev){prev=a;continue;}
      int dif = prev-a;
//       printl("#");
//       what_is(dif);
//       if(MAX!=-1)
//       dif -= (int)pow(2,MAX+1)-1;
//       what_is(dif);
//       if(dif<=0){
//         prev = a+1;
//         continue;
//       }
//       what_is(dif);
      r="";
      string temp = toBinary(dif);
//       what_is(temp);
      int lg = temp.length()-1;
//       what_is(lg);
      MAX = max(MAX,lg);
//       what_is(prev);
    }
    printl(++MAX);
  }
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
