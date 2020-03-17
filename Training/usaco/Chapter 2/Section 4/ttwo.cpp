#include <bits/stdc++.h>

using namespace std;

int x[3],y[3];
int dx[9] = {-1,0,+1,0,-1,0,+1,0,-1};
int dy[9] = {0,1,0,-1,0,1,0,-1,0};
int fd=0,cd=0;

int main(){
	ifstream in("ttwo.in");
	char grid[12][12];
	for(int i=0;i<=11;i++)
		for(int j=0;j<=11;j++) grid[i][j] = '*';

	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++){
			in >> grid[i][j];
			if(grid[i][j]=='C'){x[1] = i;y[1] = j;}
			else if(grid[i][j]=='F'){x[2] = i;y[2] = j;}
		}
	cout << "for begin" << endl;
	for(int i=0;i<300;i++){
		if(grid[x[1]+dx[fd]][y[1]+dy[fd]]!='*'){x[1] += dx[fd]; y[1] += dy[fd];}
		else{
			for(int j=fd+1;j<7;j++){
				if(grid[x[1]+dx[j]][y[1]+dy[j]]!='*'){
					//x[1] += dx[j];
					//y[1] += dy[j];
					fd = j;
					break;
				}
				
			}
			fd%=4;}
		if(grid[x[2]+dx[cd]][y[2]+dy[cd]]!='*'){x[2] += dx[cd]; y[2] += dy[cd];}
		else{
			for(int j=cd+1;j<7;j++){
				if(grid[x[2]+dx[j]][y[2]+dy[j]]!='*'){
					//x[2] += dx[j];
					//y[2] += dy[j];
					cd = j;
					break;
				}	
			}
			cd%=4;}

		cout << "________________" << endl;
		for(int i=0;i<=11;i++){
			for(int j=0;j<=11;j++){
				if(x[1]==i && y[1]==j) cout << "C";
				else if(x[2]==i && y[2]==j) cout << "F"; 
				else if(grid[i][j]=='*') cout << "#";
				else cout << " ";
			}
			cout << endl;
		}
		cout << x[1] << " " << y[1] << " " << fd << endl;
		cout << x[2] << " " << y[2] << " " << cd << endl;
		if(x[1]==x[2] && y[1]==y[2]){cout << i << endl; return 0;}
	}
	cout << 0 << endl;
}