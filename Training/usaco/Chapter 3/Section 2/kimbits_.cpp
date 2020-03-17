/*
ID: lakshit4
PROG: kimbits
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int N,L;
double I;

double sizeset[33][33];

ifstream in("kimbits.in");
ofstream out("kimbits.out");

void setupSet(){
  int i,j;
  for(j=0;j<=32;j++)
    sizeset[0][j] = 1;

  for(i=1;i<=32;i++)
    for(j=0;j<=32;j++)
      if(j==0)sizeset[i][j]=1;
      else sizeset[i][j] = sizeset[i-1][j-1] + sizeset[i-1][j];
}

void printbits(int n, int m , double index){
  double s;
  if(n==0)
    return;
  s = sizeset[n-1][m];
  if(s <= index){out << "1"; printbits(n-1,m-1,index-s);}
  else{out << "0"; printbits(n-1,m,index);}
}

int main(){
  in >> N >> L >> I;
  setupSet();
  printbits(N,L,I-1);
  out << endl;
}
