/*

ID: lakshit4

LANG: C++

TASK: palsquare

 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool isPalindrom(string s){
	
	string first = s.substr(0,(s.length()-(s.length()%2==0?0:1))/2);
	string second;
	// if(s.length()%2==0)
	// 	s = "0" + s;
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
   ifstream myfile ("palsquare.in");
    int base;
    myfile >> base;
    myfile.close();

    ofstream output("palsquare.out");

  for(int i=1;i<300;i++){
  	int squared = i*i;
  	if(isPalindrom(getResult(squared,base)))
  		output << getResult(i,base) << " " << getResult(squared,base) << endl;
  }
  output.close();
  return 0;
}



