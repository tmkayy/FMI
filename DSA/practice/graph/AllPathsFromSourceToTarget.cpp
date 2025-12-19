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
	void dfs(vector<vector<int>>& graph, vector<vector<int>>& allPaths, vector<int>& currPath, int target, int currNode) {
		currPath.push_back(currNode);
		if (currNode == target) {
			allPaths.push_back(currPath);
		}
		else {
			for (auto& neighbor : graph[currNode])
				dfs(graph, allPaths, currPath, target, neighbor);
		}
		currPath.pop_back();
	}

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> allPaths;
		vector<int> currPath;
		int target = graph.size() - 1;
		dfs(graph, allPaths, currPath, target, 0);
		return allPaths;
	}
};