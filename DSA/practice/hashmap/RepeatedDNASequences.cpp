#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string, int> h;
		vector<string> res;
		int size = s.size() - 10;
		for (int i = 0; i <= size; i++)
		{
			string str = s.substr(i, 10);
			h[str]++;
		}
		for (auto& p : h) {
			if (p.second > 1)
				res.push_back(p.first);
		}
		return res;
	}
};