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

#define printl(a) cout << a << "\n"
#define prints(a) cout << a << " "
#define printall(x) FORZ(i,sz(x))prints(x[i])
#define nextl cout << "\n"

#define in(a) cin >> a;

int main(){
  int t;
  in(t);
  while(t--){
    string s,c;
    cin >> s >> c;
    // printl(s);
    // printl(c);
    int index = -1;
    int i;
    bool flag = false;
    for(i=0;i<min(sz(s),sz(c));i++){
      if(s[i]>c[i]){break;}
      else if(s[i]<c[i]){flag = true;break;}
    }
    if(flag){
      printl(s);
      continue;
    }
    index = i;
    if(i>=sz(s)-1){
      printl("---");
      continue;
    }
    if(index==sz(c))index--;
    // printl(index);
    for(i=i+1;i<sz(s);i++){
      if(s[i]<c[index])break;
    }
    // printl(c[index]);
    if(i==sz(s)){
      printl("---");
      continue;
    }
    char temp = s[index];
    s[index] = s[i];
    s[i] = temp;
    printl(s);
  }
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
