#include <bits/stdc++.h>

using namespace std;

int W,H;
int maze[210][210];
vector<vector<int>> graph(210*210,vector<int>());
vector<bool> v(210*210,false);
string str[201];

int main(){
	ifstream in("maze1.in");
	in >> W >> H;

	for(int i=0;i<2*H+1;i++){
		getline(in,str[i]);
		for(int j=0;j<W*2+1;j++){
			char temp = str[i][j];
			if(temp==' ')maze[i][j] = 0;
			else maze[i][j] = 1;
			cout << maze[i][j] << endl;
		}
	}

	int ii=0,jj=0;
	for(int i=0;i<2*H+1;i+=2){
		for(int j=1;j<W*2;j+=2){
			cout << maze[i][j] << " +++++" << endl;
			if(maze[i][j]==0)
				graph.at(ii*H+jj).push_back(ii+1);
			jj++;
		}
		i++;
	}
	ii=1; jj=0;
	for(int i=1;i<2*H;i+=2){
		for(int j=0;j<W*2+1;j+=2){
			if(maze[i][j]==0)
				graph.at(ii*H+jj).push_back(jj+1);
			jj++;
		}
		ii++;
	}

	for(int i=0;i<H*W;i++){
		cout << i << " ->  ";
		for(int x : graph.at(i))
			cout << x << ",";
		cout << endl;
	}

}