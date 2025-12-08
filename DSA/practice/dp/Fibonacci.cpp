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
	int dp[31]{};
	int fib(int n) {
		if (n == 0 || n == 1)
			return n;
		if (dp[n] != 0)
			return dp[n];
		return dp[n] = fib(n - 1) + fib(n - 2);
	}
};