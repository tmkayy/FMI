#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Node {
	int row;
	int col;
	int cost;

	Node(int r, int c, int cst) : row(r), col(c), cost(cst) {}

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

class Solution {
public:
	int minimumObstacles(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
		dist[0][0] = 0;
		priority_queue<Node, vector<Node>, greater<Node>> pq;
		pq.push(Node(0, 0, 0));
		vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
		while (!pq.empty())
		{
			Node curr = pq.top();
			pq.pop();
			int r = curr.row;
			int c = curr.col;
			int cost = curr.cost;

			if (cost > dist[r][c])
				continue;

			for (auto& dir : directions) {
				int nr = r + dir.first;
				int nc = c + dir.second;

				if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
					int newCost = cost + grid[nr][nc];
					if (newCost < dist[nr][nc]) {
						dist[nr][nc] = newCost;
						pq.push(Node(nr, nc, newCost));
					}
				}
			}
		}
		return dist[m - 1][n - 1];
	}
};