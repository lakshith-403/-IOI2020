#include <bits/stdc++.h>

#define shit cout << "shit i'm here" << "\n";

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

int find(int parent[], int i)  
{  
    if (parent[i] == -1)  
        return i;  
    return find(parent, parent[i]);  
}  
   
void Union(int parent[], int x, int y)  
{  
    int xset = find(parent, x);  
    int yset = find(parent, y);  
    if(xset != yset) 
    {  
        parent[xset] = yset;  
    }  
}

void solve(int t){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vi alph(26);
  FORZ(i,26)alph[i]=0;
  FORZ(i,n)alph[s[i]-'a']++;
  int MAX = 0;
  FORZ(i,26)MAX = max(MAX,alph[i]);
  int ans = 0;
  for(int i=n;i>0;i--){
    int parent[n+1];
    for(int j=0;j<n+1;j++)parent[j]=-1;
    for(int j=0;j<n;j++){
      int pos = j+k;
      pos %= n;
      what_is(pos);
      what_is(j);
      Union(parent,j,pos);
    }
    shit
    int Count[n+1];
    for(int j=0;j<=n;j++)Count[j]=0;
    for(int j=0;j<n;j++)Count[find(parent,j)]++;
    vi temp = alph;
    sort(all(temp));
    int j;
    for(j=0;j<n;j++){
      int l;
      for(l=0;l<temp.size();l++){
        if(Count[j]<=temp[l]){temp.at(l)-=Count[j];break;}
      }
      if(l==26)break;
    }
    if(j==i){ans=i;break;}
  }
  printl(ans);
}

int main(){
//   io_setup();
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
