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
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> g(numCourses);

		for (auto& edge : prerequisites) {
			g[edge[1]].push_back(edge[0]);
		}
		vector<int> res;
		vector<bool> alreadyChecked(numCourses, false), currentVisitedPath(numCourses, false);

		for (int i = 0; i < numCourses; i++) {
			if (!alreadyChecked[i] && hasCycle(g, alreadyChecked, currentVisitedPath, res, i))
				return {};
		}

		reverse(res.begin(), res.end());
		return res;
	}

	bool hasCycle(const vector<vector<int>>& g, vector<bool>& alreadyChecked, vector<bool>& currentVisitedPath, vector<int>& res, int node) {
		if (currentVisitedPath[node])
			return true;
		if (alreadyChecked[node])
			return false;

		alreadyChecked[node] = true;
		currentVisitedPath[node] = true;
		for (auto& neighbor : g[node])
		{
			if (hasCycle(g, alreadyChecked, currentVisitedPath, res, neighbor))
				return true;
		}
		currentVisitedPath[node] = false;
		res.push_back(node);
		return false;
	}
};