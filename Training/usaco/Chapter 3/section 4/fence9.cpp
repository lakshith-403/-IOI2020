/*
ID: lakshit4
PROG: fence9
LANG: C++
*/
//This code isn't mine
#include <bits/stdc++.h>
using namespace std;
 int gcd (int a, int b) {
    if (a < b){
    	int t = a;
    	a = b;
    	b = t;
    }
    int r;
    while (r = a % b) {
	     a = b;
	      b = r;
    }
    return (b);
}

int main () {
    int x, y, w;
    ifstream filein ("fence9.in");
    filein >> x >> y >> w;
    filein.close();

    if (y == 0) {
    	ofstream fileout ("fence9.out");
    	fileout << 0 << endl;
    	fileout.close ();
    	return(0);
    }
    int a2 = y * w;
    int b = ((x > 0) ? gcd(x,y) : y) +
		((x == w) ? y : gcd(((x < w) ? (w - x) : (x - w)), y)) + w;
    int i = (a2 + 2 - b) / 2;
    ofstream fileout("fence9.out");
    fileout << i << endl;
    fileout.close();
    return (0);
}
