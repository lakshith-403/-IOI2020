#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream in("prob.in");
	int t;
	in >> t;
	for(int j=0;j<t;j++){
		int n,m;
		in >>n >>m;
		if(m>=n/2){
			cout << (n*(n+1)/2)- (n-m) << endl;
			continue;
		}else{
			n = m*2;
			cout << (n*(n+1)/2)- (n-m) << endl;
			continue;
		}
	}
}