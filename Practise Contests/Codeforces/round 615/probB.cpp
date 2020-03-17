#include <bits/stdc++.h>

using namespace std;

bool sortXY(pair<int,int> p1 , pair<int,int> p2){
	if(p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first < p2.first;
}

int main(){
	// ifstream in("prob.in");
	int t;
	cin >> t;
	for(int j=0;j<t;j++){
		int n;
		cin >> n;
		vector<pair<int,int>> cords;
		for(int k=0;k<n;k++){
			int x1,y1;
			cin >> x1 >> y1;
			cords.push_back({x1,y1});
		}
		sort(cords.begin(),cords.end(),sortXY);
		string path = "";
		int X =0;
		int Y =0;
		int i;
		for(i=0;i<cords.size();i++){
			// cout << "[" << cords.at(i).first << "," << cords.at(i).second << "]" << endl;
			if(cords.at(i).first < X || cords.at(i).second < Y)
					break;
			for(int l=0;l<cords.at(i).first-X;l++)
				path+="R";
			for(int l=0;l<cords.at(i).second-Y;l++)
				path+="U";
			X = cords.at(i).first;
			Y = cords.at(i).second;
		}
		if(i!=cords.size())
			cout << "NO" << endl;
		else
			cout << "YES" << endl << path << endl;
	}
}