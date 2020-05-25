#include <bits/stdc++.h>

using namespace std;

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

int main(){
  cin >> n >> m;
  for(int i=0;i<n;i++){
    vector<int> vec;
    for(int j=0;j<m;j++){
      int a;
      cin >> a;
      vec.push_back(a);
    }
    mat.push_back(vec);
  }
  create2dMinSeg(0,n-1,0);
  while(true){
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << get2dMin(0,0,n-1,x1,y1,x2,y2) << "\n";
  }
}
