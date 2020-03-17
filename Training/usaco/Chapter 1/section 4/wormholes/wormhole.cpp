/*
 ID: lakshit4
 LANG: C++
 TASK: wormhole
 */

#include <iostream>
#include <fstream>
#include <array>

const int max = 12;
int n;
int x[max+1],y[max+1];
int right[max+1];
int partner[max+1];

bool checkCycle(){
	for(int i=1;i<=n;i++){
		int pos = i;
		for(int count=0;count<n;count++)
			pos = right[partner[pos]];
		if(pos!=0)
			return true;
	}
	return false;
}

int solve(){
	int i=0;
	int total = 0;
	for(i=1;i<=n;i++)
		if(partner[i]==0)
			break;
	if(i>n)
		if(checkCycle())
			return 1;
		else
			return 0;
	for(int j=i+1;j<=n;j++){
		if(partner[j]!=0)
			continue;

		partner[i] = j;
		partner[j] = i;
		total += solve();
		partner[i] = partner[j] = 0;
	}
	return total;
}

int main(){
	std::ifstream input("wormhole.in");
	input >> n;

	for(int i=1;i<=n;i++)
		input >> x[i] >> y[i];

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(x[i]<x[j] && y[i]==y[j])
				if(right[i]==0 || x[j]-x[i]<x[right[i]]-x[i])
					right[i] = j;
	std::ofstream output("wormhole.out");
	output << solve() << std::endl;
	output.close();
	return 0;
}