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
#define FORi(i,a,b) for(int i=(a);i>=(a);i--)
#define FORZ(i,a) for(int i=0;i<(a);i++)
#define FORZi(i,a) for(int i=(a)-1;i>=0;i--)
#define trav(a,x) for (auto& a: x)
#define what_is(x) cerr << #x << " is " << x << "\n";

#define printl(a) cout << a << "\n";
#define prints(a) cout << a << " ";
#define printall(x) FORZ(i,sz(x))prints(x[i])
#define nextl cout << "\n"

#define in(a) cin >> a;
int n,a,b,c;

void BFS(int src){

}

int main(){
  int t;
  cin >> t;
  while(t--){
    vector<string> path;
    set<string> SET;
    vector<vector<int>> adjList(200001,vector<int>());
    int n,m,a,b,c;
    cin >> n >> m >> a >> b >> c;
    FORZ(i,m){
      int x,y;
      cin >> x >> y;
      adjList.at(x).pb(y);
      adjList.at(y).pb(x);
    }
    bool *visited = new bool[N];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    list<int> Q;
    visited[src] = true;
    Q.push_back(src);
    list<int>::iterator i;

    while(!Q.empty())
    {
        src = Q.front();
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
  }
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
