#include <vector>
#include <map>
using std::vector;
using std::map;
vector<int> towSum(vector<int> &nums, int target) {
	vector<int> result;
	map<int, int> table;
	for (int i = 0; i < nums.size(); i++) {
		if (!table.count(nums[i])) {
			table[nums[i]] = i;
		}
		if (table.count(target - nums[i])) {
			int n = table[target - nums[i]];
			if (n < i) {
				result.push_back(n + 1);
				result.push_back(i + 1);
				return result;

			}
		}
	}
	return result;
}
