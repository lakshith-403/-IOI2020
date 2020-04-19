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
// #define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORi(i,a,b) for(int i=(a);i>=(a);i--)
#define FORZ(i,a) for(int i=0;i<(a);i++)
#define FORZi(i,a) for(int i=(a)-1;i>=0;i--)
#define trav(a,x) for (auto& a: x)

#define printl(a) cout << a << "\n";
#define prints(a) cout << a << " ";
#define printall(x) FORZ(i,sz(x))prints(x[i])
#define nextl cout << "\n"

#define in(a) cin >> a;
#define N 200001

vector<vector<int>> adjList(N);
int score[N];
int visited[N];
int Count[N];
bool IndB[N];
vector<int> Ind;
vector<int> temp;

bool compare(int a,int b){
  if(score[a]==0)return b;
  if(score[b]==0)return a;
  return score[a]<score[b];
}

int main(){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
      temp.pb(i);
    FORZ(i,n-1){
      // score[i]=0;
      // visited[i]=0;
      int u,v;
      cin >> u >> v;
      adjList.at(u).eb(v);
      adjList.at(v).eb(u);
      Count[v]++;
      Count[u]++;
    }
    // score[n]=0;
    // visited[n]=0;
    FOR(I,1,n){
        if(Count[I]!=1)continue;
        list<int> q;
        visited[I] = I;
        q.push_back(I);
        prints("++++");
        printl(I);
        int s;
        while(!q.empty()) {
            s = q.front();
            // prints(s);
            score[s]++;
            if(s==1)break;
            q.pop_front();
            for(int i : adjList.at(s)){
                if (visited[i]!=I){
                    visited[i] = I;
                    score[i]++;
                    q.push_back(i);
                }
            }
        }
        // printl("");
    }
    FOR(i,1,n)
      prints(score[i]);
    printl("~");
    sort(temp.begin(),temp.end(),compare);
    for(int i=0;i<k;i++){
      int I = temp[i];
      IndB[I]=true;
      Ind.pb(I);
      prints("*");
      printl(I);
    }
    ll totalScore = 0;
    for(int I : Ind){
        list<int> q;
        visited[I] = I;
        q.push_back(I);
        prints(">");
        printl(I);

        int s;
        while(!q.empty()) {
            s = q.front();
            if(!IndB[s])totalScore++;
            prints(s);
            if(s==1)break;
            q.pop_front();
            for(int i : adjList.at(s)){
                if (visited[i]!=INT_MAX-I){
                    visited[i] = INT_MAX-I;
                    q.push_back(i);
                }
            }
        }
        printl("");
    }
    printl(totalScore);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
