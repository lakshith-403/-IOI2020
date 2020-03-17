#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream in("prob.in");
	int t;
	cin >> t;
	for(int j=0;j<t;j++){
		// cout << j;
		int n;
		cin >> n;
		// cout << "blaaaaaaaaaaaa:  " << n << endl;
		int prev = -1;
		int i;
		int temp =0;
		for(i=0;i<n;i++){
			int a;
			cin >> a;
			// cout << a << " ";
			if(a>prev){
				// cout << a << "<>" << prev << endl;
				prev++;
			}
			else{
				// cout << temp << "<>" << prev << endl;
				if(temp >prev)
					prev = temp;
				break;
			}
			temp = a;
		}
		// cout << "prev " << prev <<" pos: " << i <<" temp: " << temp << endl;
		for(i=i;i<n;i++){
			int a;
			in >> a;
			// cout << a << " ";
			if(a>=prev)
				prev--;
			else
				prev = a-1;
			if(prev<0)
				break;
		}
		// cout << endl;
		if(i==n)
			cout << "YES" << endl;
		else
		{
			cout << "NO" << endl;
		}	
	}
}