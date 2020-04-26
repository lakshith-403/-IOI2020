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

bool getSquare(int X,int Y){
  cout << "examine " << X << " " << Y << endl;
  string temp;
  cin >> temp;
  if(temp=="YES")return true;
  return false;
}

int XL,XR,YU,YD,L;
pi MID;

int main(){
  io_setup();
  int n,x,y;
  cin >> n >> x >> y;
  int end = x+(int)pow(2,100);
  FORZ(i,100){
    if(x+(ll)pow(2,i)>=n){end=n-1;break;}
    end = x+(int)pow(2,i);
    if(!getSquare(x+(int)pow(2,i),y))break;
  }
  int lo,hi,mid;
  lo = x;
  hi = end;
  mid = (lo+hi)/2;
  while(lo<=hi){
    mid = (lo+hi)/2;
    if(getSquare(mid,y))lo=mid+1;
    else hi=mid-1;
  }
  XR = mid-1;
  what_is(XR);
  FORZ(i,100){
    if(x-(ll)pow(2,i)<0){end=0;break;}
    end = x-(int)pow(2,i);
    if(!getSquare(x-(int)pow(2,i),y))break;
  }
  lo = end;
  hi = x;
  while(lo<=hi){
    mid = (lo+hi)/2;
    if(getSquare(mid,y))hi=mid-1;
    else lo = mid+1;
  }
  XL = mid;
  what_is(XL);
  L = XR-XL;
  FORZ(i,100){
    if(y+(ll)pow(2,i)>=n){end=n-1;break;}
    end = y+(ll)pow(2,i);
    if(getSquare(x,y+(int)pow(2,i)))break;
  }
  lo = y;
  hi = end;
  while(lo<=hi){
    mid = (lo+hi)/2;
    if(getSquare(x,mid))lo=mid+1;
    else hi = mid-1;
  }
  YU = mid-1;
  YD = YU+L;
  what_is(YU);
  what_is(YD);
  MID = {(XL+XR)/2,(YU+YD)/2};
  int left = 0,down=0;
  FOR(i,1,3){
    if(MID.f+i*2*L>=n || !getSquare(MID.f+i*2*L,y)){left = i-1;break;}
  }
  FOR(i,1,3){
    if(MID.s-i*2*L<0 || !getSquare(x,MID.s-i*2*L)){down = i-1;break;}
  }
  int X,Y;
  X = (MID.f+left*2*L)-(2*L);
  Y = (MID.s+down*2*L)-(2*L);
  cout << "report " << X << " " << Y << endl;
}
//ATTENTION:
/*
Not sure about how the Binary search gonna end;
i.e will the end be the last flatten square or the square after it
test it out
UPDATE: THIS CODE DOESN'T WORK and i'm leaving this
        to cry in a corner
*/


/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
