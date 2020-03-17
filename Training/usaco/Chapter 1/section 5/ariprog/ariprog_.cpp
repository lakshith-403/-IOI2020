/*
 ID: lakshit4
 LANG: C++
 TASK: ariprog
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;  

int main(){
	ifstream input("ariprog.in");
	int N;
	int M;
	input >> N >> M;
	set<int> Set;
	
	for(int i=0;i<=M;i++)
		for(int j=0;j<=M;j++)
			Set.insert((i*i)+(j*j));

	bool flag = false;
	for(int j=1;j<M*M + M*M;j++){
		set<int> :: iterator i;
		for(i=Set.begin();i!=Set.end();++i){
			cout << "set: " << *i << "++++" << j << endl;
			int pos = *i;
			int k;
			for(
				k=1;k<=N;k++){
				
				pos += j;
				if(Set.count(pos)==0)
					break;
			}
			if(k>=N){
				cout << *i << " " << j << endl;
				flag = true;
			}
		}
	}
	if(!flag)
		cout << "NONE" << endl;
}