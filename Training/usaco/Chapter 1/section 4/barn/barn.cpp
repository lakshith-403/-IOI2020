/*

ID: lakshit4

LANG: C++

TASK: barn1

 */
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include<tuple>

using namespace std;

bool compare(int i1,int i2){
	return i1>i2;
}
int main(){
	ifstream input("barn1.in");
	int c;
	int s;
	int m;
	input >> m;
	input >> s;
	input >> c;
	std::vector<int> stalls;
	for(int i=0;i<c;i++){
		int temp;
		input >> temp;
		stalls.push_back(temp);
	}
	sort(stalls.begin(),stalls.end());
	std::vector<int> spaces;
	int prev=stalls.at(0);
	for(int i=0;i<stalls.size();i++)
		if(stalls.at(i)-prev>1){
			spaces.push_back(stalls.at(i)-prev-1);
			prev = stalls.at(i);
		}else
			prev = stalls.at(i);
	sort(spaces.begin(),spaces.end(),compare);
	int pieces = 1;
	int pos = 0;
	int total = s;
	while(pieces<m){
		if(pos==spaces.size())
			break;
		cout << spaces.at(pos)<< endl;
		total-=spaces.at(pos);
		pieces++;
		pos++;
	}
	total -= s-stalls.at(stalls.size()-1);
	total -= stalls.at(0)-1;
	ofstream output("barn1.out");
	output << total << endl;
	return 0;
}