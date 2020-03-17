#include <bits/stdc++.h>

using namespace std;

int main(){
	// ifstream in("prob.in");
	int t;
	cin >> t;
	for(int j=0;j<t;j++){
		string a,b,c;
		cin >> a >> b >> c ;
		int i;
		for(i=0;i<a.length();i++){
			if(!(a[i]==c[i] || b[i]==c[i]))
				break;
		}
		if(i==a.length())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}