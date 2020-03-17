/*
 ID: lakshit4
 LANG: C++
 TASK: prefix
*/
#include<bits/stdc++.h>

using namespace std;

vector<string> p;
string S;

bool compareStr(string s1, string s2){
	return s1.size()<s2.size();
}

bool check(char str[], int pos , string pref){
	if(pos + pref.size() >= *(&str + 1) - str)
		return false;
	// cout << "check: " << pos << " "+pref << endl;
	char c[pref.size()];
	strcpy(c,pref.c_str());
	for(int i=0;i<pref.size();i++){
		if(str[pos]!=pref[i])
			return false;
		pos++;
	}
	return true;
}

int main(){
	ifstream in("prefix.in");
	ofstream out("prefix.out");
	while(true){
		string str;
		in >> str;
		if(str==".")
			break;
		p.push_back(str);
	}
	while(true){
		string temp;
		in >> temp;
		if(temp=="")
			break;
		S+=temp;
	}

	char C[S.size()];
	strcpy(C,S.c_str());

	sort(p.begin(),p.end(),compareStr);
	// for(string x : p)
	// 	cout << x << endl;
	// cout << S << endl;
	int size = S.size();
	vector<bool> start(size,false);
	vector<bool> covered(size,false);

	for(string x : p){
		if(check(C,0,x))
		{
			for(int i=0;i<x.size();i++)
				covered.at(i)=true;
			start.at(x.size())=true;
		}
	}
	cout << "SIZE" << size << endl;
	for(int i=0;i<size;i++){
		// cout << i << " " << start.size() << endl;
		if(!start.at(i)){
			// cout << "continue " << i << endl;
		 continue;}
		for(string x : p){
			if(check(C,i,x))
			{
				 // cout << "+++++++++++++" << i << " "+x << endl;
				//cout << i << " " << x <<endl << S<< endl;
				for(int j=0;j<x.size();j++)
					covered.at(j+i)=true;
				if(i+x.size()<start.size())
					start.at(i+x.size())=true;
				// for(bool b : covered)
				// 	cout << b;
				// cout << endl;
				// for(bool b : start)
				// 	cout << b;
				// cout << endl;

			}
		}
	}
	// cout << "done";
	// return 0;
	// for(bool b : covered)
	// 	cout << b << " ";
	int count = 0;
	for(bool b : covered)
		if(b)count++;
		else break;
	out << count << endl;
}