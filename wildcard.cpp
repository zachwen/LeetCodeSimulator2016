#include "leetcode.h"

// leetcode 44
bool wildcard(string s, string p) {
	int n = s.size();
	int m = p.size();
	vector<vector<bool> > dp(n + 1, vector<bool>(m + 1, 0));
	dp[0][0] = 1;
	for (int i = 0; i < m; ++i) {
		if (p[i] == '*') dp[0][i + 1] = 1;
		else break;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (s[i] == p[j] || p[j] == '?')
				dp[i + 1][j + 1] = dp[i][j];
			else if (p[j] == '*')
				dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1];
		}
	return dp[n][m];
}