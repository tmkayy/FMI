#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];

		vector<int> dp(nums.size());
		dp[0] = nums[0];
		dp[1] = max(dp[0], nums[1]);

		for (int i = 2; i < dp.size(); i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		return dp[dp.size() - 1];
	}
};