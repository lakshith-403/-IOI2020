/*
 ID: lakshit4
 LANG: C++
 TASK: castle
*/

#include <bits/stdc++.h>

using namespace std;

void floodfill(int index ,vector<vector<int>> graph , vector<int>* ffill , vector<int>* rooms , int count){
	ffill->at(index) = count;
	vector<int> neigh = graph.at(index);
	//cout << "index: " << index << endl;
	for(int i=0;i<neigh.size();i++){
	//	cout << "neigh: " << ffill->at(neigh.at(i)) << endl;
		if(ffill->at(neigh.at(i))==-1){
			
			rooms->at(count)++;
			ffill->at(neigh.at(i))=count;
			//cout << index << "->" << neigh.at(i) << endl;
			floodfill(neigh.at(i),graph,ffill,rooms,count);
		}
		//cout << "neigh done: " << index << endl;
	}

}

int getMax(vector<int> *vec){
	int max = -1;
	for(int i=0;i<vec->size();i++)
		if(vec->at(i)>max)
			max=vec->at(i);
	return max;
}

int main(){
	ifstream in("castle.in");
	ofstream out("castle.out");
	int m,n;
	in >> n >> m;

	vector<vector<int>> graph;
	vector<vector<int>> inverseGraph;

	for(int i=0;i<m;i++){
		for(int j=1;j<=n;j++){
			int t;
			in >> t;
			vector<bool> walls(5,true); 
			while(t>0){
				if(t>=8){
					walls[4] = false;
					t-=8;
				}else if(t>=4){
					walls[3] = false;
					t-=4;
				}else if(t>=2){
					walls[2] = false;
					t-=2;
				}else{
					walls[1] = false;
					t-=1;
				}
			}
			std::vector<int> v;
			std::vector<int> inverseV;
			if(walls[1])
				v.push_back((i*n)+j-1-1);
			else if(!walls[1] && j != 1)
				inverseV.push_back((i*n)+j-1-1);
			if(walls[2])
				v.push_back(((i-1)*n)+j-1);
			else if(!walls[1] && i != 0)
				inverseV.push_back(((i-1)*n)+j-1);
			if(walls[3])
				v.push_back((i*n)+j+1-1);
			else if(!walls[3] && j != n)
				inverseV.push_back((i*n)+j+1-1);
			if(walls[4])
				v.push_back(((i+1)*n)+j-1);
			else if(!walls[4] && i!=m-1)
				inverseV.push_back(((i+1)*n)+j-1);
			//cout << (i*m)+j-1<<"->"<<endl;
			//for(int i=0;i<v.size();i++)
			//	cout << v.at(i) << ",";
			//cout << endl;
			graph.push_back(v);
			inverseGraph.push_back(inverseV);
		}
	}
	vector<int> ffill(m*n , -1);
	vector<int> rooms;
	int count = 0;

	for(int i=0;i<m*n;i++){
		if(ffill.at(i)==-1){
			rooms.push_back(1);
			floodfill(i,graph,&ffill,&rooms,count);
			count++;
		}
	}

	int numRooms,largest,newLargest,wall;
	numRooms = count;
	largest = getMax(&rooms);

	out << numRooms << "\n" << largest << "\n";

	int max = -1;
	int maxPos = 0;
	int maxN = 0;
	int maxI , maxJ;

	for(int j=1;j<=n;j++){
		for(int i=m-1;i>=0;i--){
			int pos = (i*n)+j-1;
			cout << "ij: " << i+1 << j << endl;
			//cout << "pos:                                                " << pos << endl;
			for(int k=0;k<inverseGraph.at(pos).size();k++){
				fill(ffill.begin(), ffill.end(),-1);
				//for(int l=0;l<ffill.size();l++)
				//	cout << ffill.at(l) << " ";
				//cout << endl;
				rooms.clear();
				//cout << rooms.size() << "<>" << endl;
				count = 0;
				graph.at(pos).push_back(inverseGraph.at(pos).at(k));
				for(int l=0;l<m*n;l++){
					//cout << l << " >>>>>>" << ffill.at(l) << endl;
					if(ffill.at(l)==-1){
						//cout << "+" << l << endl;
						rooms.push_back(1);
						floodfill(l,graph,&ffill,&rooms,count);
						count++;
					}
					//cout << "booyah" << endl;
				}
				
				
				largest = getMax(&rooms);
				cout << "pos: " << pos << "->" << largest << endl;
				if(max<largest){
					cout << "pos: " << pos << "-"<< inverseGraph.at(pos).at(k) <<" ------------>" << largest << endl;
					max = largest;
					maxPos = pos;
					maxN = inverseGraph.at(pos).at(k);
					maxI = i+1;
					maxJ = j;
				}
				
				graph.at(pos).pop_back();
				//cout << "gugooo" << endl;
			}
			//cout << "pos end" << endl;
		}
	}
	cout << maxPos << " " << maxN ;
	out << max << "\n" << maxI << " " << maxJ <<" "<< ((maxN - maxPos > (n-1)) ? "N" : "E") << endl;
	return 0;
}