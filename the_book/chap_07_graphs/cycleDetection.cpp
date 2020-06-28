/* Cycle detection in an undirected graph. */
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

bool hasCycle(const vector<vector<int>> &graph, vector<bool> &visited, int node,
              int parentNode, int parentPredecessorNode) {
  if (visited[node]) {
    return (node == parentNode) || (node == parentPredecessorNode) ? false
                                                                   : true;
  }
  bool result = false;
  visited[node] = true;
  std::cout << "Visited: " << node << std::endl;
  for (auto neighbour : graph[node]) {
    result |= hasCycle(graph, visited, neighbour, node,
                       parentNode); // a return statement here would break out
                                    // of the loop always!!
  }
  return result;
}

int main() {
  // represent a graph network.
  vector<vector<int>> adjacencyList = {{},  {2, 4}, {1, 3, 5}, {2},
                                       {1}, {2, 6}, {7},       {6}};
  vector<bool> visited(8, false);
  hasCycle(adjacencyList, visited, 1, 0,
           0) // for start previous node and current nodes are same.
      ? std::cout << "Has a cycle" << std::endl
      : std::cout << "No cycles found" << std::endl;

  return 0;
}
