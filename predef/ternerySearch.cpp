/*
Ternery search can be used to find the minimum or maximum of a unimodal graph.
Complexity -> O(log n)
*/

#include <bits/stdc++.h>

using namespace std;

double f(double x){
    return x;
}
int f(int x){
    return x;
}

//ternery search on a continious graph of f(x) for the maximum
double ternerySearch(double l,double r){
    double eps = 1e9-9; // errror limit
    while(r-l>eps){
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;
        double f1 = f(m1),f2 = f(m2); //evaluate the function at given points
        if(f1<f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);
}
//ternery search on a descrete graph of f(x) for the maximum
int ternerySearch(int l,int r){
    while(r-l>=3){
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;
        int f1 = f(m1),f2 = f(m2); //evaluate the function
        if(f1<f2)
            l = m1;
        else
            r = m2;
    }
    return max(f(l),max(f(l+1),f(r)));
}