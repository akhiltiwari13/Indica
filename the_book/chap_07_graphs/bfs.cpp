/* implementing breadth first search on an adjacency list implementation of a
 * graph. */
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

// visits nodes with increasing distance from the starting node.
void bfs(const vector<vector<int>> &graph, int source) {

  vector<bool> visited(7, false);
  vector<int> distance(7, 0);
  queue<int> neighboursWithIncreasingDistance;

  neighboursWithIncreasingDistance.push(source);
  distance[source] = 0;
  visited[source] = true;

  /* O(m+n) */
  while (!neighboursWithIncreasingDistance.empty()) {
    auto n = neighboursWithIncreasingDistance.front();
    neighboursWithIncreasingDistance.pop();
    std::cout << "Visited: " << n << std::endl;
    std::cout << "distance of " << n << " from " << source << " is "
              << distance[n] << std::endl;
    for (auto neighbour : graph[n]) {
      if (visited[neighbour])
        continue;
      distance[neighbour] = distance[n] + 1;
      visited[neighbour] = true;
      neighboursWithIncreasingDistance.push(neighbour);
    }
  }
}

int main() {

  // represent a graph network.
  vector<vector<int>> adjacencyList = {{},  {2, 4}, {3, 5}, {2, 6},
                                       {1}, {2, 3}, {3, 5}};

  bfs(adjacencyList, 1); // graph and the start node.
  return 0;
}
