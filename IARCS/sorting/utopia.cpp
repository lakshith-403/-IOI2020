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
int n;
int arrX[10000];
int arrY[10000];
int v[10000];

int x[10000];
int y[10000];

int main(){
  io_setup();
  in(n);
  FORZ(i,n)in(arrX[i]);
  FORZ(i,n)in(arrY[i]);
  int prevX=0,prevY=0,Count=0;
  FORZ(i,n){
    in(v[i]);
    if(v[i]==1||v[i]==3)x[i]=-1;
    else x[i]=1;
    if(v[i]==1||v[i]==2)y[i]=1;
    else y[i]=-1;
    if(x[i]==prevX)Count++;
    else prevX=x[i];
    if(y[i]==prevY)Count++;
    else prevY=y[i];
  }
  sort(arrX,arrX+n);
  sort(arrY,arrY+n);
  arrX[Count] *= x[0];
  arrY[Count] *= y[0];
  FOR(i,Count+1,n-1){
    arrX[i] *= (i-Count)%2==0 ? x[0] : x[0]*-1;
    arrY[i] *= (i-Count)%2==0 ? y[0] : y[0]*-1;
  }
  FORi(i,Count-1,0){
    arrX[i] *= (Count-i)%2==0 ? x[0] : x[0]*-1;
    arrY[i] *= (Count-i)%2==0 ? y[0] : y[0]*-1;
  }
  int left=Count,right=Count;
  prevX=0,prevY=0;
  FORZ(i,n){
    if(x[i]==prev){
      prints(arr)
    }
  }
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
