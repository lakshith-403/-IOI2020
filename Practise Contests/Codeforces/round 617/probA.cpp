#include <bits/stdc++.h>

using namespace std;

int main(){
	//ifstream in("prob.in");
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int even = 0, odd =0;
		int sum = 0;
		for(int j=0;j<n;j++){
			int a;
			cin >> a;
			if(a%2==0)even++;
			else odd++;
			sum += a;
		}
		if(sum%2==1)
		{
			cout << "YES" << endl;
			continue;
		}
		if(even>=1&&odd>=1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}