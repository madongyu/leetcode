#include <iostream>
#include <string>
using std::string;
string longestPalindrome(string s) {
	int len = s.size();
	if (len == 0) {
		return "";
	}
	bool **dp = new bool*[len];
	for (int i = 0; i < len; i++) {
		dp[i] = new bool[i + 2];
		for (int j = 0; j < i; j++) {
			dp[i][j] = 0;
		}
		dp[i][i] = true;
		dp[i][i + 1] = true;
	}
	int re_len = 1;
	int re_begin = 0;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < i; j++) {
			if (s[j] == s[i]) {
				dp[i][j] = dp[i - 1][j + 1];
				if (dp[i][j] && re_len < i - j + 1) {
					re_len = i - j + 1;
					re_begin = j;
				}
			}
		}
	}
	for (int i = 0; i < len; i++) {
		delete dp[i];
	}
	delete dp;
	return s.substr(re_begin, re_len);
}