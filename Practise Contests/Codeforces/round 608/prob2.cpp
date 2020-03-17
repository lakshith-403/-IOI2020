#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	//ifstream cin("cin.txt");
	int n, sx, sy;
	cin >> n >> sx >> sy;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	int x,y;
	for(int i=0;i<n;i++){
		cin >> x >> y;
		if(sx<x)c1++;
		if(sx>x)c2++;
		if(sy<y)c4++;
		if(sy>y)c3++;
	}
	if(sx==0)c2=0;
	if(sy==0)c3=0;
	int MAX = max(c1 , max(c2 , max(c3 , c4)));
	if(MAX==c1){
		cout << MAX << endl;
		cout << sx+1 << " " << sy << endl;
	}else if(MAX==c2){
		cout << MAX << endl;
		cout << sx-1 << " " << sy << endl;
	}else if(MAX==c3){
		cout << MAX << endl;
		cout << sx << " " << sy-1 << endl;
	}else if(MAX==c4){
		cout << MAX << endl;
		cout << sx << " " << sy+1<< endl;
	}
}