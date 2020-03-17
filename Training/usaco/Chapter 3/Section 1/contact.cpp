/*
ID: lakshit4
PROG: contact
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
vector<pair<string,int>> freq(10000,pair<string,int>());
int A,B,N;
string S;

int getBinary(string s){
  int val = 0;
  for(int i=0;i<s.length();i++){
     val += (s[i]-'0')*(int)pow(2,s.length()-i-1);
  }
  return val;
}

bool compare(pair<string,int> p1 , pair<string,int> p2){
  if(p1.second == p2.second){
    if(p1.first.length()==p2.first.length())
      return getBinary(p1.first) < getBinary(p2.first);
    return p1.first.length() < p2.first.length();
  }
  return p1.second > p2.second;
}

void updfreq(string s){
  // cout << s << endl;
  s = "1"+s;
  int val = 0;
  for(int i=0;i<s.length();i++){
     val += (s[i]-'0')*(int)pow(2,s.length()-i-1);
  }
  // cout << "val: " << val  << endl;
  freq.at(val) = {s.substr(1,s.length()-1),freq.at(val).second+1};
}

int main(){
  ifstream in("contact.in");
  ofstream out("contact.out");
  in >> A >> B >> N;
  int lim = 2*(int)pow(10,5);
  while(lim--){
    string s;
    in >> s;
    S+=s;
  }
  cout << " len: " << S.length() << endl;
  for(int i=A;i<=B;i++){
    for(int j=0;j<=S.length()-i;j++){
        if(j+i>S.length())break;
        updfreq(S.substr(j,i));
    }
  }
  cout << "++++++++" << endl;
  sort(freq.begin(),freq.end(),compare);
  vector<vector<pair<string,int>>> ans;
  int i=0;
  int pos = 0;
  int prev = -1;
  // cout <<"shid " << endl;
  while(i<=N){
    if(freq.size()<=pos)
      break;
    if(freq.at(pos).second==0)break;
    // cout << pos << " " << i << " " << N << endl;
    if(freq.at(pos).second==prev){
      ans.at(ans.size()-1).push_back(freq.at(pos));
      pos++;
    }else{
      if(i==N)
        break;
      vector<pair<string,int>> vec;
      vec.push_back(freq.at(pos));
      ans.push_back(vec);
      prev=freq.at(pos).second;
      pos++;
      i++;
    }
  }
  // cout << "blah" << endl;
  for(vector<pair<string,int>> vec : ans){
    out << vec.at(0).second << endl;
    string ss = "";
    for(int i=0;i<vec.size();i++)
      if(i%6==5)
        ss+=vec.at(i).first + "\n";
      else
        ss+=vec.at(i).first + " ";

    if(ss[ss.length()-1]==' ')
    out << ss.substr(0,ss.size()-1) << endl;
    else
    out << ss;
  }
}
