//Educational Codeforces round 80
//Problem A

#include<iostream>
#include<fstream>

using namespace std;

bool solve(int x, int d,int n){
	if(x>=d)
		return false;
	if(x + (int)d/(x+1) <= n)
		return true;
	else
		return solve(x+(int)(d-x)/2,d,n);
}

int main(){
	//ifstream in("in.in");
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n,d;
		cin >> n >> d;
		if(solve(d/2,n,d))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}