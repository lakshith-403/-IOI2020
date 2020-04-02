#include <bits/stdc++.h>

using namespace std;

int n,q,m;
int arr[2*(int)pow(10,5)+1];
bool mem[2*(int)pow(10,5)+1];

struct query{
  int t;
  int l;
  int r;
};

void shift(int a,int l,int r){
  int b;
  if(a!=r)b=a+1;
  else b=l;
  int temp = arr[b];
  arr[b] = arr[a];
  arr[a] = temp;
}

void reverse(int a,int l,int r){
  int b = l+(r-a);
  int temp = arr[b];
  arr[b] = arr[a];
  arr[a] = temp;
}

vector<query> Q;

int main(){
  // ios_bas::sync_With_stdio(false);
  // cin.tie(NULL);
  cin >> n >> q >> m;
  for(int i=1;i<=n;i++)
    cin >> arr[i];
  for(int i=0;i<q;i++){
    int t,l,r;
    cin >> t >> l >> r;
    query qr = {t,l,r};
    Q.push_back(qr);
  }
  for(int i=0;i<m;i++){
    // cout << "___________________" << "\n";
    int a;
    cin >> a;
    if(mem[a])continue;
    mem[a]=true;
    for(int k=Q.size()-1;k>=0;k--){
      query qr = Q.at(k);
      if(a>qr.r || a<qr.l)continue;
      if(qr.t==1)shift(a,qr.l,qr.r);
      else reverse(a,qr.l,qr.r);
      // for(int j=1;j<=n;j++)
        // cout << arr[j] << " ";
      // cout << "\n";
    }
    cout << arr[a] << "\n";
  }
}
