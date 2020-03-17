#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include<tuple>

using namespace std;

int main(){
	ifstream input("prob1.in");
	int m;
	input >> m;
	for(int i=0;i<m;i++){
		int n;
		input >> n;
		string s1;
		string s2;
		input >> s1;
		input >> s2;
		int difCount = 0;
		string dif1;
		bool flag = false;
		for(int j=0;j<n;j++){
			if(difCount>=2)
				break;
			string c1 = s1.substr(j,1);
			string c2 = s2.substr(j,1);
			if(c1!=c2){
				difCount++;
				if(difCount==1)
					dif1 = c1+c2;
				else if(dif1 == c1+c2)
					flag = true;
			}
			
		}
		if(flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}