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

int getClosest(int, int, int);

int findClosest(int arr[], int n, int target)
{
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];

    int i = 0, j = n, mid = 0;
    while (i < j) {
        mid = (i + j) / 2;

        if (arr[mid] == target)
            return arr[mid];

        if (target < arr[mid]) {
            if (mid > 0 && target > arr[mid - 1])
                return getClosest(arr[mid - 1],
                                  arr[mid], target);
            j = mid;
        }
        else {
            if (mid < n - 1 && target < arr[mid + 1])
                return getClosest(arr[mid],
                                  arr[mid + 1], target);

            i = mid + 1;
        }
    }
    return arr[mid];
}

int getClosest(int val1, int val2, int target) {
    if (target - val1 >= val2 - target)
        return val2;
    else
        return val1;
}

int R[100001];
int G[100001];
int B[100001];

int main(){
  int t;
  cin >> t;
  while(t--){
    int r,g,b;
    cin >> r >> g >> b;
    FORZ(i,r){
      cin >> R[i];}
    FORZ(i,g){
      cin >> G[i];}
    FORZ(i,b){
      cin >> B[i];}
    sort(R,R+r);
    sort(G,G+g);
    sort(B,B+b);
    ll MIN = LLONG_MAX;
    FORZ(i,r){
        ll rr = R[i];
        ll gg = findClosest(G,g,rr);
        ll bb = findClosest(B,b,rr);
        ll val = (rr-gg)*(rr-gg) + (gg-bb)*(gg-bb) + (bb-rr)*(bb-rr);
        // cout << val << "+\n";
        // prints("++");
        // prints(rr);
        // prints(gg);
        // printl(bb);
        MIN = min(MIN,val);
        bb = findClosest(B,b,gg);
        val = (rr-gg)*(rr-gg) + (gg-bb)*(gg-bb) + (bb-rr)*(bb-rr);
        MIN = min(MIN,val);
    }
    FORZ(i,g){
        ll gg = G[i];
        ll rr = findClosest(R,r,gg);
        ll bb = findClosest(B,b,gg);
        ll val = (rr-gg)*(rr-gg) + (gg-bb)*(gg-bb) + (bb-rr)*(bb-rr);
        // cout << val << "+\n";
        // prints("++");
        // prints(rr);
        // prints(gg);
        // printl(bb);
        // MIN = min(MIN,val);
        // bb = findClosest(B,b,gg);
        // val = (rr-gg)*(rr-gg) + (gg-bb)*(gg-bb) + (bb-rr)*(bb-rr);
        MIN = min(MIN,val);
    }
    FORZ(i,b){
        ll bb = B[i];
        ll rr = findClosest(R,r,bb);
        ll gg = findClosest(G,g,bb);
        ll val = (rr-gg)*(rr-gg) + (gg-bb)*(gg-bb) + (bb-rr)*(bb-rr);
        // cout << val << "+\n";
        // prints("++");
        // prints(rr);
        // prints(gg);
        // printl(bb);
        // MIN = min(MIN,val);
        // bb = findClosest(B,b,gg);
        // val = (rr-gg)*(rr-gg) + (gg-bb)*(gg-bb) + (bb-rr)*(bb-rr);
        MIN = min(MIN,val);
    }
    printl(MIN);
  }
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
