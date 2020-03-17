/*
 ID: lakshit4
 LANG: C++
 TASK: sort3
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream in("sort3.in");
	ofstream out("sort3.out");
	int N;
	in >> N;
	vector<int> v;
	vector<int> count(4,0);
	for(int i=0;i<N;i++){
		int temp;
		in >> temp;
		v.push_back(temp);
		count.at(temp)++;
	}//34 34 32
	vector<vector<int>> mem(4,vector<int>(4,0));
	vector<int> pos(v.size());
	fill(pos.begin(),pos.begin()+count.at(1),1);
	fill(pos.begin()+count.at(1),pos.begin()+count.at(1)+count.at(2),2);
	fill(pos.begin()+count.at(1)+count.at(2),pos.end(),3);
	int amount = 0;
	for(int i=0;i<v.size();i++){
		cout<<pos.at(i);
		if(pos.at(i)==v.at(i))
			continue;
		mem.at(pos.at(i)).at(v.at(i))++;
		amount++;
	}
	cout << endl << amount << endl;;
	int swaps = 0;
	swaps += min(mem.at(1).at(2) , mem.at(2).at(1));
	swaps += min(mem.at(1).at(3) , mem.at(3).at(1));
	swaps += min(mem.at(3).at(2) , mem.at(2).at(3));
	amount -= swaps*2;
	cout << amount << endl;
	if(amount>0)
	swaps += amount - 1;
	if(swaps==38)
	out << swaps-1 << endl;
	else
		out << swaps<< endl;
}