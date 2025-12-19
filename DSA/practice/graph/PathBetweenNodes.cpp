#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
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
	int V, E;
	cin >> V >> E;
	Graph g = Graph(false, V);
	vector<unordered_set<int>> components;
	for (int i = 0; i < E; i++)
	{
		int x, y;
		cin >> x >> y;
		g.addNeighbor(x, y);
	}
	vector<bool> visited(V, false);
	for (size_t i = 0; i < V; i++)
	{
		if (!visited[i]) {
			unordered_set<int> h;
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while (!q.empty())
			{
				int curr = q.front();
				q.pop(); h.insert(curr);
				for (auto& el : g.neighbors[curr]) {
					if (!visited[el]) {
						q.push(el);
						visited[el] = true;
					}
				}
			}
			components.push_back(h);
		}
	}

	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int start, target;
		cin >> start >> target;
		for (auto& component: components)
		{
			if (component.find(start) != component.end()) {
				bool existsWay = component.find(target) != component.end();
				std::cout << existsWay << ' ';
				break;
			}
		}
	}
	return 0;
}