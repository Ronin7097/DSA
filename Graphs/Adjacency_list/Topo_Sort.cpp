#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;
template <typename t>
class Graphs
{
    unordered_map<t, list<t> > mp;
    void dfs(unordered_map<t, bool> &vis, stack<t> &s, t node)
    {
        vis[node] = true;
        for (auto i : mp[node])
        {
            if (!vis[i])
                dfs(vis, s, i);
        }
        s.push(node);
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

    void toposort()
    {
        unordered_map<t, bool> vis;
        stack<t> s;
        for (auto i : mp)
        {
            if (!vis[i.first])
                dfs(vis, s, i.first);
        }
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
};
// Driver Code

int main()
{
    int e;
    cout << "Enter the  number of Edges : " << endl;
    cin >> e;
    Graphs<int> g;
    for (int i = 0; i < e; i++)
    {
        int v, u, d = 1;//directed graphs
        cin >> v >> u;
        g.add_Edge(v, u, d);
    }
    g.print();
    g.toposort();
}