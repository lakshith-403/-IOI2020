

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

int grid[1000][1000];
bool visited[1000][1000];
bool row[1000];
bool column[1000];
int whiteCount = 0;
int n,m;

void DFS(int x,int y){
  if(visited[x][y]||grid[x][y]==0)return;
  visited[x][y] = true;
  if(x!=0)DFS(x-1,y);
  if(x!=n-1)DFS(x+1,y);
  if(y!=0)DFS(x,y-1);
  if(y!=m-1)DFS(x,y+1);
}

int main(){
  io_setup();
  cin >> n >> m;
  FORZ(i,n){
    FORZ(j,m){
      char c;
      cin >> c;
      if(c=='.'){
        grid[i][j]=0;
        whiteCount++;
      }
      else{
        grid[i][j]=1;
        row[i]=true;
        column[j]=true;
      }
    }
  }
  bool whiteR = false,whiteCol=false;
  FORZ(i,n){
    if(!row[i]){whiteR=true;break;}
  }
  FORZ(i,m){
    if(!column[i]){whiteCol=true;break;}
  }
  
  if((whiteCol&&!whiteR) || (!whiteCol&&whiteR))
  {
    printl("-1");return 0;
    
  }
  bool black = false;
  bool white = false;
  bool start = false;
  bool flag = false;
  FORZ(j,m){
    black = false;
    white = false;
    start = false;
    flag = false;
    FORZ(i,n){
      if(grid[i][j]==1){
        black = true;
        if(start&&white){j=m;flag = true;break;}
        start = true;
      }else{
        if(start)white = true;
      }
    }
  }
  if(flag){printl(-1);return 0;}
  black = false;
  white = false;
  start = false;
  flag = false;
  FORZ(i,n){
    black = false;
      white = false;
      start = false;
      flag = false;
    FORZ(j,m){
      if(grid[i][j]==1){
        black = true;
        if(start&&white){i=n;flag = true;break;}
        start = true;
      }else{
        if(start)white = true;
      }
    }
    
  }
  if(flag){printl(-1);return 0;}
  int Count = 0;
  FORZ(i,n){
    FORZ(j,m){
      if(!visited[i][j]&&grid[i][j]==1){
        DFS(i,j);
        Count++;
      }
    }
  }
  printl(Count);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
