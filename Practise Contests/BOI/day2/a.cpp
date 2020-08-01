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

inline void io_setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct eqn{
    int a,b;
    int op;
    int ans;
};

vector<eqn> vec;
vector<vector<pair<int,int>>> adjList(1000,vector<pair<int,int>>());
int ans[1001] = {100};
bool visited[1001];
int E[1001][1001];

void print(eqn e){
    cout << e.a << (e.op==1?" + ":" - ") << e.b << " = " << e.ans << "\n";
}

void dfs(int src){
    for(pair<int,int> p : adjList[src]){
        if(E[p.f][src]!=100){
            vec.pb({src,p.f,1,p.s});
            E[p.f][src]=100;
            E[src][p.f]=100;
        }
    }
    for(pair<int,int> p:adjList[src]){
        if(!visited[p.f]){
            visited[p.f]=true;
            dfs(p.f);
        }
    }
}


bool eqn_eql(eqn e1,eqn e2){
    if(e1.a==e2.b || e1.a==e2.a)return true;
    if(e2.a==e1.b || e1.a==e1.a)return true;
    return false;
}

void solve(){
    io_setup();
    int n,m;
    cin >> n >> m;
    bool flag = false;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        // if(E[a][b]!=0 && E[a][b]!=c){flag = true;}
        E[a][b] = c;
        E[b][a] = c;
        // adjList.at(a).pb({b,c});
        // adjList.at(b).pb({a,c});
    }
    if(flag){
        cout << "NO" << "\n";
    }
    for(int i=1;i<n;i++){
        if(visited[i])continue;
        //for each component
        dfs(i);

    }
    for(eqn e:vec)print(e);
}

int main(){
    solve();
}


/*
Edge cases: Seperate components
            Seperates comps with single edge
            same edge with different values -> handled

For each comp find a node with degree>=2 and create another eqn. Obtain the value of one and keep substituting
*/

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
