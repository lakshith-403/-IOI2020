/*
 ID: lakshit4
 LANG: C++
 TASK: sprime
*/

#include <stdio.h>
#include <math.h>
FILE *in,*out;
int isprime(int a){
    int i;
    if (a==1) return 0;
    for (i=2;i<=sqrt(a);i++) if (a%i==0) return 0;
    return 1;
}
int find(int digit,int num,int n){
    int i;
    if (digit>n) fprintf(out,"%d\n",num);
    else for (i=1;i<=9;i+=2) if (isprime(num*10+i)) find(digit+1,num*10+i,n);
}
int main(){
    in=fopen("sprime.in","r");
    out=fopen("sprime.out","w");
    int i,n;
    fscanf(in,"%d",&n);
    find(2,2,n);
    find(1,0,n);
    return 0;
}