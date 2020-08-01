#include <bits/stdc++.h>
#define pi pair<int,int>
#define f first
#define s second
#define pb push_back
#define ll long long
#define shit cout << "shit\n";

using namespace std;

inline void io_setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<pi> a;

bool compare(pi p1,pi p2){
    double x = (double)p1.s/(double)p1.f;
    double y = (double)p2.s/(double)p2.f;
    return x>y;
}

ll max(ll a,ll b){
    return a<b?b:a;
}

void printVec(vector<int> vec){
    for(int x:vec)cout << x << " ";
    cout << "\t";
}

ll A[101];
ll ans = 0;
vector<int> vec;
string s;

map<string,int> M;

string conv(vector<int> v){
    string a = "";
    for(int x:vec)a+= to_string(x) + " ";
    return a;
}

int f(vector<int> vec){
    // cout << vec.size() << "\t" << sum << "\n";
    if(vec.size()==1){
        // ans = max(ans,sum+A[vec[0]]);
        return A[vec[0]];
    }
    string a = conv(vec);
    if(M.count(a)!=0)return M.at(a);
    // printVec(vec);
    int n = vec.size();
    int r = 0;
    for(int i=0;i<n;i++){
        vector<int> t(vec);
        if(i==0||i==n-1)t.erase(t.begin()+i);
        else t.erase(t.begin()+(i-1),t.begin()+(i+1)+1);
        if(i!=0&&i!=n-1)
        t.insert(t.begin()+(i-1),vec[i-1]+vec[i+1]);
        // printVec(vec);
        // printVec(t);
        // cout << sum+ A[vec[i]] << "\n";
        r = max(r,f(t)+A[vec[i]]);
    }
    M.insert({a,r});
    return r;
}

int approach2(){
    return f(vec);
    // return ans;
}

ll approach1(){
    ll ans1 = 0;
    int z=0,o=0;
    for(char c:s)
        if(c=='1')o++;
        else z++;
    char c = '1';
    int i = 0;
    while(i<s.size()){
        if(s[i]!=c){i++;continue;}
        int r=0;
        while(i<s.size()&&s[i]==c)r++,i++;
        ans1 += A[r];
    }
    ans1 += A[c=='0'?o:z];

    ll ans2 = 0;
    i = 0;
    c = '0';
    while(i<s.size()){
        if(s[i]!=c){i++;continue;}
        int r=0;
        while(i<s.size()&&s[i]==c)r++,i++;
        ans2 += A[r];
    }
    ans2 += A[c=='0'?o:z];
    // cout << (ans1<ans2?ans2:ans1) << "\n";
    return (ans1<ans2?ans2:ans1);
}

int main(){
    int n;
    cin >> n >> s;
    // n = 6;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        a.pb({i,x});
    }
    sort(a.begin(),a.end(),compare);
    for(int i=1;i<=n;i++){
        int r=0;
        int pos=0;
        ll sum = 0;
        while(r<i){
            if(r+a[pos].f<=i){
                r+=a[pos].f;
                sum += a[pos].s;
            }else
            pos++;
        }
        A[i] = sum;
    }
    // for(int i=1;i<=n;i++)cout << A[i] << "\t";cout << "\n";
    // for(int i=0;i<vec.size();i++)cout << vec[i] << "\t";cout << "\n"; 
    // f(vec,0);
    // cout << ans << "\n";
    // for(int i=10;i<64;i++){
        // s = std::bitset<6>(i). to_string();
        // cin >> s;
        vec.erase(vec.begin(),vec.end());
        int Count=0;
        char prev = ' ';
        for(int i=0;i<n;i++){
            if(s[i]==prev)Count++;
            else{
                if(Count!=0)
                vec.pb(Count);
                prev = s[i];
                Count = 1;
            }
        }
        if(Count!=0)vec.pb(Count);
        ll a = approach2();
        cout <<a << "\n";
        // ll b = approach2();
        // if(a==b)continue;
        // cout << a << "\t" << b << " " << s <<"\n";
    // }
}












/*
*/