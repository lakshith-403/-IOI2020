/*
 ID: lakshit4
 LANG: C++
 TASK: zerosum
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> mem;
int N;

void dfs(int n, vector<char> vec){
	if(n==1){
		mem.push_back(vec);
		return;
	}
	vec.push_back('+');
	dfs(n-1,vec);
	vec.pop_back();

	vec.push_back('-');
	dfs(n-1,vec);
	vec.pop_back();

	vec.push_back(' ');
	dfs(n-1,vec);
	vec.pop_back();
	return;
}

bool sortChar(vector<char> c1, vector<char> c2){
	for(int i=0;i<c1.size();i++)
		if(c1.at(i)!=c2.at(i))
			return c1.at(i) < c2.at(i);
	return c1.at(0) < c2.at(0);
}

int main(){
	ifstream in("zerosum.in");
	ofstream out("zerosum.out");
	in >> N;
	std::vector<char> v;
	dfs(N,v);
	sort(mem.begin(),mem.end(),sortChar);

	for(vector<char> vec : mem){
		int i=2;
		int sum = 1;
		char prev = '+';
		bool flag = true;
		for(char x : vec){
			// cout << x;
			if(x=='+'){sum +=i; prev ='+';}
			else if(x=='-'){sum -=i; prev ='-';}
			else if(x==' '){
				if(prev==' ')
				{
					flag = false;
					break;
				}
				else if(prev=='+'){
					sum -= i-1;
					sum += (i-1)*10 + i;
				}else if(prev=='-'){
					sum += i-1;
					sum -= (i-1)*10 + i;
				}
				prev = ' ';
			}
			i++;
		}
		// cout << endl << sum << endl;
		if(!flag || sum != 0) continue;
		i = 1;
		for(char x : vec)
			out << i++ << x;
		out << N << endl;
	}	
}