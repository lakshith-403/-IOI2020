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

ll gcd(ll a, ll b) { 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

 ll lcm(ll a, ll b)  
 {  
    return (a*b)/gcd(a, b);  
 }

ll findGCD(vector<ll> vec, int n) { 
    ll result = vec[0]; 
    for (int i = 1; i < n; i++) { 
        result = gcd(vec[i], result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
}

int main(){
  io_setup();
  int n;
  cin >>n ;
  ll total = 0;
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  if(n==1){cout << arr[0];return 0;}
  vector<ll> vec;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++)
      vec.pb(lcm(arr[i],arr[j]));
  }
  cout << findGCD(vec,n) << "\t";
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
