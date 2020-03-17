/*
ID: lakshit4
PROG: fracdec
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int N,D;
int mem[10];
int r[1000000];

int main(){
	ifstream in("fracdec.in");
	ofstream out("fracdec.out");

	in >> N >> D;
	int n = N;
	std::vector<int> ans;
	// int decimalpoint = to_string(N/D).length();
	// cout << to_string(N/D).length() << endl;
	int count = 0;
	int pos;
	bool flag = false;
	while(true){
		int temp = n/D;
		count++;
		if(r[n]!=0){
			pos = r[n];
			flag = true;
			break;	
		}
		ans.push_back(temp);
		if(count>1)
			r[n] = count;
		if(n%D==0)
			break;
		n-= temp * D;
		n*=10;
		// cout << n << endl;
	}
	// cout << "ans: ";
	// cout << decimalpoint << endl;
	int c = 0;
	while(c<ans.size()){
		for(int i=0;i<76;i++){
			if(c==1){
				out << ".";
				i++;
			}
			if(c==pos-1){
				out << "(";
				i++;
			}
			out<<ans.at(c);
			i--;
			i+=to_string(ans.at(c)).length();
			// cout << i ;
			c++;
			if(c==ans.size())
				break;
		}
		if(c!=ans.size())
			out << endl;
	}

	if(flag)
	out << ")";
	if(ans.size()==1)
		out << ".0";
	out << endl;
	// cout << pos << endl;
}