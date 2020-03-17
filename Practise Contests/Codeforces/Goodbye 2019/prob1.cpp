#include<iostream>
#include<fstream>

using namespace std;
 int main(){
 	//ifstream in("prob1.in");
 	int t;
 	cin >> t;
 	for(int i=0;i<t;i++){
 		int n,k1,k2;
 		cin >> n >> k1 >> k2;
 		int max1 = -1;
 		int max2 = -1;
 		int k;
 		for(int j=0;j<k1;j++){
 			cin >> k;
 			if(max1<k)
 				max1=k;
 		}
 		for(int j=0;j<k2;j++){
 			cin >> k;
 			if(max2<k)
 				max2=k;
 		}
 		if(max1>max2)
 			cout << "YES" << endl;
 		else
 			cout << "NO" << endl;
 	}
 }