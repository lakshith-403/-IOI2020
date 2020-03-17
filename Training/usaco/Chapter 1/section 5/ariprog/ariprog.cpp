/*
 ID: lakshit4
 LANG: C++
 TASK: ariprog
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

bool bene[125001] = {false};
set<int> list;

bool judge(int a,int b,int n)
{
    int i;
    for (i = 0;i < n;i++)
        if (bene[a+b*i] == false)
            return false;
    return true;
}

struct Pare
{
    int a;
    int b;
};

Pare ans[10000]={{0,0}};
int anscount = 0;

int cmp( const Pare &a, const Pare &b ){
    if (a.b < b.b)
        return 1;
    else if (a.b == b.b)
        return a.a < b.a;
    else
        return 0;
}

int main()
{
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    int N, M;
    fin >> N >> M;
    int i,j;
    for (i = 0;i <= M;i++)
        for (j = 0;j <= M;j++)
        {
            int num = i*i+j*j;
            bene[num] = true;
            list.insert(num);
        }
    int maxdis = *max_element(list.begin(),list.end());
    set<int>::iterator i1,i2;
    for (i1 = list.begin(); i1 != list.end(); i1++)
        for (i2 = i1; i2 != list.end(); i2++)
        {
            int a = *i1;
            int b = *i2 - *i1;
            if (a+b*(N-1) > maxdis)
                break;
            if (b == 0)
                continue;
            else
            {
                if (judge(a,b,N))
                {
                    ans[anscount].a = a;
                    ans[anscount].b = b;
                    anscount++;
                }
            }
        }
    if (anscount == 0)
    {
        fout << "NONE" << endl;
        return 0;
    }
    sort(ans,ans+anscount,cmp);
    for (i = 0;i < anscount;i++)
        fout << ans[i].a << " " << ans[i].b << endl;

    return 0;
}