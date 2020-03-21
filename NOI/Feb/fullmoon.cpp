#include <bits/stdc++.h>

using namespace std;
long long M,D,N;
long long x[100];
long long Y1,M1,D1,Y2,M2,D2;
long long gcd;

long long GCD(long long a, long long b)
{
    if (a == 0)
        return b;
    return GCD(b % a, a);
}

long long findlcm(long long arr[], long long n)
{
    long long ans = arr[0];

    for (long long i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) /
                (GCD(arr[i], ans)));

    return ans;
}

long long main(){
  cin >> M >> D >> N;
  for(long long i=0;i<N;i++)
    cin >> x[i];
  cin >> Y1 >> M1 >> D1 >> Y2 >> M2 >> D2;
  gcd = findlcm(x,N);
    // cout << x[0] << " " << x[1] << " " << gcd << endl;
  long long dif = Y2 * M * D + M2 * D + D2 -  (Y1 * M * D + M1 * D + D1);
  if(dif%gcd==0){
    cout << "FULL MOON DAY" << endl;
    return 0;
  }
  cout << min(dif%gcd , gcd - (dif%gcd)) << endl;

}
