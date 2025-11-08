#include <bits/stdc++.h>
using namespace std;

int n, m;
int x = 1000;
int cost = 0;
vector<int> dist(x), parent(x);
vector<vector<pair<int, int>>> g(x); // Graph as adjacency list (node, weight)
vector<bool> vis(x);

void primsmst(int source) {
    // Initialize distances to infinity
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1; // Initialize parent to -1
    }

    // Min-Heap (Set to store {weight, node})
    set<pair<int, int>> s;
    dist[source] = 0;
    s.insert({0, source});

    while (!s.empty()) {
        auto x = *(s.begin());
        s.erase(s.begin()); // Remove the smallest element
        int u = x.second;
        vis[u] = true;

        // If not the source, output the edge
        if (parent[u] != -1) {
            cout << u << " " << parent[u] << " " << x.first << endl;
            cost += x.first;
        }

        // Traverse neighbors of the current node
        for (auto it : g[u]) {
            int v = it.first; // Neighboring node
            int w = it.second; // Edge weight
            if (!vis[v] && dist[v] > w) {
                // Update the distance and parent
                s.erase({dist[v], v});
                dist[v] = w;
                s.insert({dist[v], v});
                parent[v] = u;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w}); // Undirected graph
    }

    primsmst(0); // Start Prim's from node 0
    cout << "Total Cost: " << cost << endl;

    return 0;
}
