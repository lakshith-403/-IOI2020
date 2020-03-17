#include <iostream>
#include <fstream>
#include <cstring>
#include <map>

using namespace std;

bool check(string s, string h){
	int arr[200];
	int arr2[200];
	for(int i=0;i<200;i++)
		arr[i] = 0;
	for(int i=0;i<s.size();i++)
		arr[s[i]]++;
	for(int i=0;i<200;i++)
		arr2[i] = 0;
	for(int i=0;i<h.size();i++)
		arr2[h[i]]++;
	for(int i=0;i<200;i++)
		if(arr[i]!=arr2[i])
			return false;
	return true;
}

int main(){
	ifstream input("prob.in");
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string s,h;
		cin >> s >> h;
		if(s.length()>h.length()){
			cout << "NO" << endl;
			continue;
		}
		bool flag = true;
		for(int j=0;j<h.size()-s.size()+1;j++){
			//cout << "check " << s << " " << h.substr(j,s.size()) << endl;
			if(check(s,h.substr(j,s.size()))){
				cout << "YES" << endl;
				flag = false;
				continue;
			}
		}
		if(flag)
			cout << "NO" << endl;
	}
}