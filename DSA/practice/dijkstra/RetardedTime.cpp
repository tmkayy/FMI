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
	int minimumTime(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		if (grid[0][1] > 1 && grid[1][0] > 1) {
			return -1;
		}
		vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
		dist[0][0] = 0;

		priority_queue<Node, vector<Node>, greater<Node>> pq;
		pq.push(Node(0, 0, 0));

		vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

		while (!pq.empty()) {
			Node curr = pq.top(); pq.pop();
			int r = curr.row;
			int c = curr.col;
			int time = curr.cost;

			if (time > dist[r][c])
				continue;

			if (r == m - 1 && c == n - 1) {
				return time;
			}

			for (auto& dir : directions) {
				int nr = r + dir.first;
				int nc = c + dir.second;

				if (nr < 0 || nr >= m || nc < 0 || nc >= n)
					continue;

				int requiredTime = grid[nr][nc];
				int newTime;
				if (time + 1 >= requiredTime) {
					newTime = time + 1;
				}
				else {
					int diff = requiredTime - time;
					if (diff % 2 == 0) {
						newTime = requiredTime + 1;
					}
					else {
						newTime = requiredTime;
					}
				}
				if (newTime < dist[nr][nc]) {
					dist[nr][nc] = newTime;
					pq.push(Node(nr, nc, newTime));
				}
			}
		}
		return -1;
	}
};