#include<bits/stdc++.h>

using namespace std;

int main(){
	int num[] = {10,1,9,4,2,5};
	int n = 6;
	std::vector<int> bestRun;

	bestRun.push_back(num[n-1]);
	int highestRun = 1;
	for(int i=n-2;i>=0;i--){
		if(num[i]<bestRun.at(0))
			bestRun.at(0)=num[i];
		for(int j=highestRun-1;j>=0;j--){
			if(num[i]>bestRun.at(j) && j!=highestRun-1){
				bestRun.at(j+1) = num[i];
				//highestRun++;
				break;
			}else if(num[i]>bestRun.at(j) && j== highestRun-1){
				bestRun.push_back(num[i]);
				highestRun++;
			}

		}
	}
	cout << highestRun;
}