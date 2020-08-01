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

vector<vector<int>> adjList(1001,vector<int>());
bool visited[1001];

void makeTree(int src,int p){
    for(int i=0;i<adjList[src].size();i++){
        if(adjList.at(src).at(i)==p)adjList.erase(adjList.begin()+i);
    }
    for(int x:adjList[src]){
        makeTree(x,src);
    }
}

int dist[11][11];
int V;
int ans[11];

void floydWarshall (int graph[][11])  {  
    int  i, j, k; 
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
    for (k = 0; k < V; k++)  
    {  
        for (i = 0; i < V; i++)  
        {  
            for (j = 0; j < V; j++)  
            {  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
}
int MIN = INT_MIN;
void heapPermutation(int a[], int size, int n) { 
    if (size == 1) 
    { 
        int sum = 0;
        for(int i=0;i<n;i++){
            if(a[i]==i)return;
            sum += dist[i][a[i]];
        }
        if(MIN>sum)return;
        for(int i=0;i<n;i++)
            ans[i] = a[i];
        MIN = max(MIN,sum);
        return; 
    } 
  
    for (int i=0; i<size; i++) { 
        heapPermutation(a,size-1,n); 

        if (size%2==1) 
            swap(a[0], a[size-1]); 
        else
            swap(a[i], a[size-1]); 
    } 
}

void solve(int t){
    int n;
    cin >> n;
    V = n;
    int G[V][11];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    G[i][j]=99999;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b]=1;
        G[b][a]=1;
    }
    floydWarshall(G);
    int a[n];
    for(int i=0;i<n;i++){
        a[i] = i;
    }
    heapPermutation(a,n,n);
    cout << MIN << "\n";
    for(int i=0;i<n;i++)
    cout << ans[i]+1 << " ";
    cout << "\n";
}

int main(){
    int t =1;
    while(t--)
        solve(t+1);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
