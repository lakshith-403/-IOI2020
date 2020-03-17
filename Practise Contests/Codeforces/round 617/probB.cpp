#include <bits/stdc++.h>

using namespace std;

int main(){
	// ifstream in("prob.in");
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int total=0;
		// cout << "+++++" << endl;
		while(n>0){
			// cout << n << endl;
			if(n<10){
				total += n;
				break;
			}
			int temp = n/10;
			total += temp*10;
			n = n - (temp * 10) + temp;
		}
		cout <<total << endl;
	}
}