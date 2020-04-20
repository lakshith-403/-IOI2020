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

int M;
string bStrings[90];
string ans[91];
char temp;

string toBinary(int n){
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    while(r.length()<ceil(log2(M))+1)r="0"+r;
    return r;
}

int binaryToDecimal(string n){
    string num = n;
    int dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

int main(){
  in(M);
  FORZ(i,91)ans[i]="";
  FORZ(i,M)bStrings[i] = toBinary(i);
  FORZ(i,M)printl(bStrings[i]);
  FOR(i,1,ceil(log2(M))){
    FORZ(j,M){
      if(bStrings[j][i]!=bStrings[j][i-1]){cout<<"C "<<j+1<<"\n";in(temp)}}
    FOR(j,1,M){
      cout << "T " << j << "\n";
      temp = in(temp)=='Y'?1:0;
      ans[j]+=temp;
    }
  }
  prints("D");
  FOR(i,1,M){
    prints(binaryToDecimal(ans[i])+1);
  }
  printl("");
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
