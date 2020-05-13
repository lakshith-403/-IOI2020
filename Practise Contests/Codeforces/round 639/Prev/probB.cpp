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

int MIN = INT_MAX;
int MAX = INT_MAX;

vector<vi> adjList(100001,vi());
int visited[100001];
vi startPoints;

int main(){
  io_setup();
  int n;
  cin >> n;
  FORZ(i,n-1){
    int a,b;
    cin >> a >> b;
    adjList.at(a).pb(b);
    adjList.at(b).pb(a);
  }
  FORZ(i,n+1){
    if(adjList.at(i).size()==1)startPoints.pb(i);
  }
  for(int src : startPoints){
    what_is(src);
    queue<pi> Q;
    Q.push({src,0});
    while(!Q.empty()){
      pi p = Q.front();
      if(adjList[p.f].size()==1&&p.f!=src){
        what_is(p.f);
        if(p.s%2==0){
          MIN = max(MIN,1);
          MAX = min(MAX,p.s);
        }else{
          MIN = max(MIN,3);
          MAX = min(MAX,p.s);
        }
      }
      Q.pop();
      for(int node : adjList[p.f])
        if(visited[node]!=src){
          visited[node]=src;
          Q.push({node,p.s+1});
        }
    }
  }
  prints(MIN);
  printl(MAX);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
