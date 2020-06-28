/*Implments Bellman-Ford Algorithm. */
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

enum class Color { WHITE, GREEN, BLUE };

bool isBipartite(const std::vector<std::vector<int>> &graph,
                 std::vector<bool> &visited, std::vector<Color> &colorVec,
                 int node, Color color) {
  if (visited[node]) {
    return (color == colorVec[node]) ? true : false;
  }
  bool result = true;
  visited[node] = true;
  colorVec[node] = color;
  std::cout << "Visited: " << node << std::endl;
  color = (color == Color::BLUE) ? Color::GREEN : Color::BLUE;
  for (auto neighbour : graph[node]) {
    result &= isBipartite(graph, visited, colorVec, neighbour, color);
  }
  return result;
}

int main() {
  // represent a graph network.
  std::vector<std::vector<int>> adjacencyList = {{},     {2, 4}, {1, 3, 5},
                                                 {2, 5}, {1},    {2, 3}};
  std::vector<bool> visited(6, false);
  std::vector<Color> colorVec(6, Color::WHITE);
  isBipartite(
      adjacencyList, visited, colorVec, 1,
      Color::BLUE) // for start previous node and current nodes are same.
      ? std::cout << "is Bipartite" << std::endl
      : std::cout << "NOT Bipartite" << std::endl;

  return 0;
}
