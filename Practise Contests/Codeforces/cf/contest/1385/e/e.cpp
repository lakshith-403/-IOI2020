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
#define what_is(x) cout << #x << " is " << x << "\n"
#define shit cout << "shit" << "\n";
#define fuck cout << "fuck" << "\n";

#define printl(a) cout << a << "\n"
#define prints(a) cout << a << " "
#define printall(x) FORZ(i,sz(x))prints(x[i])
#define nextl cout << "\n"

#define in(a) cin >> a;

// === Debug macro starts here ===
int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
  os<<"[";
  for(auto& x:v){os<<x<<", ";}
  return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
  return os<<"{"<<p.first<<", "<<p.second<<"}";
}
// === Debug macro ends here ===

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

using namespace std; 
  
class Graph 
{ 
    int V;  
    list<int> *adj; 
    bool isCyclicUtil(int v, bool visited[], bool *rs); 
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
    Graph(int V);  
    void addEdge(int v, int w);  
    bool isCyclic();    
    void topologicalSort(); 
}; 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);  
} 
  
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    { 
        visited[v] = true; 
        recStack[v] = true; 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false; 
    return false; 
} 
bool Graph::isCyclic() 
{ 
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
    for(int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 
}
  
void Graph::topologicalSortUtil( 
int v, bool visited[], stack<int> &Stack) 
{ 
    visited[v] = true; 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
    Stack.push(v); 
} 

int pos = 1;
int topsort[200005];

void Graph::topologicalSort() 
{ 
    stack<int> Stack; 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
    for (int i = 0; i < V; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 
    while (Stack.empty() == false) 
    { 
        // cout << Stack.top() << " "; 
        topsort[Stack.top()] = pos++;
        Stack.pop(); 
    } 
}

void solve(int t){
  int n,m;
  cin >> n >> m;
  Graph g(n);
  vpi vec;
  vpi arr;
  for(int i=0;i<m;i++){
    int t,a,b;
    cin >> t >> a >> b;
    a--,b--;
    topsort[a] = 0;
    topsort[b] = 0;
    if(t){
      g.addEdge(a,b);
      arr.pb({a,b});
    }else{
      vec.pb({a,b});
    }
  }
  pos = 0;
  if(g.isCyclic()){
    printl("NO");
    return;
  }
  printl("YES");
  g.topologicalSort();
  for(pi p:vec){
    if(topsort[p.f]<=topsort[p.s]){
      cout << p.f+1 << " " << p.s+1  << "\n";
    }else{
      cout << p.s+1 << " " << p.f+1 << "\n";
    }
  }
  for(pi p:arr){
    cout << p.f+1 << " " << p.s+1 << "\n";
  }
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
