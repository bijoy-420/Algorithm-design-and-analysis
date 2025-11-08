#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100]; // Directed graph সংরক্ষণের জন্য অ্যাডজেসেন্সি লিস্ট
bool visited[100];      // ভিজিট করা হয়েছে কিনা তা চেক করার জন্য ভিজিটেড অ্যারে
vector<int> result;     // টপোলজিক্যাল অর্ডার সংরক্ষণ

void dfs(int source) {
    visited[source] = true; // বর্তমান নোড ভিজিট চিহ্নিত
    for (int next : graph[source]) { // `source` এর সাথে সংযুক্ত সকল নোডে ট্রাভার্স
        if (!visited[next]) {        // যদি নোডটি ভিজিট করা না হয়
            dfs(next);               // রিকার্সিভলি DFS কল
        }
    }
    result.push_back(source); // নোডটি প্রসেস শেষ হলে রেজাল্টে যোগ করা
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    cout << "Enter the edges (u -> v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // Directed edge যোগ করা
    }

    // সকল নোডের জন্য DFS কল
    for (int i = 0; i < nodes; i++) { 
        if (!visited[i]) {
            dfs(i);
        }
    }

    // রিভার্স করে টপোলজিক্যাল অর্ডার পাওয়া
    reverse(result.begin(), result.end());

    // টপোলজিক্যাল অর্ডার প্রিন্ট করা
    cout << "Topological sorting: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
