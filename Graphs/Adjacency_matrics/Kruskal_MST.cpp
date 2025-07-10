#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &parent, int i) {
  while (parent[i] != i)
    i = parent[i];
  return i;
}

void unionSets(int x, int y, vector<int> &parent) {
  int a = find(parent, x);
  int b = find(parent, y);
  parent[a] = b;
}
void KruskalMst(vector<vector<int>> &matrix, int V) {
  vector<int> parent(V);
  for (int i = 0; i < V; i++)
    parent[i] = i; // makeset;

  int edge_counter = 0, mincost = 0;
  while (edge_counter < V - 1) {
    int min = INT_MAX, a = -1, b = -1;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (find(parent, i) != find(parent, j) && matrix[i][j] < min) {
          min = matrix[i][j];
          a = i;
          b = j;
        }
      }
    }
    unionSets(a, b, parent);
    printf("Edge %d:(%d, %d) cost:%d \n", edge_counter++, a, b, min);
    mincost += min;
  }
  printf("\n Minimum cost= %d \n", mincost);
}

int main() {
  /* Let us create the following graph
        2    3
    (0)--(1)--(2)
     |   / \   |
    6| 8/   \5 |7
     | /     \ |
    (3)-------(4)
          9          */

  int verterx, edges;
  int node1, node2;
  // cout << "Enter the number of Vertex and Edges of the matrix: ";
  cin >> verterx >> edges;
  vector<vector<int>> matrix(verterx, vector<int>(verterx, INT_MAX));
  // cout << "Enter the edge of the matrix: ";
  for (int i = 0; i < edges; i++) {
    int weight = 0;
    cin >> node1 >> node2 >> weight;
    matrix[node1][node2] = weight;
    matrix[node2][node1] = weight;
  }
  KruskalMst(matrix, verterx);
}