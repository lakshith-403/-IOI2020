#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream in("prob.in");
	int t;
	in >> t;

	int i;
	for(i=2;i<t;i++){
		if(t%i==0)
			break;
	}
	if(i==t)
		cout << "PRIME" << endl;
	else
		cout << "NOT PRIME" << endl;
}