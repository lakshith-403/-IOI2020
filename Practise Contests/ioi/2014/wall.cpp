/*
ATTENTION : NOT COMPLETE
*/


#include <bits/stdc++.h>
#define pi pair<int,int>
#define f first
#define s second

using namespace std;

int* res;

struct segTree{
  pi tree[4200000];
  void upload(int p,int v,int op){
    if(op==1){
      tree[p].f = max(tree[p].f,v);
      tree[p].s = max(tree[p].f,v);
    }else{
      tree[p].f = min(tree[p].f,v);
      tree[p].f = min(tree[p].s,v);
    }
  }

  void insert(int s,int e,int p,int ps,int pe,int v,int op){
    if(pe<s || ps>e)return;
    if(s<=ps&&pe<=e){
      upload(p,v,op);
      res[s] = tree[p].first; 
    }else{

    }
  }

}seg;

//subtask 1
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  for(int i=0;i<n;i++)finalHeight[i]=0;
  for(int i=0;i<k;i++){
    int l=left[i],r=right[i],h=height[i],o=op[i];
    for(int j=l;j<=r;j++)
      if(o==1)finalHeight[j] = max(h,finalHeight[j]);
      else finalHeight[j] = min(h,finalHeight[j]);
  }
  return;
}

int main(){
  
}
