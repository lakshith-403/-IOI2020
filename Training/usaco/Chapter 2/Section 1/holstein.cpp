/*
 ID: lakshit4
 LANG: C++
 TASK: holstein
*/

#include<bits/stdc++.h>

using namespace std;

int minlength = 16;
vector<int> solution;
vector<int> v;
vector<vector<int>> g;
int V,G;
int SUM = 10000000;

void solve(int pos, int length,vector<int> current, vector<int> sol){
	// cout<<"pos: " << pos << endl;
	// cout << "solution: ";
	// for(int i=0;i<sol.size();i++)
	// 	cout<<sol.at(i) << " ";
	if(pos==G)
		return;
	solve(pos+1,length,current,sol);
	for(int i=0;i<V;i++)
		current.at(i) += g.at(pos).at(i);
	//cout << endl << "current: ";
	// for(int i=0;i<current.size();i++)
	// 	cout<<current.at(i) << " ";
	// cout << endl;
	length++;
	sol.push_back(pos);
	pos++;
	int l;
	for(l=0;l<V;l++)
		if(current.at(l)<v.at(l))
			break;
	if(l==V){
		//cout << "match" << endl;
		int sum = 0;
		for(int i=0;i<V;i++)
			sum+=current.at(i);
		if(length < minlength || (length==minlength && sum<SUM)){
			//cout << "blah "<< length<<  endl;
			SUM = sum;
			minlength = length;
			solution = sol;
			return;
		}
		
	}
	solve(pos,length,current,sol);
}

int main(){
	ifstream in("holstein.in");
	ofstream out("holstein.out");
	in >> V;
	for(int i=0;i<V;i++){
		int temp;
		in >> temp;
		v.push_back(temp);
	}
	in >> G;
	for(int i=0;i<G;i++){
		vector<int> t;
		for(int j=0;j<V;j++){
			int temp;
			in >> temp;
			t.push_back(temp);
		}
		g.push_back(t);
	}
	vector<int> current(V,0);
	vector<int> sol;
	solve(0,0,current,sol);
	out << minlength << " ";
	for(int i=0;i<solution.size();i++)
		if(i==solution.size()-1)
			out<<solution.at(i)+1;
		else
			out<<solution.at(i)+1 << " ";
	out << endl;
}