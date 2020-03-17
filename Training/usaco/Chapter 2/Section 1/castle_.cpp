/*
 ID: lakshit4
 LANG: C++
 TASK: castle
*/

#include <bits/stdc++.h>

using namespace std;


int getmax(vector<int> vec){
	int max = -1;
	int pos = 0;
	for(int i=0;i<vec.size();i++){
		//cout << i;
		if(vec.at(i)>max){
			pos = i;
			max = vec.at(i);
		}
	}
	return max;
}

void floodfill(int x,int y, vector<vector<vector<bool>>> &graph, vector<vector<int>> &paint, int count, vector<int> &rooms){
	if(paint.at(y).at(x) != -1)
		return;
	paint.at(y).at(x) = count;
	rooms.at(count)++;
	// cout << "pos: " << x << " " << y <<  endl;
	for(int i=1;i<=4;i++){
		if(graph.at(y).at(x).at(i))
			continue;
		// cout << i << "+" << graph.at(y).at(x).at(i) << endl;
		pair<int,int> xy;
		if(i==1)
			xy = {x-1,y};
		else if(i==2)
			xy = {x,y-1};
		else if(i==3)
			xy = {x+1,y};
		else
			xy = {x,y+1};
		// cout << xy.first<<" " << xy.second << endl;
		floodfill(xy.first,xy.second,graph,paint,count,rooms);
	}
}


int main(){
	ifstream in("castle.in");
	ofstream out("castle.out");
	int m,n;
	in >> m >> n;

	vector<vector<vector<bool>>> graph;

	for(int i=0;i<n;i++){
		vector<vector<bool>> rows;
		
		for(int j=0;j<m;j++){
			int t;
			in >> t;
			vector<bool> walls(5,false);
			// cout << j << " " << i << " -> " << t<< endl; 
			while(t>0){
				if(t>=8){
					walls[4] = true;
					t-=8;
				}else if(t>=4){
					walls[3] = true;
					t-=4;
				}else if(t>=2){
					walls[2] = true;
					t-=2;
				}else{
					walls[1] = true;
					t-=1;
				}
			}
			// for(int k=1;k<walls.size();k++)
			// 	cout << walls[k] << ",";
			// cout << endl;
			rows.push_back(walls);
		}
		graph.push_back(rows);
	}

	vector<int> rooms;
	vector<vector<int>> paint(n,vector<int> (m,-1));
	int count = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(paint.at(i).at(j)!=-1)
				continue;
			rooms.push_back(0);
			floodfill(j,i,graph,paint,count,rooms);
			//cout << rooms.at(count) << endl;
			count++;
		}
	}
	int max = getmax(rooms);
	out << count << "\n" << max << "\n";
	int I,J;
	string D;
	for(int j=0;j<m;j++){
		for(int i=n-1;i>=0;i--){//
			//cout << i+1 <<","<<j+1 << endl;
			rooms.clear();
			fill(paint.begin(),paint.end(),vector<int> (m,-1));
			count = 0;
			//cout <<graph.at(i).at(j).at(2) << endl;
			if(graph.at(i).at(j).at(2) && i!=0){
				graph.at(i).at(j).at(2) = false;
				graph.at(i-1).at(j).at(4) = false;
				for(int k=0;k<n;k++){
					for(int l=0;l<m;l++){
						if(paint.at(k).at(l)!=-1)
							continue;
							rooms.push_back(0);
							floodfill(l,k,graph,paint,count,rooms);
							//cout << rooms.at(count) << endl;
							count++;
					}
				}
				int localMax = getmax(rooms);
				//cout << "N: " << localMax << endl;
				if(localMax>max){
					max = localMax;
					I = i;
					J = j;
					D = "N";
				}
				graph.at(i).at(j).at(2) = true;
				graph.at(i-1).at(j).at(4) = true;
			}


			rooms.clear();
			fill(paint.begin(),paint.end(),vector<int> (m,-1));
			count = 0;
			if(graph.at(i).at(j).at(3) && j!= m-1){
				graph.at(i).at(j).at(3) = false;
				graph.at(i).at(j+1).at(1) = false;
				for(int k=0;k<n;k++){
					for(int l=0;l<m;l++){
						if(paint.at(k).at(l)!=-1)
							continue;
							rooms.push_back(0);
							floodfill(l,k,graph,paint,count,rooms);
							count++;
					}
				}
				int localMax = getmax(rooms);
				//cout << "E: " << localMax <<  endl;
				if(localMax>max){
					max = localMax;
					I = i;
					J = j;
					D = "E";
				}
				graph.at(i).at(j).at(3) = true;
				graph.at(i).at(j+1).at(1) = true;
			}
		}
	}
	out << max << endl;
	out << I+1 << " " << J+1 << " " << D << endl;
}