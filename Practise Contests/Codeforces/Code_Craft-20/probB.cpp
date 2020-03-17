#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      string s;
      cin >> s;
      int MIN = INT_MAX;
      s =  s;
      for(int k=1;k<=s.length();k++){
        cout << "length: " << k << endl;
        string minS = s.substr(1,k);
        for(int i=s.length()-1;i>=0;i--){
          string sub;
          if(i+k>=s.length()){
            sub = s.substr(i,s.length()-i);
            if((s.length()-i) % 2 ==0){
              string temp = s;
              reverse(s.begin(),s.begin()+i-1);
              sub += temp.substr(0,k-(s.length()-i));
            }else{
              string temp = s;
              sub += temp.substr(0,k-(s.length()-i));
            }
          }else
            sub = s.substr(i,k);

          cout << sub << " : " << minS <<  endl;
          if(sub <= minS){
             MIN = min(i,MIN);
             minS = sub;
             cout << ">" << MIN << endl;
         }
        }
      }
      cout << "++++++++++  " << MIN+1 << endl;
    }
}
