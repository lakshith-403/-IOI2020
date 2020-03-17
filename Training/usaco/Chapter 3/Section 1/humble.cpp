/*
ID: lakshit4
PROG: humble
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int K,N;
int prime[101];
int humble[100001];
int pindex[101];
int main(){
    ifstream in("humble.in");
    ofstream out("humble.out");
    in >> K >> N;
    for(int i=0;i<K;i++)
      in >> prime[i];
    int index=1;
    int prev = -1;
    humble[0] = 1;
    while(index<=N){
      int MIN = INT_MAX;
      for(int i=0;i<K;i++){
        while((double)prime[i]*humble[pindex[i]]<=humble[index-1])
          pindex[i]++;
        if((double)prime[i]*humble[pindex[i]]<=MIN)
        {
          MIN = (double)prime[i]*humble[pindex[i]];
          prev = i;
        }
      }
      humble[index++]= MIN;
      pindex[prev]++;
    }
    out << humble[N] << endl;
}
