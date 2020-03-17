/*
ID: lakshit4

LANG: C++

TASK: combo

 */
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include <tuple>
#include <set>

using namespace std;

int getPos(int n, int pos){
	if(n==1)
		return 1;
	if(pos<=0)
		return n-(pos*-1);
	else if(pos>n)
		return pos-n;
	else
		return pos;
}

int main(){
	ifstream input("combo.in");
	int n;
	vector<int> farmer;
	vector<int> master;
	int temp;
	input >> n;
	cout << n << endl;
	input >> temp;
	farmer.push_back(temp);
	input >> temp;
	farmer.push_back(temp);
	input >> temp;
	farmer.push_back(temp);
	input >> temp;

	master.push_back(temp);
	input >> temp;
	master.push_back(temp);
	input >> temp;
	master.push_back(temp);

	vector<set<int>> sampleSpace;

	for(int j=0;j<3;j++){
		set<int> tempSet;
		for(int i=-2;i<=2;i++)
			tempSet.insert(getPos(n,farmer.at(j)+i));
		sampleSpace.push_back(tempSet);
	}

	int totalFarmer = 1;
	for(int i=0;i<sampleSpace.size();i++)
		totalFarmer *= sampleSpace.at(i).size();
	
	vector<set<int>> sampleSpaceM;

	for(int j=0;j<3;j++){
		set<int> tempSetM;
		for(int i=-2;i<=2;i++){
			tempSetM.insert(getPos(n,master.at(j)+i));
			cout << "getPos " << master.at(j)+i << " " << getPos(n,master.at(j)+i) << endl;
		}
		sampleSpaceM.push_back(tempSetM);
	}

	int totalMaster = 1;
	for(int i=0;i<sampleSpaceM.size();i++){
		totalMaster *= sampleSpaceM.at(i).size();
	}

	int common = 1;
	
	for(int i=0;i<3;i++){
		set <int> :: iterator itr;
		int count = 0;
	 	for (itr = sampleSpace.at(i).begin(); itr != sampleSpace.at(i).end(); ++itr) 
	    { 
	        cout << '\t' << *itr; 
	        if(sampleSpaceM.at(i).count(*itr))
	        	count++;
	    }
	    common *= count;
	}

	int total = totalFarmer + totalMaster - common;
	cout << "+++++" << total << endl;
	ofstream output("combo.out");
	output << total << endl;
}