#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define whatis(a) cout << #a << " is " << a << "\n";

using namespace std;

inline void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int num[4501];
int dp[1005][8200];

bool isPrime[8200];

void sieve(int n){
    for(int i=0;i<=n;i++)
        isPrime[i]=true;
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i<=n;i++)
        if(isPrime[i] && (long long)i*i<=n)
            for(int j = i*i;j<n;j+=i)
                isPrime[j]=false;
}

void solve(int t){
    sieve(8199);
    int n;
    cin >> n;
    for(int i=3500;i<=4500;i++)num[i] = 0;
    vector<int> vec;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        num[a]++;
        vec.pb(a);
    }
    for(int i=0;i<1005;i++)
        for(int j=0;j<8200;j++)
            dp[i][j] = 0;
    dp[0][0] = 1;
    dp[0][vec[0]] = 1;
    for(int i=1;i<vec.size();i++)
        for(int j=0;j<=8191;j++){
            dp[i][j] += dp[i-1][j];
            dp[i][i^j] += dp[i-1][j];
        }
    ll ans = 0;
    for(int i=0;i<=8191;i++)
        if(isPrime[i]){
            ans += dp[vec.size()-1][i];
        }
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve(t);
}