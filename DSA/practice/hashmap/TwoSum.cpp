#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		unordered_map<int, int> h; // value, indx
		for (size_t i = 0; i < nums.size(); i++)
		{
			int complement = target - nums[i];
			if (h.find(h[complement]) != h.end()) {
				res.push_back(h[complement]);
				res.push_back(h[nums[i]]);
				break;
			}
			h[nums[i]] = i;
		}
		return res;
	}
};