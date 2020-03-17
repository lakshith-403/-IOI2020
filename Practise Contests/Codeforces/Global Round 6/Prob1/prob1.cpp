#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
//stoi
//strlen
void check(string num){
	bool three = false;
	bool two = false;
	bool zero = false;

	int sum = 0;
	int zeroCount= 0;
	for(int i=0;i<num.length();i++){
		int n = num[i]-'0';
		sum += n;
		if(n%2==0 && n!=0)
			two=true;
		if(n==0)
			zeroCount++;

	}
	//cout << sum << " " << zeroCount << endl;
	if(sum%3==0)
		three = true;
	if(zeroCount!=0)
		zero = true;

	if((two || zeroCount>1) && three && zero)
		cout << "red" << endl;
	else
		cout << "cyan" << endl;

}

int main(){
	//ifstream input("prob1.in");
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string num;
		cin >> num;
		check(num);
	}
}