/*
ID: lakshit4
PROG: inflate
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
int M,N;
int best[10000+1];

int main(){
  ifstream in("inflate.in");
  ofstream out("inflate.out");
  in >> M >> N;
  for(int i=0;i<N;i++){
    int s,t;
    in >> s >> t;
    for(int j=0;j+t<=M;j++)
      if(best[j+t]<best[j]+s)
        best[j+t] = best[j]+s;
  }
  out << best[M] << endl;
}
