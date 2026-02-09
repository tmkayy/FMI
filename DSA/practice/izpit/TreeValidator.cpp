// Faculty_number: 
#include <bits/stdc++.h>
using namespace std;

bool DFS(int node, int parent, vector<bool>& visited, const unordered_map<int, unordered_set<int>>& g) {
    visited[node] = true;
    if (g.find(node) != g.end()) {
        for (auto& neighbor : g.at(node)) {
            if (neighbor == parent) {
                continue;
            }

            if (visited[neighbor]) {
                return false;
            }

            if (!DFS(neighbor, node, visited, g)) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        bool isTree = true;
        int v, e;
        cin >> v >> e;
        vector<bool> visited(v, false);
        unordered_map<int, unordered_set<int>>g;
        for (int j = 0; j < e; j++) {
            int a, b;
            cin >> a >> b;
            g[a].insert(b);
            g[b].insert(a);
        }
        if (DFS(0, -1, visited, g)) {
            for (int k = 0; k < v; k++) {
                if (!visited[k]) {
                    isTree = false;
                    break;
                }
            }
        }
        else {
            isTree = false;
        }
        cout << isTree << endl;
    }

    return 0;
}