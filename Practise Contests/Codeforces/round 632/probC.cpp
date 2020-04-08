#include <bits/stdc++.h>

using namespace std;

long long arr[200001];
int n;

long long subArr() {
    unordered_set<long long> sumSet;
    long long count = 0;
    long long sum = 0;
    for (int i = 0 ; i < n ; i++)
    {
        sum += arr[i];
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            count++;

        sumSet.insert(sum);
    }
    return count;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  long long zero = subArr();
  long long rem = (long long)(n*(n+1)/2) - zero;
  cout << rem << "\n";
}
