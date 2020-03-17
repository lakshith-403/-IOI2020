/*
 ID: lakshit4
 LANG: C++
 TASK: milk3
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;
int A,B,C;
bool check[8835*7];
bool solutions[21];

bool Check(int a,int b,int c,int s){
	return check[(a*1) + (b*21) + (c*421) + (s*8835)];
}

void setTrue(int a,int b,int c,int s){
	check[(a*1) + (b*21) + (c*421) + (s*8835)] = true;
}

void solve(int a,int b, int c, int s){
	if(Check(a,b,c,s))
		return;
	setTrue(a,b,c,s);
	int temp;
	if(a==0)
		solutions[c]=true;
	switch(s){
		case 1:
			temp = b;
			b = min(B,b+a);
			a -= b-temp;
		break;
		case 2:
			temp = c;
			c = min(C,c+a);
			a -= c-temp;
		break;
		case 3:
			temp = a;
			a = min(A,b+a);
			b -= a-temp;
		break;
		case 4:
			temp = c;
			c = min(C,b+c);
			b -= c-temp;
		break;
		case 5:
			temp = a;
			a = min(A,c+a);
			c -= a-temp;
		break;
		case 6:
			temp = b;
			b = min(B,c+b);
			c -= b-temp;
		break;
	}
	for(int i=0;i<6;i++)
		solve(a,b,c,i+1);
}
int main(){
	ifstream input("milk3.in");
	ofstream output("milk3.out");
	input >> A >> B >> C;
	for(int i=0;i<8835*7;i++)
		check[i] = false;
	for(int i=0;i<21;i++)
		solutions[i] = false;
	for(int i=0;i<6;i++)
		solve(0,0,C,i+1);
	string str;
	solutions[C]=true;
	for(int i=0;i<21;i++)
		if(solutions[i])
			str += to_string(i)+" ";
	str.erase(str.length()-1);
	output << str << endl;
}