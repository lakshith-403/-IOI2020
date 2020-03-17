/*  
ID: lakshit4  
PROB: ttwo  
LANG: C++  
*/   
#include <iostream>   
using namespace std;   
   
const int dx[4]={-1,0,1,0};   
const int dy[5]={0,1,0,-1};   
char map[12][12];   
int x[3],y[3],d[3];   
int main()   
{   
    freopen("ttwo.in","r",stdin);   
    // freopen("ttwo.out","w",stdout);   
    int i,j;   
    for (i=0; i<=11; i++)   
        for (j=0; j<=11; j++) map[i][j]='*';   
    for (i=1; i<=10; i++)   
        for (j=1; j<=10; j++)   
        {   
            cin>>map[i][j];   
            if (map[i][j]=='F') { x[1]=i; y[1]=j; }   
            if (map[i][j]=='C') { x[2]=i; y[2]=j; }   
        }   
    d[1]=0; d[2]=0;   
    for (i=1; i<=300; i++)   
    {   
        for (j=1; j<=2; j++)   
        {   
            if (map[x[j]+dx[d[j]]][y[j]+dy[d[j]]]!='*')   
            {   
                x[j]+=dx[d[j]]; y[j]+=dy[d[j]];   
            }   
            else d[j]=(d[j]+1)%4;   
            //cout<<x[j]<<" "<<y[j]<<"   ";   
        }  

        cout << "________________" << endl;
        for(int i=0;i<=11;i++){
            for(int j=0;j<=11;j++){
                if(x[1]==i && y[1]==j) cout << "C";
                else if(x[2]==i && y[2]==j) cout << "F"; 
                else if(map[i][j]=='*') cout << "#";
                else cout << " ";
            }
            cout << endl;
        }
        cout << x[1] << " " << y[1] << " " <<  endl;
        cout << x[2] << " " << y[2] << " " << endl;

        //cout<<endl;   
        if (x[1]==x[2] && y[1]==y[2])   
        {   
            cout<<i<<endl;   
            return 0;   
        }   
    }   
    cout<<0<<endl;   
} 