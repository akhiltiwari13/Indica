#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<int>> floyd_warshall(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<vector<int>> dist(adj);
    
    // consider all vertices as intermediate vertices one by one
    for (int k = 0; k < n; k++) {
        // consider all pairs of vertices (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // if vertex k is on the shortest path from i to j, update the path
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    return dist;
}

int main() {
    int n, m;  // number of vertices and edges
    cin >> n >> m;
    
    vector<vector<int>> adj(n, vector<int>(n, INF));  // adjacency matrix
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;  // for undirected graphs
    }
    
    vector<vector<int>> dist = floyd_warshall(adj);
    
    // print the shortest distance between all pairs of vertices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
