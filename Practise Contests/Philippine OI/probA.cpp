#include <bits/stdc++.h>

using namespace std;

int main(){
	// ifstream in("prob.in");
	vector<int> c;
	int h;
	int sum = 0;
	for(int i=0;i<4;i++){
		cin >> h;
		sum += h;
		c.push_back(h);
	}
	cin >> h;
	for(int i=0;i<4;i++)
		if(sum-c.at(i) >= h){
			cout << "WAW" << endl;
			return 0;
		}
	cout << "AWW" << endl;
	return 0;
}