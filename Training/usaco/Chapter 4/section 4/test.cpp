#include <bits/stdc++.h>
#include <chrono>

// #pragma GCC target("avx2")
// #pragma GCC optimization("03")
// #pragma GCC optimization("unroll-loops")

using namespace std::chrono;
using namespace std;


int main(){
    int a = 0;
    int n = 1e9;
    auto start = high_resolution_clock::now(); 
    for(int i=0;i<n;i++)a++;
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken: "
         << duration.count()/(double)1e6 << " seconds" << endl;
}