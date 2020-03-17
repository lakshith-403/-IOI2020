#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <iterator>

using namespace std;

bool check(string s, string h){
	map<char,int> MAP;
	for(int i=0;i<s.size();i++){
		MAP.insert(pair<char, int>(s[i], MAP.count(s[i])==0?1:MAP.at(s[i])+1));
	}
	map<char,int> MAP2;
	for(int i=0;i<s.size();i++){
		MAP2.insert(pair<char, int>(h[i], MAP2.count(h[i])==0?1:MAP2.at(h[i])+1));
	}
	map<char, int>::iterator itr;  
    for (itr = MAP.begin(); itr != MAP.end(); ++itr) { 
    	cout << itr->first << " " << itr ->second << endl;
        if(MAP2.count(itr->first)==0)
        	return false;
        if(MAP2.at(itr->first)!=itr->second)
        	return false;
    }
	return true;
}

int main(){
	ifstream input("prob.in");
	int n;
	input >> n;
	for(int i=0;i<n;i++){
		string s,h;
		input >> s >> h;
		cout << "string::::::"<<s;
		if(s.length()>h.length()){
			cout << "NO" << endl;
			continue;
		}
		bool flag = true;
		for(int j=0;j<h.size()-s.size()+1;j++){
			cout << "check _______________ " << s << " " << h.substr(j,s.size()) << endl;
			if(check(s,h.substr(j,s.size()))){
				cout << "###################################333" << endl;
				cout << "YES" << endl;
				flag = false;
				continue;
			}
		}
		if(flag)
			cout << "NO" << endl;
	}
}