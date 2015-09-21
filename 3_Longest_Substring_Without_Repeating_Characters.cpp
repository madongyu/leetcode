#include <memory.h>
#include <string>
using std::string;
/*
最长不重复子串 的长度
'aaa' => a 1
'abcabcbb' => abc 3
'dvdf' => vdf 3

*/
int lengthOfLongestSubstring(string s) {
	int best_result = 0;
	int cur_reslut = 0;
	int hash[128];
	memset(hash, 0, sizeof(hash));
	for (int i = 0; i < s.size(); i++) {
		if (hash[s[i]]) {
			if (cur_reslut > best_result) {
				best_result = cur_reslut;
			}
			cur_reslut = 0;
			i = hash[s[i]] - 1;
			memset(hash, 0, sizeof(hash));
		}
		else {
			hash[s[i]] = i + 1;
			cur_reslut++;
		}
	}
	if (cur_reslut > best_result) {
		best_result = cur_reslut;
	}
	return best_result;
}