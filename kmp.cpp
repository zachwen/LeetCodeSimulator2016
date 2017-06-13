#include "leetcode.h"

/*
	Compute the Longest Proper Prefix which is also the suffix for each pattern[0:(i + 1)]
	where i is in [0, m).
*/
vector<int> computeLPSArray(string pattern) {
	int m = pattern.size();
	std::vector<int> lps(m, 0);

	int i = 0, j = 1;

	while (j < m) {
		if (pattern[i] == pattern[j]) {
			lps[j++] = ++i;
		}
		else if (i > 0) {
			i = lps[i - 1];
		}
		else {
			++j;
		}
	}

	return lps;
}

vector<int> KMP(string s, string p) {
	vector<int> lps = computeLPSArray(p);
	int i = 0, j = 0;
	int m = p.size();
	int n = s.size();
	vector<int> occurrences;

	while (i < n) {
		if (s[i] == s[j]) {
			++i;
			++j;
		}
		if (j == m) {
			occurrences.push_back(i - m);
			j = lps[j - 1];
		}
		else if (i < n && s[i] != s[j]) {
			if (j > 0)
				j = lps[j - 1];
			else
				++i;
		}
	}

	return occurrences;

}