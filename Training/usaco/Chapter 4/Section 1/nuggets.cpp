/*
ID: lakshit4
PROG: nuggets
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
int arr[11];
bool mem[65600];
int main(){
  ifstream in("nuggets.in");
  ofstream out("nuggets.out");
  int n;
  in >> n;
  int MIN = INT_MAX;
  for(int i=0;i<n;i++){
    in >> arr[i];
    mem[arr[i]] = true;
    MIN = min(arr[i],MIN);
  }
  int largest = 0;
  int Count = 0;
  int i;
  for(i=0;i<65600;i++){
    if(!mem[i]){
      Count=0;
      largest=i;
    }
    else{
      Count++;
      if(Count==MIN)break;
      for(int j=0;j<n;j++)
        mem[i+arr[j]] = true;
    }
  }
  if(i==65600)largest=0;
  out << largest << "\n";
}
