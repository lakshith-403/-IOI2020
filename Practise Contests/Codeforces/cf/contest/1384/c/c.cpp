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


struct Edge  
{ 
    int src, dest, weight;  
};  
  
// a structure to represent a connected, undirected  
// and weighted graph  
class Graph  
{  
    public: 
    // V-> Number of vertices, E-> Number of edges  
    int V, E;  
  
    // graph is represented as an array of edges.  
    // Since the graph is undirected, the edge  
    // from src to dest is also edge from dest  
    // to src. Both are counted as 1 edge here.  
    Edge* edge;  
};  
  
// Creates a graph with V vertices and E edges  
Graph* createGraph(int V, int E)  
{  
    Graph* graph = new Graph;  
    graph->V = V;  
    graph->E = E;  
  
    graph->edge = new Edge[E];  
  
    return graph;  
}  
  
// A structure to represent a subset for union-find  
class subset  
{  
    public: 
    int parent;  
    int rank;  
};  
  
// A utility function to find set of an element i  
// (uses path compression technique)  
int find(subset subsets[], int i)  
{  
    // find root and make root as parent of i  
    // (path compression)  
    if (subsets[i].parent != i)  
        subsets[i].parent = find(subsets, subsets[i].parent);  
  
    return subsets[i].parent;  
}  
  
// A function that does union of two sets of x and y  
// (uses union by rank)  
void Union(subset subsets[], int x, int y)  
{  
    int xroot = find(subsets, x);  
    int yroot = find(subsets, y);  
  
    // Attach smaller rank tree under root of high  
    // rank tree (Union by Rank)  
    if (subsets[xroot].rank < subsets[yroot].rank)  
        subsets[xroot].parent = yroot;  
    else if (subsets[xroot].rank > subsets[yroot].rank)  
        subsets[yroot].parent = xroot;  
  
    // If ranks are same, then make one as root and  
    // increment its rank by one  
    else
    {  
        subsets[yroot].parent = xroot;  
        subsets[xroot].rank++;  
    }  
}  
  
// Compare two edges according to their weights.  
// Used in qsort() for sorting an array of edges  
int myComp(const void* a, const void* b)  
{  
    Edge* a1 = (Edge*)a;  
    Edge* b1 = (Edge*)b;  
    return a1->weight > b1->weight;  
}  
  
// The main function to construct MST using Kruskal's algorithm  
int KruskalMST(Graph* graph)  
{  
    int V = graph->V;  
    Edge result[V]; // Tnis will store the resultant MST  
    int e = 0; // An index variable, used for result[]  
    int i = 0; // An index variable, used for sorted edges  
  
    // Step 1: Sort all the edges in non-decreasing  
    // order of their weight. If we are not allowed to  
    // change the given graph, we can create a copy of  
    // array of edges  
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);  
  
    // Allocate memory for creating V ssubsets  
    subset *subsets = new subset[( V * sizeof(subset) )];  
  
    // Create V subsets with single elements  
    for (int v = 0; v < V; ++v)  
    {  
        subsets[v].parent = v;  
        subsets[v].rank = 0;  
    }  
  
    // Number of edges to be taken is equal to V-1  
    while (e < V - 1 && i < graph->E)  
    {  
      // what_is(e);
      // what_is(i);
        // Step 2: Pick the smallest edge. And increment  
        // the index for next iteration  
        Edge next_edge = graph->edge[i++];  
  
        int x = find(subsets, next_edge.src);  
        int y = find(subsets, next_edge.dest);  
        // cout << x << y << "\n";
        // If including this edge does't cause cycle,  
        // include it in result and increment the index  
        // of result for next edge  
        if (x != y)  
        {  
            result[e++] = next_edge;  
            Union(subsets, x, y);  
        }  
        // Else discard the next_edge  
    }
    return e;
}

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve(int t){
  int n;
  cin >> n;
  int arr[27][27] = {0};
  string a,b;
  cin >> a >> b;
  for(int i=0;i<n;i++){
    if(a[i]>b[i]){
    cout << -1 << "\n";
    return;
  }
  }
  int C = 0;
  int alph[26] = {0};
  for(int i=0;i<n;i++){
    if(a[i]==b[i])continue;
    if(arr[a[i]-'a'][b[i]-'a']==1)continue;
    arr[a[i]-'a'][b[i]-'a']=1;
    C++;
    alph[a[i]-'a']=1;
    alph[b[i]-'a']=1;
  }
  int V = 26*26;
  // for(int i=0;i<26;i++)V += alph[i];
  int r = 0;
 // Number of vertices in graph  
  int E = C; // Number of edges in graph  
  Graph* graph = createGraph(V, E);  
  int pos = 0;
  for(int i=0;i<26;i++)
  for(int j=0;j<26;j++){
    if(arr[i][j]==0)continue;
    graph->edge[pos].src = i;  
    graph->edge[pos].dest = j;  
    graph->edge[pos].weight = 1; 
    pos++;
  }
  // shit
  // what_is(V);
    // if(i==j)continue;
    // else
    // r+=arr[i][j];
  // cout <<r << "\n";
  cout << KruskalMST(graph) << "\n";
}

int main(){
  // io_setup();
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
