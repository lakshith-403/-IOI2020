/*
 ID: lakshit4
 LANG: C++
 TASK: hamming
*/
#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;


int dist(int x, int y)
{
    bitset<8> b(x^y);
    return b.count();
}

int main(int argc, const char * argv[])
{
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    int n,b,Li;
    vector<int> ans;
    ans.push_back(0);
    scanf("%d %d %d",&n,&b,&Li);
    for(int i=0;i!=1<<b;i++)
    {
        bool y=true;
        for(int x:ans)
            y=y&&(dist(i,x)>=Li);
        if(y) ans.push_back(i);
        if(ans.size()==n) break;
    }
    for(int i=0;i<ans.size();i++)
    {
        if(i&&(i%10==0)) printf("\n");
        else if(i) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}