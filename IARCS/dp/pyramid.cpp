#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int N,M,a,b,c,d;
int in[1000][1000];
int prefSum[1001][1001];

vector<vector<int>> st(1025,vector<int>(1025));
vector<vector<int>> mat;

int m,n;

inline int getMid(int ss,int se){return (ss+se)/2;}

//create a 1d minimum segment tree
int createMinSegUtil(vector<int> &arr,vector<int> &st,int ss,int se,int si){
  if(ss==se){
    st.at(si) = arr[ss];
    return st[si];
  }
  int mid = getMid(ss,se);
  st.at(si) = min(createMinSegUtil(arr,st,ss,mid,si*2+1) , createMinSegUtil(arr,st,mid+1,se,si*2+2));
  return st[si];
}

//get minimum of 1d segment tree
int getMin(vector<int> &st,int ss,int se,int qs,int qe,int si){
  if(ss>qe || se<qs)return INT_MAX;
  if(ss>=qs && se<=qe)return st[si];
  int mid  = getMid(ss,se);
  return min(getMin(st,ss,mid,qs,qe,si*2+1),getMin(st,mid+1,se,qs,qe,si*2+2));
}

//create 2d minimum segment tree
void create2dMinSeg(int ss,int se,int si){
  if(ss==se)
    createMinSegUtil(mat[se],st[si],0,m-1,0);
  else{
    int mid = (ss+se)/2;
    create2dMinSeg(ss,mid,si*2+1);
    create2dMinSeg(mid+1,se,si*2+2);
    //idk F is happening here but this merge should be done
    for(int i=0;i<st[si].size();i++)
      st.at(si).at(i) = min(st[si*2+1][i],st[si*2+2][i]);
  }
}

//get minimum of a range
int get2dMin(int si,int ss,int se,int x1,int y1,int x2,int y2){
  if(ss>x2 || se<x1)return INT_MAX;
  if(ss>=x1 && se<=x2)
    return getMin(st[si],0,m-1,y1,y1,0);
  int mid = (ss+se)/2;
  return min(get2dMin(si*2+1,ss,mid,x1,y1,x2,y2),get2dMin(si*2+2,mid+1,se,x1,y1,x2,y2));
}

int getSum(pair<int,int> c1,pair<int,int> c2){
  return prefSum[c2.x+1][c2.y+1] 
        -prefSum[c1.x+1][c2.y+1]
        -prefSum[c2.x+1][c1.y+1]
        +prefSum[c1.x+1][c1.y+1];
}

int main(){
  io_setup();
  cin >> N >> M >> a >> b >> c >> d;
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      cin >> in[i][j];
  //calculate prefsum
  for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
      prefSum[i][j] += prefSum[i-1][j]+prefSum[i][j-1]+in[i-1][j-1]-prefSum[i-1][j-1];
  
  for(int i=0;i<N-c;i++){
    vector<int> vec;
    for(int j=0;j<M-d;j++){
      int sum = getSum({i,j},{i+c-1,j+d-1});
      vec.push_back(sum);
    }
    mat.push_back(vec);
  }
  n = mat.size();
  m = mat.at(0).size();
  create2dMinSeg(0,n-1,0);
  int MAX = INT_MIN;
  pair<int,int> AB;
  pair<int,int> CD;
  for(int i=0;i<N-a;i++)
    for(int j=0;j<N-b;j++){
      int sum = getSum({i,j},{i+a-1,j+b-1});
//       cout << i << "<>" << j << "\t" << i+a << "<>" << j+b << "\n";
//       cout << sum << "\t";
      int Min = get2dMin(0,0,n-1,i+1,j+1,i+a-c-1,j+b-d-1);
//       cout << Min << "\n";
      if(MAX<sum-Min){
        
      }
      MAX = max(MAX,sum-Min);
    }
  cout << MAX << "\n";
}

/*
 6 6 3 3 1 1
2 2 2 2 2 2
2 2 2 1 2 2
2 2 2 2 2 2
2 2 2 2 2 2
2 2 2 2 2 2
2 2 2 2 2 2
 */
