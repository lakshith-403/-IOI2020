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
int arr[100001];

int solve(){
  io_setup();
  int n,k;
  cin >> n >> k;
  bool flag = false;
  vector<int> pos;
  for(int i=0;i<n;i++){
    cin >> arr[i];
    if(arr[i]==k){flag = true;pos.pb(i);}
  }
  if(n==1 && k==arr[0]){cout << "YES" << "\n";return 0;}
  if(!flag){cout<<"NO"<<"\n";return 0;}
  for(int x:pos){
    int minCount = 0;
    int maxCount = 0;
    int eCount = 0;
    flag = false;
    if(x==0){
      for(int i=1;i<n;i++){
        if(arr[i]<k)minCount++;
        else if(arr[i]>k)maxCount++;
        else if(arr[i]==k)eCount++;
        
        if(minCount==maxCount || max(minCount,maxCount)-min(minCount,maxCount)==eCount || eCount>=2)
        {
          flag = true;
          break;
        }
      }
    }else if(x==n-1){
      for(int i=n-2;i>=0;i--){
        if(arr[i]<k)minCount++;
        else if(arr[i]>k)maxCount++;
        else if(arr[i]==k)eCount++;
        
        if(minCount==maxCount ||maxCount-minCount ==1|| max(minCount,maxCount)-min(minCount,maxCount)==eCount || eCount>=3)
        {
          flag = true;
          break;
        }
      }
    }else{
      int Min[n];
      int Max[n];
      int eq[n];
      if(arr[0]<k)Min[0] = 1;
      else Min[0] = 0;
        if(arr[0]>k)Max[0] = 1;
        else Max[0] = 0;
        if(arr[0]==k)eq[0] = 1;
        else eq[0] = 0;
      for(int i=1;i<n;i++){
        if(i==x)continue;
        if(arr[i]<k)Min[i] = Min[i-1]+1;
        if(arr[i>k])Max[i] = Max[i-1]+1;
        if(arr[i]==k)eq[i] = eq[i-1]+1;
      }
      for(int i=x-1;i>=0;i--){
        for(int j=x+1;j<n;j++){
          minCount= Min[j] - (i==0?0:Min[i-1]);
          maxCount= Max[j] - (i==0?0:Max[i-1]);
          eCount = eq[j] - (i==0?0:eq[i-1]);
          if(minCount==maxCount ||maxCount-minCount ==1|| max(minCount,maxCount)-min(minCount,maxCount)==eCount || eCount>=3)
          {
            flag = true;
            i=-1;
            break;
          }
        }
      }
    }
    if(flag){cout << "YES" << "\n";return 0;}
  }
  cout << "NO" << "\n";
  return 0;
}

int main(){
  io_setup();
  int t;
  cin >> t;
  while(t--)solve();
}


/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
