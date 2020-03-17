#include <bits/stdc++.h>

using namespace std;

int main(){
	// ifstream in("prob.in");
	int t;
	cin >> t;
	for(int j=0;j<t;j++){
		int a,b,c,n;
		cin >> a >> b >> c >> n;

		if(a<max(b,c)){
			n-= max(b,c) - a;
			a=max(b,c);
		}
		if(b<max(a,c)){
			n-=max(a,c)-b;
			b=max(a,c);
		}
		if(c<max(a,b)){
			n-=max(a,b)-c;
			c=max(a,b);
		}
		// cout << a << " " << b << " " << c << " " << n << endl;
		if(n==0)
			cout << "YES" << endl;
		else if(n%3==0 && n>0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}