#include <bits/stdc++.h>

using namespace std;

double def[] {0.0,0.5,1.0,1.5,2.0};
vector<vector<double>> space;
int n;

void f(vector<double> vec){
    if(vec.size()==n){
        space.push_back(vec);
        return;
    }
    for(int i=1;i<=4;i++){
        vec.push_back(def[i]);
        f(vec);
        vec.erase(vec.begin()+vec.size()-1);
    }
    for(int i=1;i<=4;i++){
        vec.push_back(def[i]*-1);
        f(vec);
        vec.erase(vec.begin()+vec.size()-1);
    }
    vec.push_back(0.0);
    f(vec);
}

int g[6][6];

int main(){
    int m;
    cin >> n >> m;
    vector<double> vec;
    bool flag = false;
    f(vec);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        if(g[a][b]!=0 && g[a][b]!=c){flag = true;}
        g[a][b] = c;
        g[b][a] = c;
    }
    if(flag){
        cout << "NO" << "\n";
        return 0;
    }
    int MIN = INT_MAX;
    vector<double> ans;
    for(vector<double> v:space){
        int i;
        for(i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==0)continue;
                if(g[i][j]==v[i]+v[j])continue;
                i=n+100;
                break;
            }
        }
        if(i==n){
            // cout << "YES" << "\n";
            // for(double x:v)
            // cout << x << " ";
            // cout << "\n";
            double s = 0;
            for(double x:v)s+=x*(x<0?-1:1);
            if(s>MIN)continue;
            MIN = s;
            ans = v;
        }
    }
    if(MIN!=INT_MAX){
        cout << "YES" << "\n";
            for(double x:ans)
            cout << x << " ";
            cout << "\n";
            return 0;
    }
    cout << "NO" << "\n"; 
    // cout << space.size() << "\n";
}