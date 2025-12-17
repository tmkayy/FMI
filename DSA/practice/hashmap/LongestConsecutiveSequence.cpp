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
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> s(nums.begin(), nums.end());
		int m = 0;
		for (int num : s) {
			if (s.find(num - 1) == s.end()) {
				int currLen = 1;
				int currNum = num + 1;
				while (s.find(currNum) != s.end())
				{
					currLen++;
					currNum++;
				}
				m = max(m, currLen);
			}
		}
		return m;
	}
};