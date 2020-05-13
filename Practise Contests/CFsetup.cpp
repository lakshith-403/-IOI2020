#include <bits/stdc++.h>

using namespace std;

string alph = "ABCDEFGHIJKLM";


int main(){
  string s;
  cout << "Codeforces contest environment setup:\n";
  cout << "Single File: \n";
  getline(cin,s);
  if(s=="Y"||s=="y") goto single;
  cout << "First line: \t Contest name (string)\n"
          "Second line:\t No of problems (integer)" << endl;
  getline(cin,s);
  int n;
  cin >> n;
  while(n--){
    string let = "";
    let += alph[n];
    string filePath = "prob" + let + ".cpp";
    cout << filePath << endl;
    ofstream out(filePath.c_str());
    ifstream in("E:\\!Lakshith\\!IOI2020\\template.cpp");
    while(getline(in,s)){
      out << s << "\n";
    }
    out.flush();
    out.close();
  }
  single:
  cout << "Enter file name: \n";
  getline(cin,s);
  ifstream in("E:\\!Lakshith\\!IOI2020\\template.cpp");
  ofstream out(s.c_str());
  while(getline(in,s)){
      out << s << "\n";
  }
  out << endl;
}
