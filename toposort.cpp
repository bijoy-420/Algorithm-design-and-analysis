#include <bits/stdc++.h>
using namespace std;

// Global variables for DFS
vector<list<int>> adj;        // Adjacency list
vector<string> color;         // Color array (white, gray, black)
vector<int> d;                // Discovery time
vector<int> f;                // Finish time
vector<int> pi;               // Parent array
list<int> topoList;           // List for topological sort
int timeCounter = 0;          // Global time counter

// Function to add an edge to the graph
void addEdge(int u, int v) {
    adj[u].push_back(v); // Directed edge from u to v
}

// Recursive DFS-Visit function
void DFSVisit(int u) {
    color[u] = "gray";  // Mark u as discovered
    timeCounter++;
    d[u] = timeCounter;

    // Explore neighbors
    for (int v : adj[u]) {
        if (color[v] == "white") {
            pi[v] = u;
            DFSVisit(v);
        }
    }

    color[u] = "black"; // Mark u as finished
    timeCounter++;
    f[u] = timeCounter;

    // Add the vertex to the front of the list after finishing
    topoList.push_front(u);
}

// DFS function
void DFS(int V) {
    // Initialize all vertices
    color.assign(V + 1, "white");
    d.assign(V + 1, INT_MAX);
    f.assign(V + 1, INT_MAX);
    pi.assign(V + 1, -1);
    timeCounter = 0;

    // Perform DFS for each vertex
    for (int i = 1; i <= V; ++i) {
        if (color[i] == "white") {
            DFSVisit(i);
        }
    }

    
}

// Function to perform topological sort
void topologicalSort(int V) {
    // Perform DFS first
    DFS(V);

    // Print topological order (list contents)
    cout << "\nTopological Order:\n";
    for (int i : topoList) {
        cout << i-1 << " ";
    }
    cout << endl;
}

int main() {
    int V = 7; // Number of vertices

    // Initialize adjacency list
    adj.resize(V + 1);

    // Add edges (directed graph)
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(5, 4);
    addEdge(5, 3);
    addEdge(6, 1);
    addEdge(6, 5);
    

    // Perform topological sort
    topologicalSort(V);

    return 0;
}