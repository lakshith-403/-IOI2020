/*
 ID: lakshit4
 LANG: C++
 TASK: frac1
*/

#include<bits/stdc++.h>

using namespace std;

int GCD(int a,int b){
	if(b==0)
		return a;
	return GCD(b,a%b);
}

bool sortfrac(pair<int,int> &a, pair<int,int> &b){
	//cout <<  (a.first/a.second) << " <> " << (b.first/b.second) << "    " << ((a.first/a.second) < (b.first/b.second)) << endl;
	return ((double)a.first/(double)a.second) < ((double)b.first/(double)b.second);
}

int main(){
	ifstream in("frac1.in");
	ofstream out("frac1.out");
	int n;
	in >> n;

	vector<set<int>> mem(n+1);
	fill(mem.begin(),mem.end(),set<int>());
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			int gcd = GCD(i,j);
			int I = i/gcd;
			int J = j/gcd;
			mem.at(I).insert(J);
		}
	}

	vector<pair<int,int>> frac;

	for(int i=0;i<mem.size();i++){
		set<int>::iterator j;
		for(j = mem.at(i).begin();j!=mem.at(i).end();++j)
			frac.push_back({*j,i});
			//cout << *j << "/" << i << " , ";
		//cout<<endl;
	}

	frac.push_back({0,1});
	frac.push_back({1,1});

	sort(frac.begin(), frac.end() , sortfrac);

	for(int i=0;i<frac.size();i++)
		out << frac.at(i).first << "/" << frac.at(i).second << endl;

}
