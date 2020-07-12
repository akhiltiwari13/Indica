/* implementing depth first search adjacency list implementation of a graph. */
#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(7, false);

void dfs(const vector<vector<int>> &graph, int node) {
  if (visited[node]) {
    return; // do nothing if the node has been visited.
  } else {
    visited[node] = true;
    std::cout << "Visited: " << node << std::endl;
    for (auto neighbour : graph[node]) {
      dfs(graph, neighbour);
    }
  }
}

int main() {

  // represent a graph network.
  vector<vector<int>> adjacencyList = {{},     {2, 4}, {1, 3, 5},
                                       {2, 5}, {1},    {2, 3}};

  dfs(adjacencyList, 1); // graph and the start node.
  return 0;
}
