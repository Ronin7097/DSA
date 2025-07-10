#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
template <typename t>
class Graphs
{
    unordered_map<t, list<t> > mp;
    bool CycleDetectionhelper_BFS(unordered_map<t, bool> &visit, t node)
    {
        unordered_map<t, t> parent;
        parent[node] = NULL;
        visit[node] = true;
        queue<t> q;
        q.push(node);
        while (!q.empty())
        {
            t current = q.front();
            q.pop();
            for (auto i : mp[current])
            {
                if (visit[i] == false)
                {
                    visit[i] = true;
                    parent[i] = current;
                    q.push(i);
                }
                else if (visit[i] && parent[current] != i)
                    return true;
            }
            visit[current] = true;
        }

        return false;
    }

    bool CycleDetectionhelper_DFS(unordered_map<t, bool> &visit, t node, t parent)
    {
        visit[node] = true;
        for (auto i : mp[node])
        {
            if (!visit[i])
            {
                bool ans = CycleDetectionhelper_DFS(visit, i, node);
                if (ans)
                    return true;
            }
            else if (i != parent)
                return true;
        }
        return false;
    }

    bool CycleDetectionDirectHelper(unordered_map<t, bool> visit, t node, unordered_map<t, bool> dfs)
    {
        visit[node] = true;
        dfs[node] = true;
        for (auto i : mp[node])
        {
            if (visit[node] == false)
            {
                bool ans = CycleDetectionDirectHelper(visit, i, dfs);
                if (ans)
                    return ans;
            }
            else if (visit[node] && dfs[node])
                return true;
        }
        dfs[node] = false;
        return false;
    }

public:
    void add_Edge(t v, t e, bool direction)
    {
        // direction 1 -> direct
        // direction 0 -> non-direct
        mp[v].push_back(e);
        if (direction == 0)
            mp[e].push_back(v);
    }
    void print()
    {
        for (auto i : mp)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
                cout << j << ", ";
            cout << endl;
        }
    }

    bool CycleDetection_BFS()
    {
        unordered_map<t, bool> visit;
        for (auto i : mp)
        {
            if (!visit[i.first])
            {
                bool ans = CycleDetectionhelper_BFS(visit, i.first);
                if (ans)
                    return ans;
            }
        }
        return false;
    }

    bool CycleDetection_Dfs()
    {
        unordered_map<t, bool> visit;
        for (auto i : mp)
        {
            if (!visit[i.first])
            {
                bool ans = CycleDetectionhelper_DFS(visit, i.first, NULL);
                if (ans)
                    return true;
            }
        }
        return false;
    }
    bool CycleDetection_Directed()
    {
        unordered_map<t, bool> visit;
        unordered_map<t, bool> dfs;
        for (auto i : mp)
        {
            if (!visit[i.first])
            {
                bool ans = CycleDetectionDirectHelper(visit, i.first, dfs);
                if (ans)
                    return ans;
            }
        }
        return false;
    }
    int size()
    {return mp.size();}
};

/// driver code
int main()
{
    int e;
    cout << "Enter the  number of Edges : " << endl;
    cin >> e;
    Graphs<int> g;
    for (int i = 0; i < e; i++)
    {
        int v, u, d;
        cin >> v >> u >> d;
        g.add_Edge(v, u, d);
    }
    g.print();
    cout << "Is Cycle Present : " << (g.CycleDetection_Directed () ? "True" : "False");
}
