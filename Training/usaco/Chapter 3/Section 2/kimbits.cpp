/*
ID: lakshit4
PROG: kimbits
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int N,L,I;

int main(){
  ifstream in("kimbits.in");
  ofstream out("kimbits.out");
  in >> N >> L >> I;
  int count = 0;
  int i;
  for(i=0;i<(int)pow(2,N);i++){
    if(__builtin_popcount(i)<=L)
      count++;
    if(count==I)
      break;
  }

  for (int j = N-1; j >= 0; j--){
        int k = i >> j;
        if (k & 1)
            out << "1";
        else
            out << "0";
  }
  out << endl;
}
