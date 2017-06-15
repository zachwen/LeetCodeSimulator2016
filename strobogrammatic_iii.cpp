#include "leetcode.h"
#include "assert.h"

// leetcode 248

// rather naive solution based on strobogrammatic ii
// waste of space
class Solution0 {
public:
    bool intGreaterEqual(string a, string b) {
        int n = a.size(), m = b.size();
        if (n < m)
            return 0;
        if (n > m)
            return 1;
        return (a.compare(b) >= 0);
    }
    bool intLessEqual(string a, string b) {
        int n = a.size(), m = b.size();
        if (n > m)
            return 0;
        if (n < m)
            return 1;
        return (a.compare(b) <= 0);
    }

    int strobogrammaticInRange(string low, string high) {
        int lowDigits = low.size();
        int highDigits = high.size();
        
        vector<vector<string>> sg(2, vector<string>());
        sg[0] = {""};
        sg[1] = {"0", "1", "8"};
        vector<vector<string>> sg0(2, vector<string>());
        sg0[0] = {""};
        sg0[1] = {"0", "1", "8"};
        
        for (int i = 2; i <= highDigits; ++i) {
            sg0.push_back(vector<string>());
            sg.push_back(vector<string>());
            for (string s : sg0[i - 2]) {
                sg0[i].push_back("0" + s + "0");
                sg0[i].push_back("1" + s + "1");
                sg0[i].push_back("6" + s + "9");
                sg0[i].push_back("8" + s + "8");
                sg0[i].push_back("9" + s + "6");
                sg[i].push_back("1" + s + "1");
                sg[i].push_back("6" + s + "9");
                sg[i].push_back("8" + s + "8");
                sg[i].push_back("9" + s + "6");
            }
        }
        int count = 0;
        for (int i = lowDigits + 1; i < highDigits; ++i)
            count += sg[i].size();
        for (string s : sg[lowDigits]) {
            if (intGreaterEqual(s, low) && intLessEqual(s, high))
                count++;
        }
        if (lowDigits == highDigits)
            return count;
        for (string s : sg[highDigits]) {
            if (intGreaterEqual(s, low) && intLessEqual(s, high))
                count++;
        }
        return count;
    }
};

// better dfs solution
class Solution1 {
    unordered_map<char, char> m;
    string low, high;
public:
    bool intGreaterEqual(string a, string b) {
        int n = a.size(), m = b.size();
        if (n < m)
            return 0;
        if (n > m)
            return 1;
        return (a.compare(b) >= 0);
    }
    
    bool intLessEqual(string a, string b) {
        int n = a.size(), m = b.size();
        if (n > m)
            return 0;
        if (n < m)
            return 1;
        return (a.compare(b) <= 0);
    }

    int strobogrammaticInRange(string low, string high) {
        m['0'] = '0';
        m['1'] = '1';
        m['6'] = '9';
        m['8'] = '8';
        m['9'] = '6';
        this->low = low;
        this->high = high;
        
        int lowDigits = low.size();
        int highDigits = high.size();
        int count = 0;
        for (int i = lowDigits; i <= highDigits; ++i) {
            string sg;
            sg.resize(i);
            strobogrammatic(count, sg, 0, i - 1);
        }
        return count;
    }
    
    void strobogrammatic(int &count, string sg, int s, int e) {
        if (s > e) {
            if (intGreaterEqual(sg, low) && intLessEqual(sg, high))
                ++count;
            return;
        }
        for (auto entry : m) {
            sg[s] = entry.first;
            sg[e] = entry.second;
            if (entry.first == '0') {
                if ((s == 0 && e == 0) || s > 0)
                    strobogrammatic(count, sg, s + 1, e - 1);
            }
            else if (entry.first == entry.second || s != e) {
                strobogrammatic(count, sg, s + 1, e - 1);
            }
        }
    }
};