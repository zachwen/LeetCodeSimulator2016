#include "leetcode.h"

class LFUCache {
    int c;
    int lf = 0; // least frequently used number
    unordered_map<int, pair<int, int> > kv; // key -> [value freq]
    unordered_map<int, list<int>::iterator> ki; // key -> iterator
    unordered_map<int, list<int> > fk; // freq -> [key] sorted by access time
public:
    LFUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if (kv.find(key) != kv.end()) {
            fk[kv[key].second].erase(ki[key]);
            if (fk.find(kv[key].second + 1) == fk.end())
                fk[kv[key].second + 1] = list<int>();
            fk[kv[key].second + 1].push_back(key);
            ki[key] = --fk[kv[key].second + 1].end();
            if (lf == kv[key].second && fk[kv[key].second].empty())
                lf++;
            kv[key].second++;
            return kv[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (c <= 0)
            return;
        pair<int, int> p(value, 0);
        if (kv.size() >= c) {
            kv.erase(fk[lf].front());
            ki.erase(fk[lf].front());
            fk[lf].pop_front();
            kv[key] = p;
        }
        else {
            kv[key] = p;
        }
        if (fk.find(0) == fk.end())
            fk[0] = list<int>();
        fk[0].push_back(key);
        ki[key] = --fk[0].end();
        lf = 0;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 int main() {
    LFUCache obj(2);
    int param_1 = obj.get(1);
    obj.put(1, 2);
}
