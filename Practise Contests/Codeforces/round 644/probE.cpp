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

int visited[50][50];
int arr[50][50];

void DFS(int x,int y,int col){
  if(x<0 || y<0)return;
  if(arr[x][y]==0 || visited[x][y]==col)return;
  visited[x][y] = col;
  DFS(x-1,y,col);
  DFS(x,y-1,col);
}

void solve(int t){
  t++;
  int n;
  cin >> n;
  FORZ(i,n){
    FORZ(j,n){
      char c;
      cin >> c;
      arr[i][j] = c-'0';
    }
  }
  for(int i=0;i<n;i++){
    DFS(i,n-1,t);
    DFS(n-1,i,t);
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
      if(arr[i][j]==1&&visited[i][j]!=t){cout << "NO" << "\n"; return;}
    }
  cout << "YES" << "\n";
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
