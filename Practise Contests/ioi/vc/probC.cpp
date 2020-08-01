#include "combo.h"


std::std::string l;


std::string guess_sequence(int n){
    int start = ' ';
    std::string r = "";
    if(press("A")){
        r += 'A';
        l = "BXY";
    }else if(press("B")){
        r += 'B';
        l = "AXY";
    }else if(press("X")){
        r += 'X';
        l = "BAY";
    }else{
        r += 'Y';
        l = "ABX";
    }
    int k = 1;
    for(int i=1;i<n-1;i++){
        std::string a,b,c,d;
        a = r + l[0]+l[0];
        b = r + l[0]+l[1];
        c = r + l[0]+l[2];
        d = r + l[1];
        int p = press(a+b+c+d);
        p -= k;
        if(p==0){
            r += l[2];
        }else if(p==1){
            r += l[1];
        }else
        {
            r += l[0];
        }
        k++;
    }
    for(int i=0;i<3;i++){
        if(press(r+l[i])==n){
            r += l[i];
            break;
        }
    }
    return r;
}