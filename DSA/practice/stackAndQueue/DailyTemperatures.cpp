#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> res(temperatures.size());
		stack<int> indexes;
		for (size_t i = 0; i < temperatures.size(); i++)
		{
			while (!indexes.empty()&&temperatures[i]>temperatures[indexes.top()])
			{
				int prevIndex = indexes.top();
				indexes.pop();
				res[prevIndex] = i - prevIndex;
			}
			indexes.push(i);
		}
		
		return res;
	}
};