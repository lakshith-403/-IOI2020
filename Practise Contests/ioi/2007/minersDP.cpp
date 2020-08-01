#include <bits/stdc++.h>

using namespace std;

inline void io_setup(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int n;
int DP[2][4][4][4][4];
int A[100002];
char c;

int t(int a,int b,int c){
	int r = 0;
	for(int i=1;i<=3;i++)
		if(i==a ||i==b || i==c)r++;
	return r;
}

int main(){
	io_setup();
	cin >> n;
	for( int i = 1; i <= n; i++ ){
		cin >> c;
		if( c == 'M' )
			A[i] = 1;
		if( c == 'B' )
			A[i] = 2;
		if( c == 'F' )
			A[i] = 3;
	}
	
	int a = 0, b = 1;
	int i, x, y, r, s;
	for( i = n; i; i-- ){
		swap( a, b );
		for( x = 0; x < 4; x++ )
			for( y = 0; y < 4; y++ )
				for( r = 0; r < 4; r++ )
					for( s = 0; s < 4; s++ )
						DP[a][x][y][r][s] = max( DP[b][y][ A[i] ][r][s] + t( x, y, A[i] ), DP[b][x][y][s][ A[i] ] + t( r, s, A[i] ) );
	}
	cout << DP[a][0][0][0][0] << "\n";
}