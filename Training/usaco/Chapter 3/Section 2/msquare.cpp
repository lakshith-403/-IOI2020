/*
ID: lakshit4
PROG: msquare
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

ifstream in("msquare.in");
ofstream out("msquare.out");

int* goal;

map<string,bool> mem;

int* transA(int* arr){
  int* newArr = new int[8];
  for(int i=0;i<4;i++)
    newArr[4+i] = arr[i];
  for(int i=0;i<4;i++)
    newArr[i] = arr[4+i];
  return newArr;
}

int* transB(int* arr){
  int* newArr = new int[8];
  for(int i=0;i<3;i++)
    newArr[i+1] = arr[i];
  for(int i=4;i<7;i++)
    newArr[i+1] = arr[i];
  newArr[0] = arr[3];
  newArr[4] = arr[7];
  return newArr;
}

int* transC(int* arr){
  int* newArr = new int[8];
  for(int i=0;i<8;i++)
    newArr[i] = arr[i];
  newArr[1] = arr[5];
  newArr[2] = arr[1];
  newArr[5] = arr[6];
  newArr[6] = arr[2];
  return newArr;
}

int* trans(int num , int*arr){
  if(num==1)return transA(arr);
  if(num==2)return transB(arr);
  if(num==3)return transC(arr);
  return arr;
}

bool checkArr(int* a , int* b){
  for(int i=0;i<8;i++)
    if(a[i]!=b[i])return false;
  return true;
}

void printArr(int* arr){
  for(int i=0;i<4;i++)
    cout << arr[i];
  cout << endl;
  for(int i=4;i<8;i++)
    cout << arr[i];
  cout << endl;
}

bool encode(int* arr){
    string s = "";
    for(int i=0;i<8;i++)
      s += arr[i]-'0';
    if(mem.count(s))
      return true;
    mem.insert(pair<string,bool>(s,true));
    return false;
}

void BFS(int* arr){
    list<pair<int*,string>> q;
    q.push_back({arr,""});
    pair<int* , string> p;
    while(!q.empty()){
      p = q.front();
      int* newArr = p.first;
      if(checkArr(newArr,goal)) break;
      q.pop_front();
      int* arr1 = trans(1,newArr);
      int* arr2 = trans(2,newArr);
      int* arr3 = trans(3,newArr);
      if(!encode(arr1))q.push_back({arr1,p.second + "A"});
      if(!encode(arr2))q.push_back({arr2,p.second + "B"});
      if(!encode(arr3))q.push_back({arr3,p.second + "C"});
    }
    out << p.second.length() << "\n" << p.second << "\n";
}

int main(){
  int arr[8];
  for(int i=0;i<4;i++)  in >> arr[i];
  for(int i=7;i>=4;i--) in >> arr[i];
  goal = arr;
  int a[] = {1,2,3,4,8,7,6,5};
  BFS(a);
}
