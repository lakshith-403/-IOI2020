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

struct Compare { 
    bool operator()(pi const& p1, pi const& p2) 
    { 
        if(p1.s-p1.f<p2.s-p2.f)return true;
        if(p1.s-p1.f>p2.s-p2.f)return false;
        return (p1.f>p2.f);
    } 
};

int getMid(pi P){
  if((P.s-P.f+1)%2==1){
    return (P.s + P.f)/2;
  }else{
    return (P.s + P.f - 1)/2;
  }
}

void solve(int t){
  int n;
  in(n);
  int arr[n];
  priority_queue<pi,vpi,Compare> pq;
  pq.push({1,n});
  int index = 1;
//   what_is(n);
  while(!pq.empty()){
    pi pr = pq.top();
    pq.pop();
//     what_is(pr.f);
//     what_is(pr.s);
    int mid = getMid(pr);
    arr[mid]=index++;
//     what_is(mid);
    if(pr.f!=mid)
    pq.push({pr.f,mid-1});
    if(pr.s!=mid)
    pq.push({mid+1,pr.s});
  }
  for(int i=1;i<=n;i++)
    prints(arr[i]);
  cout << "\n";
}

int main(){
  io_setup();
  int t;
  cin >> t;
  while(t--){
    solve(t+1);
  }
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
