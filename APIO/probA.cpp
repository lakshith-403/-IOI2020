#include <bits/stdc++.h>
// #include "paint.h"

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#pragma region 

using namespace std;

#define pb push_back
#define f first
#define s second


const int MAX = 1e5+1;

bool v[MAX];

int minimumInstructions(int n, int m, int k, std::vector<int> C,std::vector<int> A, std::vector<std::vector<int>> B) {
    vector<set<int>> b(m,set<int>());
    int i=0,j,l;
    for(vector<int> x:B){
        for(int a:x)
            b.at(i).insert(a);
        i++;
    }
    vector<pair<int,int>> intervals;
    for(i=0;i<n-m+1;i++){
        for(j=0;j<m;j++){
            int x=j,y=i;
            for(l=0;l<m;l++)
                if(b.at((x+l)%m).count(C[y+l])==0)break;
            if(l==m)break;
        }
        if(j==m)continue;
        intervals.pb({i,i+m-1});
    }
    if(intervals.size()==0)return -1;
    l = -1;
    int Count = 0;
    for(i=0;i<intervals.size();i++){
        int p = -1,ma=-1;
        for(j=i;j<intervals.size();j++){
            if(intervals[j].f>l+1)break;
            if(intervals[j].s>ma) p = j,ma=intervals[j].s;
        }
        if(p==-1)return -1;
        l = ma,Count++;
        if(l==n-1)break;
    }
    if(l==n-1)  return Count;
    else  return -1;
}
/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
