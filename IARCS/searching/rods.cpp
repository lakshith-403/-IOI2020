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
  ios_base::sync_With_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL)l
}

int n;
int x1,x2,y1,y2;
int c1,c2,c3,c4;

int getRect(int x1,int y1,int x2,int y2){
  if(x1>x2)swap(x1,x2);
  if(y1>y2)swap(y1,y2);
  x1 = max(x1,1);
  x2 = max(x2,1);
  y1 = min(y1,n);
  y2 = min(y2,n);
  return rect(x1,y1,x2,y2);
}

int binarySearch(int x,int y,int dx,int dy,int offx=0,int offy=0){
  int low = 0;
  int high = n;
  while(lo<=high){
    int mid = (low+high)/2;
    if(getRect(x+offx,y+offy,x+dx*mid,y+dx*mid)==1)high = mid-1;
    else low = mid+1;
  }
  return
}

int main(){
  io_setup();
  n = gridSize();

}
/////////////////////////////////////////
////////////////////////////////////////
///////////////GAVE UP/////////////////
///////////////////////////////////////
///////////////////////////////////////
/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
