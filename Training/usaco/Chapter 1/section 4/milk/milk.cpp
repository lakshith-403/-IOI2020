/*

ID: lakshit4

LANG: C++

TASK: milk

 */
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include<tuple>

using namespace std;

struct farmer 
{ 
    int price, amount; 
};

bool compareFarmer(farmer f1 , farmer f2){
	return f1.price < f2.price;
}

int main(){
    ifstream input ("milk.in");
    int n;
    int m;
    input >> n;
    input >> m;
    vector<farmer> farmers;
    for(int i=0;i<m;i++){
    	farmer f1;
    	input >> f1.price;
    	input >> f1.amount;
    	farmers.push_back(f1);
    }
	input.close();
	sort(farmers.begin() , farmers.end() , compareFarmer);
    ofstream output("milk.out");
    int totalPrice = 0;
    int pos = 0;
    cout << n << endl;
    while(n>0){
    	farmer f = farmers.at(pos);
    	cout << f.price << " " << f.amount << endl;
    	if(f.amount <= n){
    		totalPrice += f.price * f.amount;
    		n -= f.amount;
    		pos ++;
    	}else{
    		totalPrice += f.price * n;
    		break;
    	}
    }
    output << totalPrice << endl;
    output.close();
}
