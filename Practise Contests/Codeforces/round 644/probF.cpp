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
  int n,m;
  cin >> n >> m;
  map<string,int> Map;
  string arr[n];
  FORZ(i,n)cin >> arr[i];
  FORZ(i,n){
//     what_is(arr[i]);
    FORZ(j,m){
      FORZ(k,26){
        string temp = arr[i];
        if(temp[j]=='a'+k)continue;
        temp[j] = 'a'+k;
//         cout << temp << "\t";
        if(Map.count(temp)==0)Map.insert({temp,1});
        else{
          int num = Map.at(temp);
          Map.erase(temp);
          Map.insert({temp,num+1});
        }
      }
      
//       cout << "\n";
    }
    string temp = arr[i];
//         cout << temp << "\t";
        if(Map.count(temp)==0)Map.insert({temp,1});
        else{
          int num = Map.at(temp);
          Map.erase(temp);
          Map.insert({temp,num+1});
        }
  }
  map<string, int>::iterator itr;
  bool flag = false;
  for (itr = Map.begin(); itr != Map.end(); ++itr) { 
        if(itr->second>=n){
          cout << itr-> first << "\n";
          return;
        }
    }
  cout << "-1" << "\n";
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
