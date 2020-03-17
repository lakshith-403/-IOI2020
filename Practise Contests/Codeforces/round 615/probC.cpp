#include <bits/stdc++.h>

using namespace std;

int binarysearch(int i,int j,int n){
	// cout << j << endl;
	if (j<2 || j==n/i/2)
		return -1;
	
	int k = n/i/j;
	if((i)*(j)*(k)==n)
		return j;
	if((i)*(j)*(k)>n)
		return binarysearch(i,j+((n/i/2)-j)/2,n);
	else
		return binarysearch(i,j-(j/2),n);
}

int main(){
	// ifstream in("prob.in");
	int t;
	cin >> t;
	for(int z=0;z<t;z++){
		int n;
		cin >> n;
		int i,j,k;
		bool flag = false;

		for(int i=2;i<=n/4;i++){
			// for(int j=2;j<=n/i/2;j++){
			// 		int k = n/i/j;
			// 		if((i)*(j)*(k)==n && i!=j && j!=k && i!=k && k>=2){
			// 			cout << "YES" << endl << i << " " << j << " " << k << endl;
			// 			flag = true;
			// 			break;
			// 		}
			// }
			j = binarysearch(i,((n/i/2)-2)/2,n);
			if(j==-1)
				continue;
			else{
				// cout << "yes";
				int k = n/i/j;
				if(!(i!=j && j!=k && i!=k && k>=2))
					continue;
				cout << "YES" << endl << i << " " << j << " " << k << endl;
				flag = true;
				break;
			}

		}
		if(!flag)
			cout << "NO" << endl;
	}
}