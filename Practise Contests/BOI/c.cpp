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

int l, r,V;

inline bool inrange(int a){return (a>=l && a<=r);}

vector<vector<int>> G(2001,vector<int>());

map<pi,int> streets;

bool isBipartiteUtil(int src, int colorArr[]) { 
    colorArr[src] = 1; 
    queue <int> q; 
    q.push(src); 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop();  
        for (int v:G[u]) { 
            if(inrange(streets.at({u,v})))continue;
            if (colorArr[v] == -1) 
            { 
                colorArr[v] = 1 - colorArr[u]; 
                q.push(v); 
            } 
            else if (colorArr[v] == colorArr[u]) 
                return false; 
        } 
    } 
    return true; 
} 
bool isBipartite() 
{ 
    int colorArr[V]; 
    for (int i = 0; i < V; ++i) 
        colorArr[i] = -1; 
    for (int i = 0; i < V; i++) 
    if (colorArr[i] == -1) 
        if (isBipartiteUtil(i, colorArr) == false) 
        return false; 
  
    return true; 
}
void solve(int t){
    int n,m,q;
    cin >> n >> m >> q;
    V = n;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        streets.insert({make_pair(a,b),i});
        streets.insert({make_pair(b,a),i});
        G.at(a).pb(b);
        G.at(b).pb(a);
    }
    for(int i=0;i<q;i++){
        cin >> l >> r;
        l--,r--;
        if(isBipartite())cout << "NO\n";
        else cout << "YES\n"; 
    }
}

int main(){
    io_setup();
  solve(0);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
