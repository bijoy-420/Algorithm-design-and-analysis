#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;  // Maximum number of vertices

vector<int> adj[MAX], transpose[MAX]; // Adjacency list and transposed graph
bool visited[MAX]; // Visited array to keep track of visited nodes
stack<int> finishStack; // Stack to store the finishing times of nodes

// Function to add an edge to the graph
void addEdge(int u, int v) {
    adj[u].push_back(v);
}

// DFS function to fill the stack with finishing times
void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    finishStack.push(u);
}

// DFS function to explore the strongly connected components (SCC)
void dfs2(int u, vector<int>& scc) {
    visited[u] = true;
    scc.push_back(u);
    for (int v : transpose[u]) {
        if (!visited[v]) {
            dfs2(v, scc);
        }
    }
}

// Main function to find and print SCCs
void findSCCs(int V) {
    // Step 1: Perform DFS to fill the stack with finishing times
    fill(visited, visited + V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    // Step 2: Transpose the graph
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            transpose[v].push_back(u);
        }
    }

    // Step 3: Perform DFS on the transposed graph in finishing time order
    fill(visited, visited + V, false);
    vector<vector<int>> sccList;

    while (!finishStack.empty()) {
        int u = finishStack.top();
        finishStack.pop();

        if (!visited[u]) {
            vector<int> scc;
            dfs2(u, scc);
            sccList.push_back(scc); // Store each SCC
        }
    }

    // Sort SCCs to ensure the correct order
    sort(sccList.begin(), sccList.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size(); // Sort by size of SCCs
    });

    // Print the SCCs in the desired format
    cout << "Strongly Connected Components:\n";
    for (const auto& scc : sccList) {
        for (int i = 0; i < scc.size(); ++i) {
            cout << scc[i];
            if (i != scc.size() - 1) {
                cout << " ";  // Add space between elements
            }
        }
        cout << "\n";  // New line after each SCC
    }
}

int main() {
    int V = 8;
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 0);
    addEdge(2, 4);
    addEdge(4, 5);
    addEdge(5, 6);
    addEdge(6, 4);
    addEdge(6, 7);

    findSCCs(V);
    return 0;
}
