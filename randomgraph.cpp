#include<bits/stdc++.h>
#include<chrono> // for measuring time

using namespace std;
using namespace chrono;

const int MAX = 200;
int G[MAX][MAX];
int x[MAX];
int n, m, flag;

void NextValue(int k) {
    do {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0) return;
        bool valid = true;

        for (int j = 1; j <= n; j++) {
            if (G[k][j] && x[j] == x[k]) {
                valid = false;
                break;
            }
        }
        if (valid) return;
    } while (true);
}

void mColoring(int k) {
    do {
        NextValue(k);
        if (x[k] == 0) return;
        if (k == n) {
            flag = 1;
        } else {
            mColoring(k + 1);
            if (flag) return;
        }
    } while (true);
}

void generateGraph(int edgeDensity) {
    // Create a graph with n vertices and a given edge density (D)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                // Randomly decide if there should be an edge
                if (rand() % 100 < edgeDensity) {
                    G[i][j] = G[j][i] = 1;
                } else {
                    G[i][j] = G[j][i] = 0;
                }
            }
        }
    }
}

int main() {
    // Vary N from 50 to 200 in steps of 50
    for (n = 10; n <= 200; n += 5                   ) {
        cout << "Number of vertices (N): " << n << endl;

        // Vary edge density D from 10% to 90% in steps of 20%
        for (int density = 10; density <= 90; density += 20) {
            // Generate the graph with the given edge density
            generateGraph(density);

            // Measure the time taken to find the chromatic number
            auto start = high_resolution_clock::now();

            for (m = 1; m <= n; m++) {
                flag = 0;
                fill(x, x + MAX, 0);
                mColoring(1);
                if (flag == 1) {
                    cout << "Edge Density: " << density << "%, Chromatic number: " << m << endl;
                    break;
                }
            }

            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);

            cout << "Time taken: " << duration.count() << " ms" << endl;
        }
    }

    return 0;
}