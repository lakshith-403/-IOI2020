/*
 ID: lakshit4
 LANG: C++
 TASK: numtri
*/

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main(){
	ifstream in("numtri.in");
	int r;
	in >> r;
	vector<vector<int>> tree;
	for(int i=0;i<r;i++){
		std::vector<int> v;
		for(int j=0;j<=i;j++){
			int t;
			in >> t;
			v.push_back(t);
		}
		tree.push_back(v);
	}
	for(int i=r-2;i>=0;i--){
		for(int j=0;j<=i;j++){
			tree.at(i).at(j) += max(tree.at(i+1).at(j),tree.at(i+1).at(j+1));
		}
	}
	ofstream out("numtri.out");
	out << tree.at(0).at(0) << endl;
}