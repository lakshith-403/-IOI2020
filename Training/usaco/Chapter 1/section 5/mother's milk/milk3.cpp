#include<iostream>
#include<fstream>

using namespace std;

int A,B,C;

// A-B 1
// A-C 2
// B-A 3
// B-C 4
// C-A 5
// C-B 6

void pour(int a, int b, int c , int state){
	cout << a << b << c << endl;
	int t;
	switch(state){
		case 1:
			if(a==0 || b==B)
				return;
			t = b;
			b = min(B,a+b);
			a -= min(B-t,a);
			for(int i=1;i<=6;i++)
				pour(a,b,c,i);
		break;
		case 2:
			if(a==0 || c==C)
				return;
			t=c;
			c = min(C,a+c);
			a -= min(C,a);
			for(int i=1;i<=6;i++)
				pour(a,b,c,i);
		break;
		case 3:
			if(b==0 || a==A)
				return;
			t = a;
			a = min(A,b+a);
			b -= min(A-a,b);
			for(int i=1;i<=6;i++)
				pour(a,b,c,i);
		break;
		case 4:
			if(b==0 || c==C)
				return;
			t = c;
			c = min(C,b+c);
			b -= min(C-c,b);
			for(int i=1;i<=6;i++)
				pour(a,b,c,i);
		break;
		case 5:
			if(c==0 || a==A)
				return;
			t = a;
			a = min(A,c+a);
			c -= min(A-a,c);
			for(int i=1;i<=6;i++)
				pour(a,b,c,i);
		break;
		case 6:
			if(c==0 || b==B)
				return;
			t = b;
			b = min(B,c+b);
			c -= min(B-b,c);
			for(int i=1;i<=6;i++)
				pour(a,b,c,i);
		break;
	}
		if(a!=A && c==0){
		cout<< a << " ";
		return;
	}
}

int main(){
	ifstream input("milk3.in");
	input >> A >> B >> C;
	pour(A,0,0,1);
}