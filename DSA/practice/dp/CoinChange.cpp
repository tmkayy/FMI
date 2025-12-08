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
	vector<int> dp;

	int helper(vector<int>& coins, int amount) {
		if (amount < 0)
			return -1;

		if (amount == 0)
			return 0;

		if (dp[amount] != -2)
			return dp[amount];

		int least = INT_MAX;
		for (int coin : coins) {
			int sub = helper(coins, amount - coin);
			if (sub != -1) {
				least = min(least, 1 + sub);
			}
		}

		dp[amount] = (least != INT_MAX) ? least : -1;
		return dp[amount];
	}

	int coinChange(vector<int>& coins, int amount) {
		dp.resize(amount + 1, -2);
		dp[0] = 0;

		return helper(coins, amount);
	}
};