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
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<vector<pair<int, int>>> graph(n + 1);
		for (const auto& time : times) {
			int u = time[0], v = time[1], w = time[2];
			graph[u].push_back({ v, w });
		}

		vector<int> dist(n + 1, INT_MAX);
		dist[k] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, k });
		while (!pq.empty())
		{
			int currDist = pq.top().first;
			int currNode = pq.top().second;
			pq.pop();
			if (currDist > dist[currNode])
				continue;
			for (auto& neighborAndWeight : graph[currNode]) {
				int newDist = currDist + neighborAndWeight.second;
				if (newDist < dist[neighborAndWeight.first]) {
					dist[neighborAndWeight.first] = newDist;
					pq.push({ newDist, neighborAndWeight.first });
				}
			}
		}

		int maxTime = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] == INT_MAX) {
				return -1;
			}
			maxTime = max(maxTime, dist[i]);
		}

		return maxTime;
	}
};