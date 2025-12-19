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
	static constexpr int RED = 0;
	static constexpr int BLUE = 1;
	static constexpr int START = -1;

	vector<vector<int>> buildGraph(int n, vector<vector<int>>& edges) {
		vector<vector<int>> graph(n);
		for (auto& e : edges)
			graph[e[0]].push_back(e[1]);
		return graph;
	}

	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
		auto redGraph = buildGraph(n, redEdges);
		auto blueGraph = buildGraph(n, blueEdges);

		vector<bool> visitedRed(n, false);
		vector<bool> visitedBlue(n, false);
		vector<int> answers(n, -1);

		int level = 0;
		queue<pair<int, int>> q;
		q.push({ 0, START });
		while (!q.empty())
		{
			int lvlSize = q.size();
			for (size_t i = 0; i < lvlSize; i++)
			{
				auto p = q.front(); q.pop();
				int node = p.first;
				int prevColor = p.second;
				if (answers[node] == -1)
					answers[node] = level;
				if (prevColor != BLUE) {
					for (auto& el : blueGraph[node])
					{
						if (!visitedBlue[el]) {
							visitedBlue[el] = true;
							q.push({ el, BLUE });
						}
					}
				}
				if (prevColor != RED) {
					for (auto& el : redGraph[node])
					{
						if (!visitedRed[el]) {
							visitedRed[el] = true;
							q.push({ el, RED });
						}
					}
				}
			}
			level++;
		}
		return answers;
	}
};