#include <bits/stdc++.h>

using namespace std;

int main(){
	// ifstream in("prob.in");
	int t;
	cin >> t;

	for(int i=0;i<t;i++){
		int n;
		cin >> n;
		int sum = 0;
		int zeroCount = 0;
		for(int j=0;j<n;j++){
			int a;
			cin >> a;
			sum += a;
			if(a==0)
				zeroCount++;
		}
		sum += zeroCount;
		int ans = 0;
		if(sum==0)
			ans++;
		ans += zeroCount;
		cout << ans << endl;
	}
}