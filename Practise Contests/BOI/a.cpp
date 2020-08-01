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

bool q(int i){
    cout << "? " << i << endl;
    int r;
    cin >> r;
    return (r==1);
}
int visited[1000];

int dis(int pos,int n,int m,int t){
    if(pos+m<=n && visited[pos+m]!=t)return pos+m;
    return pos-m;
}

void solve(int t){
    int n;
    cin >> n;
    int pos = 1;
    q(pos);
    int arr[n+1] = {8};
    visited[1] = t;
    for(int i = n-1;i>=1;i-=2){
        pos = dis(pos,n,i,t);
        visited[pos] = t;
        arr[i] = q(pos);
    }
    int i;
    // for(int i=1;i<n;i++)cout << arr[i] << " ";
    // cout<< "\n";
    for(i=1;i<n;i++)if(arr[i]==1)break;
    if(i!=1){
        pos = dis(pos,n,i-1,t);
        if(q(pos))i--;
    }
    cout << "= " << i << endl;
    // cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)
        solve(t+1);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
