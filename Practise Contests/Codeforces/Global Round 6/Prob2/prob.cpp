#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
	ifstream input("prob2.in");
	int n;
	input >> n;
	for(int i=0;i<n;i++){
		int num;
		input >> num;
		int r = num%14;
		if(r>=1 && r<=6 && num > 14)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}