#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Graph {
	bool dir;
	int verticesCount;
	vector<vector<int>> neighbors;

	Graph(bool dir, int verticesCount) {
		this->dir = dir;
		this->verticesCount = verticesCount;
		neighbors.resize(verticesCount);
	}

	void addNeighbor(int x, int y) {
		if (!dir) {
			neighbors[y].push_back(x);
		}
		neighbors[x].push_back(y);
	}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int V, E;
		cin >> V >> E;
		Graph g = Graph(false, V);
		for (int j = 0; j < E; j++)
		{
			int x, y;
			cin >> x >> y;
			g.addNeighbor(x, y);
		}

		int count = 0;
		vector<bool> visited(V, false);
		for (size_t j = 0; j < V; j++)
		{
			if (!visited[j]) {
				count++;
				queue<int> q;
				q.push(j);
				while (!q.empty())
				{
					int curr = q.front();
					q.pop();
					for (auto& neighbor : g.neighbors[curr]) {
						if (!visited[neighbor]) {
							visited[neighbor] = true;
							q.push(neighbor);
						}
					}
				}
			}
		}
		std::cout << count << ' ';
	}
	return 0;
}