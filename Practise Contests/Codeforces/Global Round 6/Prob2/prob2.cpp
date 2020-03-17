#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
	//ifstream input("prob2.in");
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int num;
		cin >> num;
		int r = num%14;
		if((r==1 || r==6 || r==5 || r==2 || r==4 || r==3) && num > 14)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}