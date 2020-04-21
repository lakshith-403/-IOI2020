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
#define what_is(x) cerr << #x << " is " << x << "\n";

#define printl(a) cout << a << "\n";
#define prints(a) cout << a << " ";
#define printall(x) FORZ(i,sz(x))prints(x[i])
#define nextl cout << "\n"

#define in(a) cin >> a;

int arr[200001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n,k;
    in(n);
    in(k);
    FOR(i,1,n)in(arr[i]);
    pi r = {min(arr[1],arr[n]) , arr[1]+arr[n]+(k-min(arr[1],arr[n]))};
    int Count = 0;
    FOR(i,1,n/2){
      int a = arr[i];
      int b = arr[n-i+1];
      pi tempR = {min(a,b) , a+b+(k-min(a,b))};
      // what_is(a);
      // what_is(b);
      // prints(tempR.f);
      // printl(tempR.s);
      if(tempR.s<r.f || tempR.f>r.s){
        Count+=2;
        continue;
      }
      r = {max(tempR.f,r.f),min(tempR.s,r.s)};
      Count ++;
    }
    int Ccount = 0;
    map<int,int> M;
    int MAX = 0;
    FOR(i,1,n/2){
      int a = arr[i];
      int b = arr[n-i+1];
      if((a+b)<r.f || (a+b)>r.s)continue;
      if(a+b==r.f)continue;
      // printl(a+b);
      if(M.count(a+b)!=0){
        M.find(a+b)->second = M.find(a+b)->second+1;
      }else{
        M.insert({a+b,1});
      }
      MAX = max(MAX,M.find(a+b)->second);
    }
    // printl(r.s);
    // prints(r.f);
    printl(Count-MAX);
  }
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
