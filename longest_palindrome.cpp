#include "leetcode.h"

// leetcode 409
int longestPalindrome(string s) {
	int n = s.size();
	int i = 0;
	int index = 0, maxLength = 0;
	while (i < n) {
		int j = i, k = i;
		while (k + 1 < n && s[k] == s[k + 1])
			++k;
		i = k + 1;
		while (j - 1 >= 0 && k + 1 < n && s[j - 1] == s[k + 1]) {
			--j;
			++k;
		}
		if (k - j + 1 > maxLength) {
			index = j;
			maxLength = k - j + 1;
		}
	}
	return maxLength;
}