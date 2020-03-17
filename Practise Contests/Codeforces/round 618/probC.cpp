#include <bits/stdc++.h>

using namespace std;

bool compareOR(int i1, int i2){
	if(__builtin_popcount(i1) == __builtin_popcount(i2))
		return i1 > i2;
	return __builtin_popcount(i1) > __builtin_popcount(i2);
}

int main(){
	ifstream in("prob.in");
	int n;
	in >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		in >> arr[i];
	}
	sort(arr,arr+n,compareOR);
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl << (((3|5)-5) | 4)-4;
}