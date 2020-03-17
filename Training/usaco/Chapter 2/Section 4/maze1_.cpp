/*
ID: lakshit4
PROG: maze1
LANG: C++
*/

//#include <iostream>
#include <fstream>
#include <queue> 
#include <string>
#include <stdlib.h> 
using namespace std;

//North walls[i][j][0]
short width = 0;
short height = 0;
bool walls[100][38][4];
short dist[100][38][2];
string str[201];
short exits[2][2];
short counter = 0;
bool visited[100][38];

class Point{
public:
  int x_;
  int y_;
  Point(int x, int y):x_(x),y_(y){}
  Point(const Point& element){
    x_ = element.x_;
    y_ = element.y_;
  }
};

void Record(int i, int j);
void BFS(short exit_num);

int main(){
    ifstream fin("maze1.in");
    string cur_line;
    getline(fin,cur_line);
    int pos = cur_line.find(' ');
    width = atoi(cur_line.substr(0,pos).c_str());
    height = atoi(cur_line.substr(pos+1).c_str());
    //cout<<width<<" "<<height<<endl;
    for(int i = 0; i < 2*height+1; i++){
        getline(fin,str[i]);
    }
    //collect walls info;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(str[2*i][2*j+1] != ' ')//North
                walls[i][j][0] = 1;
            else if(i == 0){
                Record(i,j);
            }
            if(str[2*i+1][2*j+2] != ' ')//East
                walls[i][j][1] = 1;
            else if(j == width-1){
                Record(i,j);
            }
            if(str[2*i+2][2*j+1] != ' ')//South
                walls[i][j][2] = 1;
            else if(i == height-1){
                Record(i,j);
            }
            if(str[2*i+1][2*j] != ' ')//West
                walls[i][j][3] = 1;
            else if(j == 0){
                Record(i,j);
            }
        }
    }
    //cout << exits[0][0] << " " << exits[0][1] << endl;
    //cout << exits[1][0] << " " << exits[1][1] << endl;
    BFS(0);
    //Reset visited info 
    for(short i = 0; i < height; i++){
        for(short j = 0; j < width; j++){
            //cout<<dist[i][j][0]<<" ";
            visited[i][j] = 0;
        }
        //cout<<endl;
    }
    BFS(1);
    short max_step = 0;
    for(short i = 0; i < height; i++){
        for(short j = 0; j < width; j++){
            short less_step = dist[i][j][0] <= dist[i][j][1] ? dist[i][j][0]:dist[i][j][1];
            max_step = less_step > max_step ? less_step : max_step; 
            //cout<<dist[i][j][1]<<" ";
        }
        //cout<<endl;
    }
    ofstream fout("maze1.out");
    fout<<max_step+1<<endl;
    return 0;
}

void Record(int i,int j){
    exits[counter][0] = i;
    exits[counter][1] = j;
    //cout<<"C  "<< counter<<endl;
    counter++;
}

void BFS(short exit_num){
    Point start(exits[exit_num][0],exits[exit_num][1]); 
    dist[start.x_][start.y_][exit_num] = 0;
    visited[start.x_][start.y_] = 1;
    queue<Point> points;
    points.push(start);
    while(!points.empty()){
        Point cur = points.front();//Note front() function return a temporary const object; 
        points.pop();
        if(cur.x_ > 0 && walls[cur.x_][cur.y_][0] == 0 && visited[cur.x_-1][cur.y_] == 0){//North
            dist[cur.x_-1][cur.y_][exit_num] = dist[cur.x_][cur.y_][exit_num]+1;
            visited[cur.x_-1][cur.y_] = 1;
            points.push(Point(cur.x_-1,cur.y_));
        }
        if(cur.y_+1 < width && walls[cur.x_][cur.y_][1] == 0 && visited[cur.x_][cur.y_+1] == 0){//East
            dist[cur.x_][cur.y_+1][exit_num] = dist[cur.x_][cur.y_][exit_num]+1;
            visited[cur.x_][cur.y_+1] = 1;
            points.push(Point(cur.x_,cur.y_+1));
        }
        if(cur.x_+1 < height && walls[cur.x_][cur.y_][2] == 0 && visited[cur.x_+1][cur.y_] == 0){ //South
            dist[cur.x_+1][cur.y_][exit_num] = dist[cur.x_][cur.y_][exit_num]+1;
            visited[cur.x_+1][cur.y_] = 1;
            points.push(Point(cur.x_+1,cur.y_));
        }
        if(cur.y_ > 0 && walls[cur.x_][cur.y_][3] == 0 && visited[cur.x_][cur.y_-1] == 0){ //West
            dist[cur.x_][cur.y_-1][exit_num] = dist[cur.x_][cur.y_][exit_num]+1;
            visited[cur.x_][cur.y_-1] = 1;
            points.push(Point(cur.x_,cur.y_-1));
        }
    }
}