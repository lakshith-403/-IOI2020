#include <bits/stdc++.h>

using namespace std;

int main(){
	// ifstream in("prob.in");
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n;
		cin >> n;
		n *= 2;
		int arr[n];
		for(int j=0;j<n;j++){
			cin >> arr[j];
		}
		int size = sizeof(arr)/sizeof(arr[0]);
		sort(arr,arr+n);
		cout << arr[n/2] - arr[(n/2)-1] << endl;
	}
}