#include <bits/stdc++.h>
using namespace std;

struct fenwikTree {
    vector<int> bit;  // binary indexed tree
    int n;

    fenwikTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    fenwikTree(vector<int> a)
        : fenwikTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    //range query and point update
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }

    //range update and point query
    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    int point_query(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

};