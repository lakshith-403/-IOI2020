#include <bits/stdc++.h>

using namespace std;
//to store the size of each list
int sizes[100001];

int main(){
  int n;
  cin >> n;
  //MAX keep the maximum length of lists
  int MAX = INT_MIN;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    sizes[i] = a;
    MAX = max(MAX,a);
  }
  /*
  Goal: Lists have to be of the same size without changing the initial sum value
  Strategy: We take the max size as the common size
  Therefore we don't need to change the list with max length
  Size of every other list is less than the max value. So we fill the remaining size with 0's.
  Size becomes the same And the su won't change bacause we are adding zeros.
  */
  //MAX is the preffered commmon size
  cout << MAX << "\n";
  //we need to print the starting positions
  //let the common size = s
  //positions are 0 s s+s s+s+s etc
  //this loop print those values
  for(int i=0;i<n*MAX;i+=MAX)
    cout << i << " ";
    cout << endl;
  
  //This loop print each list
  for(int i=0;i<n;i++){
    //first print the elements of the list
    for(int j=0;j<sizes[i];j++){
      int a;
      cin >> a;
      cout << a << " ";
    }
    //if the size is less than S(common size)
    //make it to the common size by printing zeros
    for(int j=0;j<MAX-sizes[i];j++){
      cout << 0 << " ";
    }
  }
}
