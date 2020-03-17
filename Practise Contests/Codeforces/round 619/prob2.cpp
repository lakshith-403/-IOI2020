#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream in("prob.in");
	int t;
	in >> t;
	for(int j=0;j<t;j++){
		int n;
		in >> n;
		int m =-1;
		int k;
		int maxk = INT_MIN;
		int maxP = INT_MIN;
		int prev = -1;
		for(int i=0;i<n;i++){
			int a;
			in >> a;
			if(a!=-1)
				if(prev==-1)
					if(m!=-1)
					{
						int temp = m;
						m = (m+a)/2;
						maxk += max(m-temp,temp-m);
					}
					else
						m = a;
			int ta = (a==-1)?m:a;
			int tp = (prev==-1)?m:prev;
			k = max(ta-tp , tp-ta);
			if(k>maxP)
				maxP = k;
			if(k>maxk)
				maxk = k;
			prev = a;
		}
		if(m==-1){
			m=1;
			k=0;
		}
		cout << min(maxk,maxP) << " " << m << endl;
	}
}