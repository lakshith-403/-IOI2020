/*
ID: lakshit4
PROG: game1
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 102;
int n,d[maxn];
int sum[maxn][maxn],f[maxn][maxn];
int main()
{
	fstream fin("game1.in",ios::in);
	fstream fout("game1.out",ios::out);
	fin>>n;
	for(int i=1;i<=n;i++)
	{
		fin>>d[i];
		f[i][i]=sum[i][i]=d[i];
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			sum[i][j]=sum[i][j-1]+d[j];
	for(int len=2;len<=n;len++)
		for(int i=1;i<=n-len+1;i++)
		{
			int j=i+len-1;
			f[i][j]=max(d[i]+sum[i+1][j]-f[i+1][j],d[j]+sum[i][j-1]-f[i][j-1]);
		}
	fout<<f[1][n]<<" "<<sum[1][n]-f[1][n]<<endl;
	fin.close();
	fout.close();
	return 0;
}
