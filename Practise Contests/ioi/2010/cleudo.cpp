#include <bits/stdc++.h>
#include "grader.h"
#include "cluedo.h"

using namespace std;

void Solve(){
  int t=6,l=10,w=6;
  while(true){
    int a = Theory(t,l,w);
    if(a==1)t--;
    else if(a==2)l--;
    else if(a==3)w--;
    else return;
  }
}
