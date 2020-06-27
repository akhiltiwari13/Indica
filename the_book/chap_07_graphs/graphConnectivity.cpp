/* Checking graph connectivity. */
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<int>> &graph, vector<bool> &visited, int node) {
  if (visited[node]) {
    return; // do nothing if the node has been visited.
  } else {
    visited[node] = true;
    std::cout << "Visited: " << node << std::endl;
    for (auto neighbour : graph[node]) {
      dfs(graph, visited, neighbour);
    }
  }
}

bool isConnected(const vector<vector<int>> &graph) {
  bool result = true;
  vector<bool> visited(8, false);
  dfs(graph, visited, 1); // graph and the start node.

  for (int i = 1; i < visited.size(); ++i) {
    if (!visited[i]) {
      result = false;
      break;
    }
  }
  return result;
}

int main() {
  // represent a graph network.
  vector<vector<int>> adjacencyList = {{},  {2, 4}, {1, 3, 5}, {2, 5},
                                       {1}, {2, 3}, {7},       {6}};
  isConnected(adjacencyList) ? std::cout << "Connected" << std::endl
                             : std::cout << "Disconnected" << std::endl;

  return 0;
}
