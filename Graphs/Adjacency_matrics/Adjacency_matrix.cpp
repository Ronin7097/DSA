#include <iostream>
#include <vector>
using namespace std;
void printDFS(vector<vector<int> > arr, int sv, vector<bool> &dp)
{
    cout << sv << endl;
    dp[sv] = true;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[sv][i] == 1 && dp[i] == false)
            printDFS(arr, i, dp);
    }
}

void DFS(vector<vector<int> > m)
{
    vector<bool> dp(m.size(), false);
    for (int i = 0; i < m.size(); i++)
    {
        if (!dp[i])
            printDFS(m, i, dp);
    }
}
int main()
{
    int verterx, edges;
    int node1, node2;
    //cout << "Enter the number of Vertex and Edges of the matrix: ";
    cin >> verterx >> edges;
    vector<vector<int> > matrix(verterx, vector<int>(verterx, 0));
    //cout << "Enter the edge of the matrix: ";
    for (int i = 0; i < edges; i++)
    {
        cin >> node1 >> node2;
        matrix[node1][node2] = 1;
        matrix[node2][node1] = 1;
    }
    DFS(matrix);
    return 0;
}