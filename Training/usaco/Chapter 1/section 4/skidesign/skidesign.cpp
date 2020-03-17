/*
 ID: lakshit4
 LANG: C++
 TASK: skidesign
 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n,hills[1000];

int main()
{
	ifstream input("skidesign.in");
	input >> n;
	for (int i=0; i<n; i++)
		input >> hills[i];
	input.close();

	int mincost=100000000;
	for (int i=0; i<=83; i++)
	{
		int cost=0,temp;
		for (int j=0; j<n; j++)
		{
			if (hills[j]<i)
				temp=i-hills[j];
			else if (hills[j]>i+17)
				temp=hills[j]-(i+17);
			else
				temp=0;
			cost+=temp*temp;
		}
		mincost=min(mincost,cost);
	}

	ofstream output("skidesign.out");
	output << mincost << endl;
	output.close();
}