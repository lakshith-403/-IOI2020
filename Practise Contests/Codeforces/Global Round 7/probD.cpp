#include <bits/stdc++.h>

using namespace std;

// bool table[(int)pow(10,6)][(int)pow(10,6)];

string longestPalSubstr(string str)
{
    int n = str.length();
    bool table[n][n];
    // cout << str << endl;
    memset(table, 0, sizeof(table));

    for (int i = 0; i < n; ++i)
        table[i][i] = true;
    for (int i = 0; i < n-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            table[i][i+1] = true;
        }
    }
    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n-k+1 ; ++i)
        {
            int j = i + k - 1;
            if (table[i+1][j-1] && str[i] == str[j])
            {
                table[i][j] = true;
            }
        }
    }
    int MAX = 0;
    int i;

    for(i=n-1;i>=0;i--){
      if(table[0][i])break;
    }
    i++;
    MAX = i;
    for(i=0;i<n;i++){
      if(table[i][n-1])break;
    }
     i = n-i;
  //   cout << endl;
  //   for(int a=0;a<n;a++){
  //   for(int b=0;b<n;b++)
  //     cout << table[a][b] << "\t";
  //   cout << endl;
  // }
  //   cout << endl;
  //  // cout << i << endl;
    if(i>MAX)
      return str.substr(str.length()-i,i);
    return str.substr(0,MAX);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    string ans;
    int i;
    for(i=0;i<s.length()/2;i++){
      if(s[i]!=s[s.length()-1-i])break;
      ans += s[i];
    }
    int mid = i;
    for(i=0;i<ans.length();i++)
      cout << ans[i];
    cout << longestPalSubstr(s.substr(i,s.length()-(2*mid)));
    for(i=ans.size()-1;i>=0;i--)
      cout << ans[i];
    cout << endl;
  }
}
