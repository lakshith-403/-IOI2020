#include<bits/stdc++.h>

using namespace std;

int main(){
  ofstream out("input.in");
  out << 2 * (int)pow(10,6) << endl;
  for(int i=1;i<=(int)pow(10,6);i++)
    out << "RUN " << i << endl;
  for(int i=(int)pow(10,6);i>=1;i--)
    out << "END " << i << endl;
}
