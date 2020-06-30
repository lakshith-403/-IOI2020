#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

bool black[200000];
bool white[200000];
vector<int> C;
string temp = "";
string in;
int n;

void solve(int k,int l,int pos[]){
  if(k<0)return;
//   cout << pos[k] << "\t" << l-C[k]+1 << "\n";
  int i;
  for(i=pos[k];i<=l-C[k]+1;i++){
    if(in[i+C[k]-1]=='_'){continue;}
    if(in[i-1]=='X')break;
    bool flag = false;
    for(int j=i;j<=i+C[k]-1;j++)if(in[j]=='_'){flag = true;}
    if(flag)continue;
//     cout << i << "\n";
    black[i+C[k]-1]=true;
    for(int j=i;j<=i+C[k]-1;j++)black[j]=true;
    int last = 0;
    if(k!=0)last = pos[k-1]+C[k-1];
    for(int j=last;j<=i-1;j++)if(in[j]!='X')white[j]=true;
    white[i-1]=true;
  }
//   cout << i-1 << "\n";
  solve(k-1,i-3,pos);
}

string solve_puzzle(string s,vector<int> c){
  n = s.length();
  in = s;
  C = c;
  int i = 0,j=0;
  int pos[100];
  for(int x:c){
    pos[i++]=j;
    for(int i=0;i<x;i++)
      temp+="X",j++;
    temp+="_",j++;
  }
  while(temp.length()<n)temp+="_";
  for(int i=0;i<n;i++)if(temp[i]=='X')black[i]=true;else if(temp[i]=='_')white[i]=true;
  solve(c.size()-1,n-1,pos);
  string ans = "";
  for(int i=0;i<n;i++){
    if(black[i]&&!white[i])ans+='X';
    else if(!black[i]&&white[i])ans+='_';
    else ans+='?';
  }
  return ans;
}

// int main(){
//   vector<int> vec = {3,4};
//   cout << solve_puzzle("..........",vec) << "\n";
//   for(int i=0;i<10;i++)cout<<black[i];
//   cout << "\n";
//   for(int i=0;i<10;i++)cout<<white[i];
//   cout << "\n";
// }
