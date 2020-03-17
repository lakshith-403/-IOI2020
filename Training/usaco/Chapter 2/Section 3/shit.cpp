/*
 ID: lakshit4
 LANG: C++
 TASK: concom
*/

#include<fstream>
#include<cstring>
using namespace std; fuck
const int mm=889;
ifstream cin("concom.in");
ofstream cout("concom.out");
int map[mm][mm],cnt[mm];
bool s[mm],flag[mm];
void dfs(int x,int n)
{
  if(flag[x])return;
  flag[x]=1;
  for(int i=1;i<=n;i++)
  {
    cnt[i]+=map[x][i];
    if(cnt[i]>50)
    { s[i]=1;
      dfs(i,n);
    }
  }
}
int main()
{
  int m,a,b,c,n=0;
  cin>>m;
  memset(map,0,sizeof(map));
  for(int i=0;i<m;i++)
  {
    cin>>a>>b>>c;
    map[a][b]+=c;
    if(a>n)n=a;if(b>n)n=b;
  }
  for(int i=1;i<=n;i++)
  { memset(s,0,sizeof(s));
    memset(flag,0,sizeof(flag));
    memset(cnt,0,sizeof(cnt));
    dfs(i,n);
    for(int j=1;j<=n;j++)
    if(s[j]&&j!=i)
    cout<<i<<" "<<j<<"\n";
  }
}