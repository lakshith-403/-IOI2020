#include <bits/stdc++.h>
// #include "quality.h"

using namespace std;


void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[],int lo,int hi){
  int pivot = arr[hi];
  int i = lo;
  for(int j=lo;j<hi;j++)
    if(arr[j]<=pivot)swap(&arr[i],&arr[j]),i++;
  swap(&arr[i],&arr[hi]);
  return i;
}

int randomPartition(int arr[], int l,int r){
  int n = r-l+1;
  int pivot = rand()%n;
  swap(&arr[l+pivot],&arr[r]);
  return partition(arr,l,r);
}

int median(int arr[],int l,int r,int k){
  if(k<0 || k>r-l+1)return INT_MAX;
  int pos = randomPartition(arr,l,r);
  if(pos-l==k-1)
    return arr[pos];
  if(pos-l>k-1)
    return median(arr,l,pos-1,k);
  return median(arr,pos+1,r,k-pos+l-1);
}

int rectangle(int r,int c,int h,int w,int q[3001][3001]){
  int MIN = INT_MAX;
  for(int i=0;i<r-h+1;i++)
    for(int j=0;j<c-w+1;j++){
      int arr[h*w];
      int n = 0;
      for(int k=i;k<i+h;k++)
        for(int l=j;l<j+h;l++)
          arr[n++] = q[k][l];
      MIN = min(MIN,median(arr,0,(h*w)-1,((h*w)+1)/2));
    }
  return MIN;
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
