/* Cycle detection in an undirected graph. */
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

bool hasCycle(const vector<vector<int>> &graph, vector<bool> &visited, int node,
              int previousNode) {
  if (visited[node]) {
    return (node == previousNode) ? false : true;
  }
  visited[node] = true;
  std::cout << "Visited: " << node << std::endl;
  for (auto neighbour : graph[node]) {
    return hasCycle(graph, visited, neighbour, previousNode);
  }
}

int main() {
  // represent a graph network.
  vector<vector<int>> adjacencyList = {{},  {2, 4}, {1, 3, 5}, {2, 5},
                                       {1}, {2, 3}, {7},       {6}};
  vector<bool> visited(8, false);
  hasCycle(adjacencyList, visited, 1,
           1) // for start previous node and current nodes are same.
      ? std::cout << "Has a cycle" << std::endl
      : std::cout << "No cycles found" << std::endl;

  return 0;
}
