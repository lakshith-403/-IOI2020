/*

ID: lakshit4

LANG: C++

TASK: crypt1

 */

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include<tuple>

vector<vector<int>> permutations;

void permute(vector<int> arr , vector<int> visited , vector<int>permutation){
	if(permutation.size()==5){
		permutations.push_back(permutation);
		//for(int i=0;i<permutation.size();i++)
		//	cout<<permutation.at(i) << " ";
		//cout << endl;
		return;
	}
	for(int i=0;i<arr.size();i++){
			vector<int> tempV = visited;
			tempV.at(i)=1;
			vector<int> tempP = permutation;
			tempP.push_back(arr.at(i));
			permute(arr,tempV,tempP);
		
	}
}

//to_string(int)
//stoi(string)
bool check(int num,vector<int>arr){
	int count = 0;
	string vec = "";
	for(int i=0;i<arr.size();i++)
		vec += to_string(arr.at(i));
	string str = to_string(num);
	for(int i=0;i<str.size();i++)
		if(vec.find(str.substr(i,1))!=-1)
			count++;
	//cout << count << " " << str.size() << endl;
	if(count<str.size())
		return false;
	else
		return true;
}

int checkCount(vector<int> arr){
	int count = 0;
	for(int i=0;i<permutations.size();i++){
		string s1 = "";
		string s2 = "";
		string s3 = "";
		string s4 = "";
		s1 += to_string(permutations.at(i).at(0));
		s1 += to_string(permutations.at(i).at(1));
		s1 += to_string(permutations.at(i).at(2));

		s2 += to_string(permutations.at(i).at(3));
		s3 += to_string(permutations.at(i).at(4));

		s4 += to_string(permutations.at(i).at(3));
		s4 += to_string(permutations.at(i).at(4));

		int num1 = stoi(s1);
		int num2 = stoi(s2);
		int num3 = stoi(s3);
		int num4 = stoi(s4);
		if(check(num1*num2,arr) && check(num1*num3,arr) && check(num1*num4,arr)){
			if(to_string(num1*num2).size()!=3 || to_string(num1*num3).size()!=3 || to_string(num1*num4).size()>34)
				continue;

			cout << num1 << endl;
			cout << num4 << "" << endl;
			cout << num1*num4 << endl;
			cout << "_________" << endl;
			
			count++;
		}
	}
	return count;
}



int main(){
	ifstream input("crypt1.in");
	int n;
	input >> n;
	std::vector<int> arr;
	std::vector<int> v;
	for(int i=0;i<n;i++){
		int temp;
		input >> temp;
		arr.push_back(temp);
		v.push_back(0);
	}
	std::vector<int> perm;
	permute(arr,v,perm);
	cout<< permutations.size(); 
	int count = checkCount(arr);
	ofstream output("crypt1.out");
	output << count << endl;
}