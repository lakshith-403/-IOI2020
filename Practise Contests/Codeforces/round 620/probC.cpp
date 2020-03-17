#include <bits/stdc++.h>

using namespace std;
int n,m;
int main(){
	// ifstream in("prob.in");
	int t;
	cin >> t;
	for(int j=0;j<t;j++){
		cin >> n >> m;
		pair<int,int> temp = {m,m};
		int prev = 0;
		int i;
		for(i=0;i<n;i++){
			int t,l,h;
			cin >> t >> l >> h;
			// cout  << l << " " <<h << endl;
			if(h>temp.second){
				temp.second = temp.second+(t-prev) > h ? h : temp.second+(t-prev); 
				temp.first = temp.first+(t-prev) > l ? l : temp.first+(t-prev);
			}else{
				temp.second = temp.second-(t-prev) < h ? h : temp.second-(t-prev);
				temp.first = temp.first-(t-prev) < l ? l : temp.first-(t-prev);
			}
			// cout << t-prev << " " << temp.first << " " << temp.second << endl;
			prev = t;
			// cout << temp.second << " " << ( temp.second < l)<< " " << l<< endl;
			if(temp.second >h) temp.second = h;
			if(temp.first < l)temp.first = l;
			// cout << temp.first << " " << temp.second << endl;
			if(!((temp.first >= l && temp.first <= h) && (temp.second >= l && temp.second <= h)))
				break;
		}
		if(i==n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}