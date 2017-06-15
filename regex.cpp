#include "leetcode.h"

// leetcode 10
bool regex(string s, string p) {
	int n = s.size();
	int m = p.size();
	vector<vector<bool> > dp(n + 1, vector<bool>(m + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i < m; i += 2) {
		if (p[i] == '*') dp[0][i + 1] = 1;
		else break;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (s[i] == p[j] || p[j] == '.')
				dp[i + 1][j + 1] = dp[i][j];
			else if (p[j] == '*') {
				if (p[j - 1] == s[i] || p[j - 1] == '.')
					dp[i + 1][j + 1] = dp[i + 1][j - 1] || dp[i][j - 1] || dp[i][j + 1];
				else
					dp[i + 1][j + 1] = dp[i + 1][j - 1];
			}
		}
	return dp[n][m];
}