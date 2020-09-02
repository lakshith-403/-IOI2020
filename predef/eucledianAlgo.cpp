/*
Eucledian Algorithm for Greatest Common Divisor (and Least Common Multiple)
Complexity - > O(log min(a,b))
*/


#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    while(b){
        a %= b;
        swap(a,b);
    }
    return a;
}

int lcm(int a,int b){
    return a / gcd(a,b) * b;
}