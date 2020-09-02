/*
Segment tree for Range sum Query
*/

#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

inline int getMid(int l,int r){return (l+(r-l)/2);}

int getSumUtil(int *st,int ss,int se,int qs,int qe,int si){
  if(qs<=ss && qe>=se)return st[si];
  if(se<qs || ss>qe)return 0;
  int mid = getMid(ss,se);
  return getSumUtil(st,ss,mid,qs,qe,si*2+1) + getSumUtil(st,mid+1,se,qs,qe,si*2+2);
}

int getSum(int*st, int n, int qs, int qe){
  return getSumUtil(st,0,n-1,qs,qe,0);
}

int constructSegTreeUtil(int arr[],int ss,int se,int* st,int si){
  if(ss==se){
    st[si] = arr[ss];
    return st[si];
  }
  int mid = getMid(ss,se);
  st[si] = constructSegTreeUtil(arr,ss,mid,st,si*2+1) + constructSegTreeUtil(arr,mid+1,se,st,si*2+2);
  return st[si];
}

void updateValuesUtil(int *st,int ss,int se,int i,int dif,int si){
  if(i<ss || i>se)return;
  st[si]+=dif;
  if(ss!=se){
    int mid = getMid(ss,se);
    updateValuesUtil(st,ss,mid,i,dif,si*2+1);
    updateValuesUtil(st,mid+1,se,i,dif,si*2+2);
  }
}

void update(int arr[], int*st,int i,int n,int new_val){
  int dif = arr[i]-new_val;
  arr[i] = new_val;
  updateValuesUtil(st,0,n-1,i,dif,0);
}

int* constructSegTree(int arr[],int n){
  int x = (int)ceil(log2(n));
  int max_size = 2*(int)pow(2,x) -1;
  int* st = new int[max_size];
  constructSegTreeUtil(arr,0,n-1,st,0);
  return st;
}

int main(){
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++)cin >> arr[i];
  int* st = constructSegTree(arr,n);
  while(true){
    int qs,qe;
    cin >> qs >> qe;
    if(qs == -1)break;
    cout << getSum(st,n,qs,qe) << "\n";
  }
}
