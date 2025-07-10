#include <iostream>
#include <vector>
#include "../Queue/queue_ll.cpp"
using namespace std;
void bfs(vector<vector<int> > matrix, int node, vector<bool> & dp)
{
    Queue<int> q;
    q.push(node);
    q.push(-1); // NULL
    cout << node << endl;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == -1)
        {
            cout << endl;
            if(!q.empty())
            q.push(-1);
        }
        else
        {
            for (int i = 0; i < matrix[curr].size(); i++)
            {
                if (matrix[curr][i] && !dp[i])
                {
                    q.push(i);
                    dp[i] = true;
                    cout << i << " ";
                }
            }
            dp[curr] = true;
        }
    }
}
void BFS(vector<vector<int> >mat)
{
    vector<bool> dp(mat.size(), false);
    for (int i = 0; i < mat.size(); i++)
    {
        if (!dp[i])
            bfs(mat, i, dp);
    }
}

int main()
{
    int verterx, edges;
    int node1, node2;
    // cout << "Enter the number of Vertex and Edges of the matrix: ";
    cin >> verterx >> edges;
    vector<vector<int> > matrix(verterx, vector<int>(verterx, 0));
    // cout << "Enter the edge of the matrix: ";
    for (int i = 0; i < edges; i++)
    {
        cin >> node1 >> node2;
        matrix[node1][node2] = 1;
        matrix[node2][node1] = 1;
    }

    BFS(matrix);
    return 0;
}
