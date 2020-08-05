/*
Sparce table with precomputed log values
preprocessing time O(n log n)
most queries (i.e sum) O(log n)
min max queries O(1)
    ~ LaKsHiTh_
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
const int k = 25; //upper bound log 2 of MAX
int st[MAX][k+1];

//replace with the operation
inline int f(int a,int b){
    return a+b;
}

int log[MAX+1];

void conputeLog(){
    log[1] = 0;
    for(int i=2;i<=MAX;i++)
        log[i] = log[i/2]+1;
}   

int rangeSum(int l,int r){
    int sum = 0;
    for(int j=k;j>=0;j--)
        if((1<<j) <= r-l+1)
            sum += st[l][j], l += (1<<j);
    return sum;
}

int minRange(int l,int r){
    int j = log[l-r+1];
    return min(st[l][j],st[r-(1<<j)+1][j]);
}

void setupSparce(int* arr, int n){
    for(int i=0;i<n;i++)
        st[i][0] = arr[i];
    for(int j=0;j<=k;j++)
        for(int i=0; i+(1<<j) < n;i++)
                st[i][j] = f(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    setupSparce(arr,10);
}