#include <string>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		queue<int> temp;
		double maxavg = INT_MIN;
		double sum = 0;
		for (int num : nums) {
			sum += num;
			temp.push(num);
			if (temp.size() == k) {
				if (maxavg < sum / k)
					maxavg = sum / k;
				sum -= temp.front();
				temp.pop();
			}
		}
		return maxavg;
	}
};