#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited) {
  visited[node] = true;
  for (int i = 0; i < graph[node].size(); i++)
    if (graph[node][i] && !visited[i])
      dfs(graph, i, visited);
}

int components(vector<vector<int>> &graph) {
  vector<bool> visited(graph.size(), false);
  int count = 0;
  for (int i = 0; i < graph.size(); i++)
    if (!visited[i]) {
      count++;
      dfs(graph, i, visited);
    }
  return count;
}

int main() {
  int vertices, edges;
  cin >> vertices >> edges;
  vector<vector<int>> graph(vertices, vector<int>(vertices, 0));

  for (int i = 0; i < edges; i++) {
    int u, v;
    cin >> u >> v;
    graph[u][v] = 1;
    graph[v][u] = 1; // For undirected graph
  }
  cout << components(graph) << endl;
}
