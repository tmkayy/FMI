#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> res;
		stack<int> as;
		for (int a : asteroids) {
			while (!as.empty() && a < 0 && as.top()>0)
			{
				if (abs(a) > as.top())
					as.pop();
				else if (abs(a) == as.top()) {
					as.pop();
					a = 0;
				}
				else {
					a = 0;
				}
			}
			if (a != 0)
				as.push(a);
		}
		while (!as.empty())
		{
			res.insert(res.begin(), as.top());
			as.pop();
		}
		return res;
	}
};