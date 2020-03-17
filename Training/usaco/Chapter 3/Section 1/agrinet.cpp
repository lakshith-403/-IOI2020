/*
ID: lakshit4
PROG: agrinet
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int N;
int graph[100][100];
bool intree[100];
int dis[100];

int main(){
    ifstream in("agrinet.in");
    ofstream out("agrinet.out");
    in >> N;
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        in >> graph[i][j];

    for(int i=0;i<N;i++)
      dis[i]= INT_MAX;

    dis[0] = 0;
    int treeSize = 1;
    int graphSize = N;
    int treecost = 0;
    intree[0] = true;

    for(int i=0;i<N;i++)dis[i] =graph[0][i];

    while(treeSize < graphSize){
      int index = 1;
      int MIN = INT_MAX;
      for(int i=0;i<N;i++)
        if(dis[i]<MIN && !intree[i]){
          index = i;
          MIN = dis[i];
        }

      treeSize++;
      treecost += dis[index];
      intree[index] = true;
      for(int i=0;i<N;i++)
        dis[i] = min(dis[i] , graph[index][i]);
    }

    out << treecost << endl;
}
