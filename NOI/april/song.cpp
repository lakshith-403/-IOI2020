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

#define printl(a) cout << a << "\n";
#define prints(a) cout << a << " ";
#define printall(x) FORZ(i,sz(x))prints(x[i])
#define nextl cout << "\n"

#define in(a) cin >> a;
int N;
int arr[1001];
vpi vec;

bool compare(pi a,pi b){
  return a.s < b.s;
}

int main(){
  in(N);
  FORZ(i,N)in(arr[i]);
  FOR(i,0,N-3){
    int start = i;
    int end;
    int localMax = 0;
    int localMin = INT_MAX;
    bool MIN = arr[i+1]>arr[i];
    if(arr[i+1]==arr[i])continue;
    localMax=arr[i+1];
    localMin=arr[i+1];
    FOR(j,i+2,N-1){
      if(MIN)
        if(arr[j]<localMin){vec.pb({start,j});break;}
      if(!MIN)
        if(arr[j]>localMax){vec.pb({start,j});break;}
      localMax = max(localMax,arr[j]);
      localMin = min(localMin,arr[j]);
    }
  }
  sort(vec.begin(),vec.end(),compare);
  int end = -1;
  int Count = 0;
  for(pi p : vec){
    // prints(p.f);
    // printl(p.s);
    if(p.f>end){
      Count++;
      end=p.s;
    }
  }
  printl(Count);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
