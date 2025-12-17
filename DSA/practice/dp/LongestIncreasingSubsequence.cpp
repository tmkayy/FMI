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
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n, 1);
		for (size_t i = 1; i < n; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[i], 1 + dp[j]);
				}
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};