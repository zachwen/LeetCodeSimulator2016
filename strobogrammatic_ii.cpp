#include "leetcode.h"

// leetcode 247
vector<string> strobogrammatic_ii(int n) {
	vector<vector<string>> sg(2, vector<string>());
	sg[0] = {""};
	sg[1] = {"0", "1", "8"};
	if (n < 2)
		return sg[n];
	for (int i = 2; i <= n; ++i) {
		sg.push_back(vector<string>());
		for (string s : sg[i - 2]) {
			if (i != n)
				sg[i].push_back("0" + s + "0");
			sg[i].push_back("1" + s + "1");
			sg[i].push_back("6" + s + "9");
			sg[i].push_back("8" + s + "8");
			sg[i].push_back("9" + s + "6");
		}
	}
	return sg[n];
}