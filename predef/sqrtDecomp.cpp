#include <bits/stdc++.h>

using namespace std;

int sqrtDeco(int* a,int n){
    //preprocessing
    int len = sqrt(n + .0) + 1;
    vector<int> b(len);
    for(int i=0;i<n;i++)
        b[i/len].pb(a[i]);
    //queries
    int l=0,r=0;
    int sum = 0;
    int c_l = l/len,    c_r = r/len;
    if(c_l==c_r)
        for(int i=l;i<=r;i++)
            sum += a[i];
    else
    {
        for(int i=l,end=(c_l+1)*len-1;i<=end;i++)
            sum += a[i];
        for(int i=c_l+1;i<=c_r-1;i++)
            sum += b[i];
        for(int i=c_r*len; i<=r; i++)
            sum += a[i];
    }
    return sum;
}

int main(){

}