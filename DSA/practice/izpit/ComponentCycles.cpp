#include <bits/stdc++.h>
using namespace std;

bool hasCycle(int start, vector<vector<int>>& g, vector<bool>& visited) {
    bool result = false;
    queue<pair<int, int>> q;
    q.push({ start, -1 });
    visited[start] = true;
    while (!q.empty()) {
        auto& curr = q.front(); q.pop();
        for (auto& neighbor : g[curr.first]) {
            if (neighbor == curr.first) {
                result = true;
            }
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({ neighbor, curr.first });
            }
            else {
                if (neighbor != curr.second)
                    result = true;
            }
        }
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        vector<vector<int>>g(v);
        for (int i = 0; i < e; i++) {
            int from, to;
            cin >> from >> to;
            g[from].push_back(to);
            g[to].push_back(from);
        }
        vector<bool> visited(v, false);
        int cycleCount = 0;
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (hasCycle(i, g, visited))
                    cycleCount++;
            }
        }
        cout << cycleCount << endl;
    }

    return 0;
}