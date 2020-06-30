/*
ID: lakshit4
PROG: lgame
LANG: C++
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("lgame.in");
ifstream fdict("lgame.dict");
ofstream fout("lgame.out");

const int score[26] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
int c[26] = {0};
int cc[26] = {0};
string word[40000];
int s[40000];
int n;

void init()
{
	int i,j;
	string str;
	fin >> str;
	for(i = 0; i < str.size(); i ++)
		c[str[i] - 'a'] ++;
	i = 0;
	while(1)
	{
		memset(cc,0,sizeof(cc));
		fdict >> str;
		if(str == ".")
			break;
		for(j = 0; j < str.size(); j ++)
		{
			cc[str[j] - 'a'] ++;
			if(cc[str[j] - 'a'] > c[str[j] - 'a'])
				break;
		}
		if(j == str.size())
			word[i ++] = str;
	}
	n = i;
}

int maxS = 0;
int sw[40000],swn = 0;
string ans[40000];
int ansN = 0;

void work()
{
	int i,j,k,sum;
	for(i = 0; i < n; i ++)
	{
		sum = 0;
		for(j = 0; j < word[i].size(); j ++)
			sum += score[word[i][j] - 'a'];
		if(maxS < sum)
			maxS = sum;
		s[i] = sum;
		
		if(word[i].size() < 5)
			sw[swn ++] = i;
	}
	sw[swn] = n+1;
	ansN = 0;
	for(j = 0; j < sw[0]; j ++)
		if(s[j] == maxS)
			ans[ansN ++] = word[j];
	for(i = 0; i < swn; i ++)
	{
		for(j = sw[i]; j < sw[i + 1]; j ++)
			if(s[j] == maxS)
				ans[ansN ++] = word[j];
		for(j = i; j < swn; j ++)
		{
			if(word[sw[i]].size() + word[sw[j]].size() < 8 && s[sw[j]] + s[sw[i]] >= maxS)
			{	
				memset(cc,0,sizeof(cc));
				for(k = 0; k < word[sw[i]].size(); k ++)
				{
					cc[word[sw[i]][k] - 'a'] ++;
					if(cc[word[sw[i]][k] - 'a'] > c[word[sw[i]][k] - 'a'])
						break;
				}
				if(k != word[sw[i]].size())
					continue;
				for(k = 0; k < word[sw[j]].size(); k ++)
				{
					cc[word[sw[j]][k] - 'a'] ++;
					if(cc[word[sw[j]][k] - 'a'] > c[word[sw[j]][k] - 'a'])
						break;
				}
				if(k != word[sw[j]].size())
					continue;
				
				if(s[sw[j]] + s[sw[i]] > maxS)
				{
					maxS = s[sw[j]] + s[sw[i]];
					ansN = 0;
				}
				ans[ansN ++] = word[sw[i]] + " " + word[sw[j]];
			}
		}
	}
}

void output()
{
	fout << maxS << endl;
	for(int i = 0; i < ansN; i ++)
		fout << ans[i] << endl;
}

int main()
{
	int i,j;
	init();
	work();
	output();
    return 0;
}
