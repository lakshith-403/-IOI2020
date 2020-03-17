/*
 ID: lakshit4
 LANG: C++
 TASK: lamps
*/

#include <bits/stdc++.h>

using namespace std;

int C;
int N;
vector<int> on;
vector<int> off;
vector<vector<int>> mem;
vector<vector<int>> ans;

void changeState(vector<int> *vec , int s){
	int Size = N;
	switch(s){
		case 1:
		for(int i=0;i<Size;i++)
			vec->at(i) = (vec->at(i)==1) ? 0 : 1;
		break;
		case 2:
		for(int i=0;i<Size;i+=2)
			vec->at(i) = (vec->at(i)==1) ? 0 : 1;
		break;
		case 3:
		for(int i=1;i<Size;i+=2)
			vec->at(i) = (vec->at(i)==1) ? 0 : 1;
		break;
		case 4:
		for(int i=0;i<Size;i+=3)
			vec->at(i) = (vec->at(i)==1) ? 0 : 1;
		break;
	}
	// for(int i=0;i<Size;i++)
	// 	cout << vec->at(i) << " ";
	// cout << endl;


}

void solve(int n,vector<int> vec,int sum){
	if(vec.size()==4 ){
		if(sum==n)
			mem.push_back(vec);
		return;
	}
	for(int i=0;i<=n-sum;i++){
		vec.push_back(i);
		solve(n,vec,sum+i);
		vec.pop_back();
	}
}

bool check(vector<int> switches){
	vector<int> Lamps(N,1);
	for(int i=0;i<switches.size();i++)
		if(switches.at(i)%2==1)
			changeState(&Lamps,i+1);
	bool flag = true;
	for(int i=0;i<on.size();i++){
		//if(on.at(i)>6)continue;
		if(Lamps.at(on.at(i)-1)==0){
			flag = false;
			break;
		}
	}
	for(int i=0;i<off.size();i++){
		//if(off.at(i)>6)continue;
		if(Lamps.at(off.at(i)-1)==1){
			flag = false;
			break;
		}
	}
	if(flag){
		// for(int i=0;i<Lamps.size();i++)
		// 	cout << Lamps.at(i) << " ";
		// cout << endl;
		ans.push_back(Lamps);
	}
	return flag;
}

bool compareAns(vector<int> v1, vector<int> v2) 
{ 
	for(int i=0;i<N;i++)
		if(v1.at(i) != v2.at(i))
			return v1.at(i) < v2.at(i);
    return v1.at(0) < v2.at(0);
}

int main(){
	ifstream in("lamps.in");
	ofstream out("lamps.out");
	in >> N;
	in >> C;
	// C=21;
	while(true){
		int temp;
		in >> temp;
		if(temp==-1)
			break;
		on.push_back(temp);
	}

	while(true){
		int temp;
		in >> temp;
		if(temp==-1)
			break;
		off.push_back(temp);
	}

	if(C>3 && C%2==0)
		C=4;
	if(C>3 && C%2==1)
		C=3;
	vector<int> temp;

	//for(int i=1;i<=4;i++)
	solve(C,temp,0);
					
	// cout << mem.size() << endl;
	// for(int j=0;j<mem.size();j++){
	// 	for(int i=0;i<mem.at(j).size();i++)
	// 		cout << mem.at(j).at(i) << " ";
	// 	cout << endl;
	// }
	// cout << " ++++++++++ " << endl;
	int cc = 0;
	for(int j=0;j<mem.size();j++)
		if(check(mem.at(j)))
			cc++;
	if(cc==0){
		out << "IMPOSSIBLE" << endl;
		return 0;
	}
	sort(ans.begin(),ans.end(),compareAns);
	vector<int> prev(101,-1);
	for(int j=0;j<ans.size();j++){
		int ccc = 0;
		for(int i=0;i<ans.at(j).size();i++){
			if(ans.at(j).at(i)==prev.at(i)) ccc++;
			//cout << ans.at(j).at(i);
		}
		if(ccc==N)continue;
		prev=ans.at(j);
		for(int i=0;i<ans.at(j).size();i++){
			out << ans.at(j).at(i);
		}
		out << endl;
	}
}