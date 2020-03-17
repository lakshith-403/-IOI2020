/*

ID: lakshit4

LANG: C++

TASK: dualpal

 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool isPalindrom(string s){
	
	string first = s.substr(0,(s.length()-(s.length()%2==0?0:1))/2);
	string second;
	for(int i=s.length()-1;i>=(s.length()+1)/2;i--){
		second += s.substr(i,1);
	}
	if(first==second)
		return true;
	else
		return false;
}

string getResult(int n,int base){
	string result;
	string arr[] {"A","B","C","D","E","F","G","H","I","J","K"};
	while(n>0){
		result = ((n%base >= 10) ? arr[(n%base)-10] : to_string(n % base)) + result;
		n = n/base;
	}
	return result;
}

int main () {
   ifstream myfile ("dualpal.in");
    int n;
    int s;
    myfile >> n;
    myfile >> s;
    myfile.close();

    ofstream output("dualpal.out");
    
    int count = 0;
    int i = s+1;
    while(count<n){
    	int tempCount = 0;
    	for(int j=2;j<=10;j++){
    		if(isPalindrom(getResult(i,j)))
    			tempCount++;
    		if(tempCount>=2){
    			output << i << endl;
    			count++;
    			break;
    		}
    	}
    	i++;
    }
  output.close();
  return 0;
}



