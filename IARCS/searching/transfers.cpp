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

int arr[100000];
int n,k;

bool checkDis(int dis){
  int prev = max(0,arr[0]-k);
  prints(prev);
  FOR(i,1,n-1){
    if(prev+dis>arr[i]+k)return false;
    if(prev+dis<arr[i]-k)prev=arr[i];
    else prev+=dis;
    prints(prev);
  }
  printl("");
  return true;
}

int main(){
  io_setup();
  in(n);
  in(k);
  FORZ(i,n)in(arr[i]);
  sort(arr,arr+n);
  int lo = 1;
  int hi = n;
  int MAX = INT_MIN;
  while(lo<=hi){
    int mid = (lo+hi)/2;
    if(checkDis(mid)){
        MAX = max(MAX,mid);
        lo = mid+1;
    }else hi = mid-1;
  }
  printl(--MAX);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
