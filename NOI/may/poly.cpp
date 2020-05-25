#include <bits/stdc++.h> 
#define llu long long int 
using namespace std; 
  
struct Point { 
    llu x, y; 
    bool operator<(Point p) { 
        return x < p.x || (x == p.x && y < p.y); 
    } 
}; 

int orientation(Point p, Point q, Point r) { 
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0; 
    return (val > 0)? 1: 2; 
} 

llu cross_product(Point O, Point A, Point B) { 
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x); 
} 
vector<Point> convex_hull(vector<Point> A) { 
    int n = A.size(), k = 0; 
    if (n <= 3) 
        return A; 
    vector<Point> ans(2 * n); 
    sort(A.begin(), A.end()); 
    for (int i = 0; i < n; ++i) { 
        while (k >= 2 && cross_product(ans[k - 2],ans[k - 1], A[i]) <= 0) k--; 
        ans[k++] = A[i]; 
    } 
    for (size_t i = n - 1, t = k + 1; i > 0; --i) { 
        while (k >= t && cross_product(ans[k - 2], ans[k - 1], A[i - 1]) <= 0) k--; 
        ans[k++] = A[i - 1]; 
    } 
    ans.resize(k - 1); 
    return ans; 
} 
int main() { 
    vector<Point> points; 
    int n;
    cin >> n;
    while(n--){
      int a,b;
      cin >> a >> b;
      points.push_back({a,b});
    }
    vector<Point> hull = convex_hull(points);
    int r = hull.size();
    for(int i=1;i<hull.size()-1;i++)
      if(orientation(hull.at(i-1),hull.at(i),hull.at(i+1))==0)
        r--;
    cout << r << "\n";
    return 0; 
}
