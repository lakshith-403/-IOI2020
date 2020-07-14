#include <bits/stdc++.h>
#include <conio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>

using namespace std;

string alph = "ABCDEFGHIJKLM";

void single(){
  string s;
  cout << "Enter file name: \n";
  getline(cin,s);
  ifstream in("E:\\!Lakshith\\-IOI2020\\template.cpp");
  ofstream out(s.c_str());
  while(getline(in,s)){
      out << s << "\n";
  }
  out << endl;
}

int main(){
  string s;
  cout << "Codeforces contest environment setup:\n";
  cout << "Single File: (Y/N)\n";
  getline(cin,s);
  if(s=="Y"||s=="y"){single();return 0;};
  cout << "Contest name:" << endl;
  getline(cin,s);
  string con = s;
  mkdir(con.c_str());
  cout << "No of problems:" << endl;
  int n;
  cin >> n;
  while(n--){
    string let = "";
    let += alph[n];
    string filePath = con + "\\prob" + let + ".cpp";
    cout << filePath << endl;
    ofstream out(filePath.c_str());
    ifstream in("E:\\!Lakshith\\-IOI2020\\template.cpp");
    while(getline(in,s)){
      out << s << "\n";
    }
    out.flush();
    out.close();
    string makepath = con + "\\makefile";
    ifstream make("makefile");
    ofstream makeout(makepath.c_str());
    while(getline(make,s))
      makeout << s << "\n";
    makeout.flush();
    makeout.close();
  }
  return 0;
}
