#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> G;
vector<int> x;

// Function to assign the next color to vertex k
void nextValue(int k) {
    do {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0) return; // Backtrack if no color is possible

        int j;
        for (j = 1; j <= n; j++) {
            if (G[k][j] != 0 && x[k] == x[j]) break; // Check for conflicts
        }
        if (j == n + 1) return; // Valid color found
    } while (true);
}

// Recursive function to check if coloring is possible with m colors
bool mColoring(int k) {
    do {
        nextValue(k);
        if (x[k] == 0) return false; // No color found, backtrack

        if (k == n) {
            return true; // All vertices are colored
        } else {
            if (mColoring(k + 1)) return true;
        }
    } while (true);
}



int main() {
    n = 7;
    G.resize(n + 1, vector<int>(n + 1, 0));  
    x.resize(n + 1, 0);

    // Initialize adjacency matrix
    G = {
        {0, 1, 0, 0, 1,1,1},
        {1, 0, 1, 1, 0,0,0},
        {0, 1, 0, 1, 0,0,1},
        {0, 1, 1, 0, 1,0,0},
        {1,0, 0, 1, 0,1,1},
        {1,0,0,0,1,0,1},
        {1,0,1,01,1,0}
    };

    m = 1; // Start with 1 color

    // Try increasing number of colors until successful
    while (true) {
        //fill(x.begin(), x.end(), 0); // Reset colors
        x.resize(n+1,0);
        if (mColoring(1)) {
            cout << "Minimum colors required: " << m << endl;
            break;
        }
        m++;
    }

    
}