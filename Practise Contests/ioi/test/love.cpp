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

// === Debug macro starts here ===
int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
  os<<"[";
  for(auto& x:v){os<<x<<", ";}
  return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
  return os<<"{"<<p.first<<", "<<p.second<<"}";
}
// === Debug macro ends here ===

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int solveB(string s){
  int l,o,v,k,i,e,li;
  l =0,o=0,v=0,k=0,i=0,e=0,li=0;
  for(char c:s){
    if(c=='l')l++,li++;
    else if(c=='o'&&l!=0)l--,o++;
    else if(c=='v'&&o!=0)o--,v++;
    else if(c=='e'&&v!=0){
      v--,e++;
      if(li!=0)li--;
      else if(i!=0)i--;
      else if(k!=0)k--;
    }
    else if(c=='i'&&li!=0)li--,i++;
    else if(c=='k'&&i!=0)i--,k++;
    else if(c=='e'&&k!=0){
      k--,e++;
      if(l!=0)l--;
      else if(o!=0)o--;
      else if(v!=0)v--;
    }
  }
  return e;
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/


long int Lcount,Ocount,Vcount,Ecount,Icount,Kcount;

void print(){
    cout << "-----------------"<<'\n';
    cout << "L- " << Lcount<<'\n';
    cout << "O- " << Ocount<<'\n';
    cout << "V- " << Vcount<<'\n';
    cout << "E- " << Ecount<<'\n';
    cout << "I- " << Icount<<'\n';
    cout << "K- " << Kcount<<'\n';
    cout << "-----------------"<<'\n';
}

vector<string>  perm;


bool check(char u){
//cout << u << '\n';
//print();

    switch (u){
    case 'o':
        if(Ocount<Lcount){
        return true;
        }else{return false;}
        break;

    case 'v':
        if(Vcount<Ocount){
        return true;
        }else{return false;}
        break;

    case 'i':
        if(Icount<Lcount){
        return true;
        }else{return false;}
        break;

    case 'k':
        if(Kcount<Icount){
        return true;
        }else{return false;}
        break;

    case 'e':
        if(Kcount+Vcount>Ecount && Lcount>Ecount){
        return true;
        }else{return false;}
        break;

    }
    return false;

}

int solveA(string s){
    char l='l',o='o',v='v',e='e',i='i',k='k';
    Lcount=0,Ocount=0,Vcount=0,Ecount=0,Icount=0,Kcount=0;
    int x;
    string msg = s;
    x = msg.size();
    for(long int a=0;a<x;a++){

        if(msg[a]==l){
            Lcount++;
        }
        if(msg[a]==o && check(o)){
            Ocount++;
        }
        if(msg[a]==v && check(v)){
            Vcount++;
        }
        if(msg[a]==e && check(e)){
            Ecount++;
        }
        if(msg[a]==i && check(i)){
            Icount++;
        }
        if(msg[a]==k && check(k)){
            Kcount++;
        }
    }
    return Ecount;
}

void permute(string a, int l, int r)  
{  
    if (l == r){
      int x = solveA(a);
      int y = solveB(a);
      if(x==y)return;
      cout <<  "`"  << a << "\t" << x << "\t" << y << "`\n";
    }
    else
    {    
        for (int i = l; i <= r; i++)  
        {  
            swap(a[l], a[i]);  
            permute(a, l+1, r);  
   
            swap(a[l], a[i]);  
        }  
    }  
}  

int main()  
{  
    string str = "lovelike";
    int n = str.size();  
    permute(str, 0, n-1);  
    return 0;  
}

