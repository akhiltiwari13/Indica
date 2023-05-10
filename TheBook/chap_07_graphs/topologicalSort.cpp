#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& s) {
    visited[u] = true;
    
    // visit all adjacent vertices of u
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, s);
        }
    }
    
    // push the current vertex to the stack after all its adjacent vertices are visited
    s.push(u);
}

vector<int> topological_sort(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> s;
    
    // perform DFS on all unvisited vertices
    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            dfs(u, adj, visited, s);
        }
    }
    
    // pop the vertices from the stack to obtain the topological order
    vector<int> order;
    while (!s.empty()) {
        order.push_back(s.top());
        s.pop();
    }
    
    return order;
}

int main() {
    int n, m;  // number of vertices and edges
    cin >> n >> m;
    
    vector<vector<int>> adj(n);
    
    // read in the edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    vector<int> order = topological_sort(adj);
    
    // print the topological order
    for (int u : order) {
        cout << u << " ";
    }
    cout << endl;
    
    return 0;
}
