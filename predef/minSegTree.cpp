#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

inline int getMid(int s,int e){return s+(e-s)/2;}

int getMin(int* st,int ss,int se,int qs,int qe,int si){
  if(ss>qe || se<qs)return INT_MAX;
  if(ss>=qs && se<=qe)return st[si];
  int mid  = getMid(ss,se);
  return min(getMin(st,ss,mid,qs,qe,si*2+1),getMin(st,mid+1,se,qs,qe,si*2+2));
}

int createMinSegUtil(int* arr,int* st,int ss,int se,int si){
  if(ss==se){
    st[si] = arr[ss];
    return st[si];
  }
  int mid = getMid(ss,se);
  st[si] = min(createMinSegUtil(arr,st,ss,mid,si*2+1) , createMinSegUtil(arr,st,mid+1,se,si*2+2));
  return st[si];
}

int* createMinSeg(int* arr ,int n){
  int x = (int)ceil(log2(n));
  int max_size = (int)pow(x,2)+1;
  int* st = new int[max_size];
  createMinSegUtil(arr,st,0,n-1,0);
  return st;
}

int main(){
//   io_setup();
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++)cin >> arr[i];
  int* st = createMinSeg(arr,n);
  while(true){
    int qs,qe;
    cin >> qs >> qe;
    cout << getMin(st,0,n-1,qs,qe,0) << "\n";
  }
}
