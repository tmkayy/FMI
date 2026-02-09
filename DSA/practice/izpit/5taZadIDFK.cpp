// Faculty_number: 
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<int> parent, rank_;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    if (rank_[x] < rank_[y])
        parent[x] = y;
    else if (rank_[x] > rank_[y])
        parent[y] = x;
    else {
        parent[y] = x;
        rank_[x]++;
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());
    parent.resize(n);
    rank_.resize(n, 0);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int components = n;
    vector<int> maxEdgeInComponent(n, 0);
    for (const auto& edge : edges) {
        if (components == k)
            break;
        if (unite(edge.u, edge.v)) {
            components--;
            int root = find(edge.u);
            maxEdgeInComponent[root] = max(maxEdgeInComponent[root], edge.w);
        }
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            result.push_back(maxEdgeInComponent[i]);
        }
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < k; i++) {
        cout << result[i] << ' ';
    }

    return 0;
}