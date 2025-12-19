#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

void bfs(int start, vector<unordered_set<int>>& g, vector<int>& shortestPaths) {
	int V = g.size();
	vector<bool> visited(V, false);
	visited[start] = true;
	int visitedCount = 1;
	queue<int> q;
	q.push(start);
	int level = 0;
	shortestPaths[start] = level;
	while (!q.empty() && visitedCount < V)
	{
		int lvlSize = q.size();
		for (int i = 0; i < q.size(); i++)
		{
			if (visitedCount == V) {
				return;
			}
			int curr = q.front(); q.pop();
			for (int j = 0; j < V; j++)
			{
				if (!visited[j] && (g[curr].find(j) == g[curr].end())) {
					visitedCount++;
					visited[j] = true;
					q.push(j);
					shortestPaths[j] = level + 1;
				}
			}
		}
		level++;
	}
}

void doShit() {
	int V, E;
	cin >> V >> E;
	vector<unordered_set<int>> g(V);
	for (size_t i = 0; i < E; i++)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].insert(y);
		g[y].insert(x);
	}
	int start;
	cin >> start;
	start--;
	vector<int> shortestPaths(V, -1);
	bfs(start, g, shortestPaths);
	for (auto& el : shortestPaths) {
		if (el == start)
			continue;
		cout << el << ' ';
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;
	for (size_t i = 0; i < q; i++)
	{
		doShit();
	}
	return 0;
}