/*
 ID: lakshit4
 LANG: C++
 TASK: runround
*/

#include<bits/stdc++.h>

using namespace std;

long long getNum(long long num,int l){
	//cout << l << ": " << (num - (num/(int)pow(10,l))*(int)pow(10,l))/(int)pow(10,l-1) << endl;
	return (num - (num/(int)pow(10,l))*(int)pow(10,l))/(int)pow(10,l-1);
}

int main(){
	ifstream in("runround.in");
	ofstream out("runround.out");
	long n;
	in >> n;
	n++;
	while(true){
		int length =  (log(n) / log(10));
		length++;
		//cout << "length: " << length << endl;
		vector<int> mem(10,0);
		int pos = 0;
		int i;
		for(i=0;i<length;i++){
			int temp = getNum(n,length-pos);
			mem.at(temp)++;
			if(mem.at(temp)>1){
				//cout<<"breaking" << endl;
			 break;
			}
			//cout<< "at pos: " << getNum(n,length-pos) << endl;
			pos+=(temp%length);
			pos = pos%length;
		}
		if(pos==0 && length==i)
			break;
		n++;
	}
	out << n << endl;
}