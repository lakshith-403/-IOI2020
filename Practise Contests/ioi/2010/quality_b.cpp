// nlogn implementation with binary search

#include <bits/stdc++.h>

#define pi pair<int,int>
#define x first
#define y second

using namespace std;

int r,c,h,w;
int q[3001][3001];
bool b[3001][3001];
bool flag = false;
pi pos;
void down(pi p,int x,int lo,int hi);
void left(pi p,int x,int lo,int hi);

void down(pi p,int x,int lo,int hi){
  if(flag)return;
  if(p.x>=r || p.y>=c)return;
//   cout << lo << "<>" << hi << "\n";
  if(p.x-h>=pos.x)
  for(int i=p.y;i>p.y-w;i--)
    if(q[p.x-h][i]<x)lo--;
    else if(q[p.x-h][i]>x)hi--;
//   cout << p.x << "," << p.y << "\t" << lo << " " << hi << "\n";
  for(int i=p.y;i>p.y-w;i--)
    if(q[p.x][i]<x)lo++;
    else if(q[p.x][i]>x)hi++;
  if(lo==hi){
    flag = true;
    return;
  }
  cout << p.x << "," << p.y << "\t" << lo << " " << hi << "\n";
  left({p.x,p.y+1},x,lo,hi);
  down({p.x+1,p.y},x,lo,hi);
}

void left(pi p,int x,int lo,int hi){
  if(flag)return;
  if(p.x>=r || p.y>=c)return;
  if(p.y-w>=pos.y)
  for(int i=p.x;i>p.x-h;i--)
    if(q[i][p.y-w]<x)lo--;
    else if(q[i][p.y-w]>x)hi--;
//   cout << p.x << "," << p.y << "\t" << lo << " " << hi << "\n";
  for(int i=p.x;i>p.x-h;i--)
    if(q[i][p.y]<x)lo++;
    else if(q[i][p.y]>x)hi++;
  if(lo==hi && lo+hi==(h*w)-1){
    flag = true;
    return;
  }
//   cout << p.x << "," << p.y << "\t" << lo << " " << hi << "\n";
  left({p.x,p.y+1},x,lo,hi);
  if(p.y-w+1==pos.y)down({p.x+1,p.y},x,lo,hi);
}

int rectangle(int R,int C,int H,int W,int Q[3001][3001]){
  r = R;
  c = C;
  h = H;
  w = W;
  for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
      q[i][j] = Q[i][j];
    
  int l=1,r=(h*w)-1;
  while(l-r){
    int mid = (l+r)/2;
    int lo = 0;
    int hi = 0;
    int x = mid;
    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
        if(q[i][j]==x){pos.x=i,pos.y=j;j=c;break;}
    
      for(int i=max(0,pos.x-h+1);i<max(0,pos.x-h+1)+h;i++)
      for(int j=max(0,pos.y-w+1);j<max(0,pos.y-w+1)+w-1;j++)
        if(q[i][j]<x){lo++;}
        else if(q[i][j]>x){hi++;}
  //   cout << lo << "<>" << hi  << "\n";
  //   cout << max(0,pos.y-w+1) << " " << max(0,pos.y-w+1)+pos.y << "\n";
    left({max(0,pos.x-h+1)+h-1,max(0,pos.y-w+1)+w-1},x,lo,hi);
    if(flag)r=mid-1;
    else l=mid+1;
  }
  cout << flag << "\n";
  return 0;
}

int arr[3001][3001];
int main(){
  int r,c,h,w;
  cin >> r >> c >> h >> w;
  for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
      cin >> arr[i][j];
  cout << rectangle(r,c,h,w,arr);
}
