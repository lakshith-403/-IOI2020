/*
ID: lakshit4
PROG: heritage
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
char inOrder[30];
char preOrder[30];
int N;
string s;

int search(char* arr, char x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void printPostOrder(char* in, char* pre, int n)
{
    char root = search(in, pre[0], n);
    if (root != 0)
        printPostOrder(in, pre + 1, root);
    if (root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
    s+=pre[0];
}
int main(){
  ifstream in("heritage.in");
  ofstream out("heritage.out");
  int i = 0;
  char temp[100];
  while(in >> temp[i++]);
  for(int j=0;j<i/2;j++){
    inOrder[j] = temp[j];
    cout << inOrder[j];
  }
  cout << endl;
  for(int j=i/2;j<i-1;j++){
    preOrder[j-(i/2)] = temp[j];
    cout << preOrder[j-(i/2)];
  }
  cout << endl;
  N=i/2;
  cout << N << endl;
  printPostOrder(inOrder,preOrder,N);
  for(int i=0;i<N;i++)
    out << s[i];
  out << endl;
}
