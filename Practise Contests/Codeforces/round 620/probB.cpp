#include <bits/stdc++.h>
// #define cin in;
using namespace std;

int checked[101];
int List[101];

bool check(string a , string b){
	// cout << a << " " << b;
	for(int i=0;i<a.length();i++){
		if(a[i] != b[a.length()-1-i]){
					// cout << "false" << endl;
					return false;}
	}
	// cout << "true" << endl;
	return true;
}

bool check(string a){
		for(int i=0;i<a.length()/2;i++)
			if(a[i] != a[a.length()-1-i])
				return false;
		return true;
}

int main(){
	// ifstream in("prob.in");
	int n,m;
	cin >> n >>  m;
	vector<string> vec;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		vec.push_back(s);
	}

	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec.size();j++){
			// cout << i << " " << j << endl;
			if(i==j || checked[i]==1 || checked[j]==1)
				continue;
			if(check(vec.at(i),vec.at(j))){
				checked[i] = 1;
				checked[j] = 1;
				List[i] = j+1;
			}
		}
	}

	for(int i=0;i<vec.size();i++)
		if(checked[i]!=1)
		if(check(vec.at(i)))
			List[i] = i+1;

	vector<string> ansLeft;
	vector<string> ansright;
	string middle = "";
	int Size = 0;
	for(int i=0;i<100;i++){
		if(List[i]==0)continue;
		if(List[i]==i+1){ middle = vec.at(i); continue;}
		ansLeft.push_back(vec.at(i));
		Size += vec.at(i).size();
	}
	for(int i=99;i>=0;i--){
		if(List[i]==0 || List[i]==i+1)continue;
		ansright.push_back(vec.at(List[i]-1));
		Size += vec.at(List[i]-1).size();
	}
	Size += middle.size();
	cout << Size << endl;
	for(int i=0;i<ansLeft.size();i++)
		cout << ansLeft.at(i);
	cout << middle;
	for(int i=0;i<ansright.size();i++)
		cout << ansright.at(i);
	cout << endl;
}