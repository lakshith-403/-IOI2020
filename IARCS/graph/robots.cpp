/*
 * ~Lakshith Nishshnake
 * 2020/05/22
 * 9.50 pm
*/

#include <bits/stdc++.h>

using namespace std;

inline void setup_io(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

struct coord{
  int x;
  int y;
};

struct guard{
  int x;
  int y;
  int len;
  char dir;
};

struct qNode{
  coord rob1;
  coord rob2;
  int depth;
  string path;
  bool robot1;
  bool robot2;
};

int r1,c1,r2,c2;
int grid1[22][22];
int grid2[22][22];
int g1,g2;
vector<guard> gList1;
vector<guard> gList2;
int stateSpace[22][22][22][22][13];
bool visited[22][22][22][22][13];
coord start1,start2;
// bool robot1 = false;
// bool robot2 = false;
string dic[] = {"N","E","S","W"};

coord moves[] = { {+1,0} , {0,+1} , {-1,0} , {0,-1} };

coord getPos(guard g,int time){
  coord r;
  int len = time % ((g.len-1)*2);
  len = len>g.len ? ((g.len-1)*2) - len : len ;
  if(g.dir=='N'){
    r.x = g.x;
    r.y = g.y + len;
  }else if(g.dir=='S'){
    r.x = g.x;
    r.y = g.y - len;
  }else if(g.dir=='E'){
    r.x = g.x - len;
    r.y = g.y;
  }else{
    r.x = g.x + len;
    r.y = g.y;
  }
  return r;
}
/*
 * 5 -> out of the maze
 * 1 -> wall
 * 2 -> guard
 * 0 -> Free space
*/

void BFS(){
  queue<qNode> Q;
  qNode src = {start1, start2, 1, "",false,false};
  Q.push(src);
  while(!Q.empty()){
    qNode node = Q.front();
    Q.pop();
    int mask1 = (1<<4)-1;
    int mask2 = (1<<4)-1;
    coord rob1 = node.rob1;
    coord rob2 = node.rob2;
    int time = node.depth;
    string path = node.path;
    bool robot1 = node.robot1;
    bool robot2 = node.robot2;
    if(rob1.x<=0 || rob1.x>=r1+1)robot1=true;
    if(rob1.y<=0 || rob1.y>=c1+1)robot1=true;
    if(rob2.x<=0 || rob2.x>=r2+1)robot2=true;
    if(rob2.y<=0 || rob2.y>=c2+1)robot2=true;
    if(grid1[rob1.x][rob1.y]==1 || grid2[rob2.x][rob2.y]==1)continue;
//     cout << rob1.x << " " << rob1.y << "\t" << rob2.x << " " << rob2.y << "\n";
    if(robot1&&robot2){
      cout << time-1 << "\n";
      for(char C : path)
        cout << C << "\n";
      break;
    }
    time %= 12;
    for(int i=0;i<4;i++){
      bool b1,b2;
      if(!robot1)
        b1 = (stateSpace[rob1.x+moves[i].x][rob1.y+moves[i].y][rob2.x][rob2.y][time]!=1);
      else
        b1 = true;
      if(!robot2)
        b2 = (stateSpace[rob1.x][rob1.y][rob2.x+moves[i].x][rob2.y+moves[i].y][time]!=1);
      else
        b2 = true;
      if(stateSpace[rob1.x][rob1.y][rob2.x+moves[i].x][rob2.y+moves[i].y][time]==2
        ||
        stateSpace[rob1.x+moves[i].x][rob1.y+moves[i].y][rob2.x][rob2.y][time]==2
        )continue;
      coord newRob1 = {rob1.x+moves[i].x*(robot1?0:1)*(b1?1:0),rob1.y+moves[i].y*(robot1?0:1)*(b1?1:0)};
      coord newRob2 = {rob2.x+moves[i].x*(robot2?0:1)*(b2?1:0),rob2.y+moves[i].y*(robot2?0:1)*(b2?1:0)};
      if(visited[newRob1.x][newRob1.y][newRob2.x][newRob2.y][time+1])continue;
      visited[newRob1.x][newRob1.y][newRob2.x][newRob2.y][time+1] = true;
      qNode nextNode = {newRob1,newRob2,time+1,path+dic[i],robot1,robot2};
      Q.push(nextNode);
    }
    
  }
//   if(robot1 && robot2)cout << "shit is over" << "\n";
//   cout << "messed up" << "\n";
}

void setupStates(){
  for(int i=0;i<=12;i++){
    
    for(int i1=0;i1<22;i1++)
      for(int i2=0;i2<22;i2++)
        stateSpace[i1][0][i2][0][i] = 5;
      
    for(int j1=0;j1<22;j1++)
      for(int j2=0;j2<22;j2++)
        stateSpace[0][j1][0][j2][i] = 5;
    
    for(guard g : gList1){
      coord pos = getPos(g,i);
      for(int i1=0;i1<22;i1++)
        for(int j1=0;j1<22;j1++)
          stateSpace[pos.x][pos.y][i1][j1][i] = 2;
    }
    
    for(guard g : gList2){
      coord pos = getPos(g,i);
      for(int i2=0;i2<22;i2++)
        for(int j2=0;j2<22;j2++)
          stateSpace[i2][j2][pos.x][pos.y][i] = 2;
    }
    
    for(int i1=0;i1<22;i1++)
        for(int j1=0;j1<22;j1++){
          if(grid1[i1][j1]==1)
          for(int i2=0;i2<22;i2++)
            for(int j2=0;j2<22;j2++)
              stateSpace[i1][j1][i2][j2][i] = 1;
        }
        
    for(int i2=0;i2<22;i2++)
        for(int j2=0;j2<22;j2++){
          if(grid2[i2][j2]==1)
          for(int i1=0;i1<22;i1++)
            for(int j1=0;j1<22;j1++)
              stateSpace[i1][j1][i2][j2][i] = 1;
        }
  }
}

int main(){
  cin >> r1 >> c1;
  for(int i=1;i<=r1;i++)
    for(int j=1;j<=c1;j++){
      char temp;
      cin >> temp;
      if(temp=='#')grid1[i][j]=1;
      else if(temp=='.')grid1[i][j]=0;
      else{
        grid1[i][j]=0;
        start1={i,j};
      }
    }
  cin >> g1;
  for(int i=0;i<g1;i++){
    int a,b,c;
    char dir;
    cin >> a >> b >> c >> dir;
    guard tempG = {a,b,c,dir};
    gList1.push_back(tempG);
  }
  cin >> r2 >> c2;
  for(int i=1;i<=r2;i++)
    for(int j=1;j<=c2;j++){
      char temp;
      cin >> temp;
      if(temp=='#')grid2[i][j]=1;
      else if(temp=='.')grid2[i][j]=0;
      else{
        grid2[i][j]=0;
        start2={i,j};
      }
    }
      
  cin >> g2;
  for(int i=0;i<g2;i++){
    int a,b,c;
    char dir;
    cin >> a >> b >> c >> dir;
    guard tempG = {a,b,c,dir};
    gList2.push_back(tempG);
  }
  setupStates();
  BFS();
}

/*
4 4
####
#x.#
#...
####
0
4 4
####
#x.#
#..#
#..#
0
*/
