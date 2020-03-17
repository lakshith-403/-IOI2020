#include <bits.stdc++.h>

using namespace std;
int a,b,c;
int main(){
  int t;
  cin >> t;
  while(t--){
      int count = 0;
      cin >>a>>b>>c;
      if(a>0){
        count ++;
        a--;
      }
      if(b>0){
        count ++;
        b--;
      }
      if(c>0){
        count ++;
        c--;
      }
      if(max(a,max(b,c))==1 && min(a,min(b,c))==1)
        count++;
      else{
        if(a>2){
          if(b==1){
            if(c==0)
              count++;
          }else if(c==1){
            if(b==0)
              count++;
          }
        }
      }
  }
}
