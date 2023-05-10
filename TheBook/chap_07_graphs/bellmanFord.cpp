/*Implments Bellman-Ford Algorithm. */
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// structure to represent a weighted edge in the graph
struct Edge {
  int source, destination, weight;
};

// function to find the shortest path using Bellman-Ford algorithm
void bellmanFord(vector<Edge> &edges, int numVertices, int sourceVertex) {
  int numEdges = edges.size();

  // Initialize distances from source vertex to all other vertices as INFINITE
  vector<int> distance(numVertices, numeric_limits<int>::max());

  // Set distance of source vertex to 0
  distance[sourceVertex] = 0;

  // Relax all edges (numVertices - 1) times
  for (int i = 0; i < numVertices - 1; i++) {
    for (int j = 0; j < numEdges; j++) {
      int u = edges[j].source;
      int v = edges[j].destination;
      int w = edges[j].weight;
      if (distance[u] != numeric_limits<int>::max() && distance[u] + w < distance[v]) {
        distance[v] = distance[u] + w;
      }
    }
  }

  // Check for negative-weight cycles. If we still can relax the edges, then
  // there is a negative cycle
  for (int j = 0; j < numEdges; j++) {
    int u = edges[j].source;
    int v = edges[j].destination;
    int w = edges[j].weight;
    if (distance[u] != numeric_limits<int>::max() && distance[u] + w < distance[v]) {
      cout << "Graph contains negative-weight cycle" << endl;
      return;
    }
  }

  // Print the shortest distances
  cout << "Shortest distances from source vertex " << sourceVertex
       << " to all other vertices:" << endl;
  for (int i = 0; i < numVertices; i++) {
    cout << i << ": " << distance[i] << endl;
  }
}

int main(int argc, char *argv[]) {
  // create the example graph
  vector<Edge> edges = {{0, 1, 4}, {0, 2, 8}, {1, 2, -2},
                        {1, 3, 6}, {2, 3, 3}, {3, 4, 9}};
  int numVertices = 5;
  int sourceVertex = 0;

  // find the shortest path
  bellmanFord(edges, numVertices, sourceVertex);

  return 0;
}
