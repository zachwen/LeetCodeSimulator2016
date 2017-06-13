#include "leetcode.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        // map: num -> freq
        for (int n : nums) {
            if (m.count(n)) ++m[n];
            else m[n] = 1;
        }
        
        // bucket: freq -> [num]
        vector<vector<int>> bucket(nums.size() + 1, vector<int>());
        for (auto entry : m) {
            bucket[entry.second].push_back(entry.first);
        }
        
        vector<int> r;
        for (int i = bucket.size() - 1; i >= 0; --i)
            for (int n : bucket[i]) {
                if (!k) return r;
                r.push_back(n);
                --k;
            }
        return r;
    }
};

int main() {
    Solution s;
    std::vector<int> v(1, 1);
    s.topKFrequent(v, 1);
}
