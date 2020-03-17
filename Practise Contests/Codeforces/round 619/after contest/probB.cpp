#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream in("prob.in");
	int t;
	in >> t;
	for(int j=0;j<t;j++){
		int n;
		in >> n;
		vector<int> vec;
		for(int i=0;i<n;i++){
			int temp;
			in >> temp;
			vec.push_back(temp);
		}
		vec.push_back(-1);
		int min = INT_MAX;
		int MAX = INT_MIN;
		for(int i=0;i<vec.size()-1;i++){
			if(vec.at(i+1)==-1){
				min = vec.at(i) < min ? vec.at(i) : min;
				MAX = vec.at(i) > MAX ? vec.at(i) : MAX;
			}
		}
		if(min==INT_MAX){
			cout << 0 << " " << 0 << endl;
		}
		int k = (min+MAX)/2;
		int maxdif = INT_MIN;
		for(int i=0;i<vec.size()-1;i++){
			int i1 = vec.at(i)==-1 ? k : vec.at(i);
			int i2 = vec.at(i+1)==-1 ? k : vec.at(i+1);
			int dif = max(i1-i2 , i2-i1);
			maxdif = MAX > maxdif ? MAX : maxdif ;
		}
		cout << maxdif << " " << k << endl;
	}
}