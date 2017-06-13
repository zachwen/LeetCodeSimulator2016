#include "leetcode.h"

class DisjointSet {
public:
    int count = 0;
    vector<int> ds;
    DisjointSet(int n) {
        for (int i = 0; i < n; ++i)
            ds.push_back(i);
        count = n;
    }
    
    int findNumber(int n) {
        while (n != ds[n]) {
            ds[n] = ds[ds[n]];
            n = ds[n];
        }
        return n;
    }
    
    int unionNumbers(int a, int b) {
        int ua = findNumber(a);
        int ub = findNumber(b);
        if (ua == ub)
            return ua;
        ds[ub] = ua;
        --count;
        return ua;
    }
};

int friendCircle(vector < string > friends) {
    int n = friends.size();
    DisjointSet disjointSet(n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (friends[i][j] == '1')
                disjointSet.unionNumbers(i, j);
        }
    }
    
    return disjointSet.count;
}
