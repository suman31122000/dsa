#include <bits/stdc++.h>
using namespace std;

// Function to compute transitive closure using the Floyd-Warshall algorithm
vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph) {
    vector<vector<int>> ans = graph;

    // Step 1: Initialize the answer matrix
    for (int i = 0; i < N; i++) {
        ans[i][i] = 1; // A node is reachable from itself
    }

    // Step 2: Update the answer matrix using the Floyd-Warshall algorithm
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // If there is a path from i to k and from k to j, then there is a path from i to j
                if (ans[i][k] && ans[k][j]) {
                    ans[i][j] = 1;
                }
            }
        }
    }

    return ans;
}

int main() {
    int N, E;
    cout << "Enter number of vertices and edges: ";
    cin >> N >> E;

    // Initialize the graph with 0 (no edges)
    vector<vector<int>> graph(N, vector<int>(N, 0));

    cout << "Enter the edges (from, to):" << endl;
    for (int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1; // Set edge from x to y
    }

    // Compute the transitive closure
    vector<vector<int>> closure = transitiveClosure(N, graph);

    // Output the transitive closure matrix
    cout << "Transitive Closure Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << closure[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
