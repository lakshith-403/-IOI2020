/*
ID: lakshit4
PROG: cowtour
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int,int>> points;
int matrix[151][151];
int pastures[151];
int visited[151];
float minDis[151][151];
float dis[151];

void floodfill(int col,int node){
	if(pastures[node]!=0)
		return;

	pastures[node] = col;
	for(int i=0;i<N;i++){
		if(matrix[node][i]==1)
			floodfill(col,i);
	}
}

float getEucledian(int i , int j){
	return (sqrt(pow(points.at(i).first - points.at(j).first , 2)+
							pow(points.at(i).second - points.at(j).second,2)));
}

float dijkstra(int source){
	for(int i=0;i<N;i++){
			visited[i] = 0;
			dis[i] = FLT_MAX;
	}
	dis[source] = 0;
	int nodesVisited = 0;
	// cout << nodesVisited << "," << N;
	float maxDis = FLT_MIN;
	while(nodesVisited<N){
		int I = -1;
		float min = FLT_MAX;
		for(int i=0;i<N;i++){
			if(visited[i]==1 )continue;
			// cout << i << endl;
			float d = dis[i];
			// cout << dis << endl;
			if(d==FLT_MAX)continue;
			if(d < min){
				d = min;
				I = i;
			}
		}
		if(I==-1)break;
		// cout << I << endl;
		visited[I] = true;
		for(int i=0;i<N;i++){
			if(matrix[i][I]==0)
				continue;
			float f = getEucledian(I,i);
			if(dis[I]+f<dis[i])
				dis[i] = dis[I]+f;
			if(dis[i]>maxDis)
				maxDis = dis[i];
		} 
		nodesVisited++;
	}
	return maxDis;
}

float getDiameter(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(matrix[i][j]==1)
				minDis[i][j] = 
						(sqrt(pow(points.at(i).first - points.at(j).first , 2)+
							pow(points.at(i).second - points.at(j).second,2)));
			else
				minDis[i][j] = pow(10,6);
			minDis[j][i] = minDis[i][j];
		}
	}

	float diameter = -1;
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(i==j)continue;
				// cout <<  minDis[i][j] << endl;
				if(minDis[i][k] + minDis[k][j] < minDis[i][j]){
					minDis[i][j] = minDis[i][k] + minDis[k][j];
					minDis[j][i] = minDis[i][j];
				}
				if(minDis[i][j] > diameter && minDis[i][j] < pow(10,5)){
					diameter = minDis[i][j];
					// cout <<minDis[i][j] << " <> " << i << "," << j << endl;
				}
			}
		}	
	}
	// cout << diameter << endl;
	return diameter;
}

int main(){
	ifstream in("cowtour.in");
	ofstream out("cowtour.out");
	in >> N;
	for(int i=0;i<N;i++){
		int x,y;
		in >> x >> y;
		points.push_back({x,y});
	}
	for(int i=0;i<N;i++){
		// string line;
		// getline(in,line);
		for(int j=0;j<N;j++){
			char c;
			in >> c;
			matrix[i][j] = c - '0';// = stoi(line.substr(j,1));
		}
	}
	int col = 1;

	for(int i=0;i<N;i++){
		floodfill(col,i);
		col++;
	}

	// for(int i=0;i<N;i++)
	// 	cout << pastures[i] << endl;

	//////////////////////
	
	// cout << "++++++++++++++++++++++" << endl;
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<N;j++)
	// 		cout << minDis[i][j] << " ";
	// 	cout << endl;
	// }

	// cout << dijkstra(2);
	// return 0;

	float minDiameter = (float)pow(10,6);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(pastures[i]==pastures[j] || i==j)
				continue;
		// 	matrix[i][j] = 1;
		// 	matrix[j][i] = 1;
		// 	float diameter = getDiameter();
		// 	if(diameter < minDiameter){
		// 		minDiameter = diameter;
		// 		// cout << minDiameter << "<>" << i << "," << j << endl;
		// 	}
		// 	matrix[i][j] = 0;
		// 	matrix[j][i] = 0;
		// }
			float dis1 = dijkstra(i);
			float dis2 = dijkstra(j);
			float diameter = dis1 + dis2 + getEucledian(i,j);
			// cout << "dijkstra: " << dis1 << "," << dis2<< " | " << getEucledian(i,j) << endl;
			// cout << diameter << "<>" << i << "," << j << endl;
 			if(diameter < minDiameter){
				minDiameter = diameter;
				// cout << minDiameter << "<>" << i << "," << j << endl;
			}
		}
	}

	out << fixed << setprecision(6) << minDiameter << endl;
}