#include <bits/stdc++.h>

using namespace std;
double x,y,a,b;
int main(){
	ifstream in("prob.in");
	int t;
	in >> t;
	for(int j=0;j<t;j++){
		in >> x >> y >> a >> b;
		double ans = (y-x)/(a+b);
		if(ans == trunc(ans))// && ans >= x && ans <=y)
			cout << ans << endl;
		else
			cout << "-1" << endl;
	}
}