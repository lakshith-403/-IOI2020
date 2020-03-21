#include <bits/stdc++.h>

using namespace std;
int H,W,N;
//(M)(M+1)(N)(N+1)/4
int rotateLeft(){
  queue<int> q;
  for(int j=W-1;j>=0;j--)
    for(int i=0;i<H;i++)
      q.push(matrix[i][j]);

  int temp = W;
  W = H;
  H = temp;

  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++){
      matrix[i][j] = q.front();
      q.pop();
    }
}

int main(){
  cin >> H >> W >> N;
    for(int i=0;i<N;i++){
        char d;
        cin >> d;
        rotations += (d=='l')? 1 : -1;
    }
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)cin >> matrix[i][j];
    rotations %= 4;
    if(rotations<0){
        rotations *= -1;
        for(int i=0;i<rotations;i++)rotateLeft();}
    else
        for(int i=0;i<rotations;i++)rotateRight();

    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++)cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
