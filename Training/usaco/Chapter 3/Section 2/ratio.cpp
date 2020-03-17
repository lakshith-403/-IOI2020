/*
ID: lakshit4
PROG: ratios
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

struct mixture{
  int a;
  int b;
  int c;
};

int main(){
  ifstream in("ratios.in");
  ofstream out("ratios.out");
  mixture m1,m2,m3,g;
  in >> g.a >> g.b >> g.c;
  in >> m1.a >> m1.b >> m1.c;
  in >> m2.a >> m2.b >> m2.c;
  in >> m3.a >> m3.b >> m3.c;
  int min = INT_MAX;
  mixture ans;
  int coeff = 0;
  for(int i=0;i<=100;i++)
    for(int j=0;j<=100;j++)
      for(int k=0;k<=100;k++){
        if(i+j+k >= min) continue;
        int i1 = (m1.a*i + m2.a*j + m3.a*k);
        int i2 = (m1.b*i + m2.b*j + m3.b*k);
        int i3 = (m1.c*i + m2.c*j + m3.c*k);
        if(g.a!=0 && i1==0)continue;
        if(g.b!=0 && i2==0)continue;
        if(g.c!=0 && i3==0)continue;
        if(g.a==0 && i1!=0)continue;
        if(g.b==0 && i2!=0)continue;
        if(g.c==0 && i3!=0)continue;
        std::vector<double> v;
        // cout << g.c << " " << i3 << endl;
        if((g.a!=0))v.push_back((double)i1/(double)g.a);
        if((g.b!=0))v.push_back((double)i2/(double)g.b);
        if((g.c!=0))v.push_back((double)i3/(double)g.c);
        bool flag = false;
        if(v.size()!=0){
          double mem = v.at(0);
          if(v.at(0)==0)continue;
          for(double x : v){
            // cout << x << endl;
            if(mem!=x){flag = true;break;}
          }
        }
        if(flag)
            continue;
        // min = i+j+k;
        // ans = {i,j,k};
        // cout << "shit" << endl;
        // coeff = v.size()==0 ? 0 : v.at(0);
        // cout << i1/coeff <<" " << i2/coeff << " " << i3/coeff << endl;
        // cout << i <<" " << j << " " << k << endl;

        coeff = v.size()==0 ? 0 : v.at(0);
        // cout << ">" << i <<" " << j << " " << k << endl;
        // cout << i1 <<" " << i2 << " " << i3 << endl;
        if(coeff==0)continue;
        // cout << i1/coeff <<" " << i2/coeff << " " << i3/coeff << endl;
        if(i1/coeff == g.a && i2/coeff==g.b && i3/coeff==g.c){
          min = i+j+k;
          ans = {i,j,k};
        }

      }
  if(coeff == 0){out << "NONE" << endl; return 0;}\
  out <<ans.a << " " << ans.b << " " << ans.c << " " << coeff << endl;

}
