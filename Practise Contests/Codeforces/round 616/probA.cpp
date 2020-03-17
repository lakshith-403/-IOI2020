#include<fstream>
#include<iostream>
#include<vector>

using namespace std;

int main(){
	// ifstream in("prob.in");
	int t;
	cin >> t;
	int pos;
	for(int i=0;i<t;i++){
		int n;
		cin >> n;
		vector<int> S;
		int sum = 0;
		// cout << "+";
		for(int j=0;j<n;j++){
			char temp;
			cin >> temp;
			S.push_back(temp - '0');
			sum += temp - '0';
			// cout << temp - '0';
		}
		// cout << endl;
		if(sum%2==0 && S.at(n-1)%2!=0){
			for(int j=0;j<n;j++)
				cout << S.at(j);
			cout << endl;
			continue;
		}
		// cout << "booyah" << endl;
		if(S.at(n-1)%2==0){
			// cout << "sdd" << S.at(n-1) <<  endl;
			//remove from end until odd num is found
			int j;
			for(j=n-1;j>=0;j--){
				if(S.at(j)%2==0){
					sum -= S.at(j);
					S.pop_back();
				}
				else
					break;
			}

			if(j==-1)
			{
				cout << "-1" << endl;
				continue;
			}
		}

		n = S.size();
		pos = -1;
		if(sum%2!=0){
			//delete an odd number
			int j;
			for(j=0;j<n-1;j++){
				if(S.at(j)%2!=0)
					pos = j;
			}
			if(pos==-1){
				cout << "-1" << endl;
				continue;
			}
		}
		// cout << "+++++++" << n << endl;
		for(int j=0;j<n;j++)
			if(j!=pos)
				cout << S.at(j);
		
		cout << endl;
	}
}