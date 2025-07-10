#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;
template <typename t>
class Graphs
{
    unordered_map<t, list<pair<t, int> > > adj;
    void primsHelper(unordered_map<t, int> &weigh, unordered_map<t, bool> &visit, unordered_map<t, t> &parent, t node, priority_queue<pair<int, t>, vector<pair<int, t> >, greater<pair<int, t> > > &pq)
    {
        pq.push(make_pair(0, node));
        while (!pq.empty())
        {
            // finding the minimum weight;
            t u = pq.top().second;
            pq.pop();
            if (visit[u] == true)
                continue; // Skip if the vertex is already visited
            // mark u as true;
            visit[u] = true;
            // finding next min adj node
            for (auto v : adj[u])
            {
                int vertex = v.first;
                int weight = v.second;
                if (visit[vertex] == false && weigh[vertex] > weight)
                {
                    parent[vertex] = u;
                    pq.push(make_pair(weight, vertex));
                    weigh[vertex] = weight;
                }
            }
        }
    }

public:
    void add_Edge(t v, t u, int weigh)
    {
        adj[v].push_back(make_pair(u, weigh));
        adj[u].push_back(make_pair(v, weigh));
    }
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
                cout << j.first << ", ";
            cout << endl;
        }
    }
    void prims()
    {
        unordered_map<t, int> weigh;
        unordered_map<t, bool> visit;
        unordered_map<t, t> parent;
        priority_queue<pair<int, t>, vector<pair<int, t> >, greater<pair<int, t> > > pq;
        // intialization
        for (auto i : adj)
        {
            weigh[i.first] = INT_MAX;
            visit[i.first] = false;
            parent[i.first] = -1;
        }

        // run Prims Algorithm
        for (auto i : visit)
        {
            if (i.second == false)
                primsHelper(weigh, visit, parent, i.first, pq);
        }
        unordered_map<t, list<pair<t, int> > > tree;
        for (auto i : adj)
        {
            auto p = make_pair(i.first, weigh[i.first]);
            if (parent[i.first] == -1)
                continue;
            auto p1 = make_pair(parent[i.first], weigh[i.first]);
            tree[parent[i.first]].push_back(p);
            tree[i.first].push_back(p1);
        }
        // print tree
        cout << "MST Tree : " << endl;
        for (auto i : tree)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
                cout << j.first << ", ";
            cout << endl;
        }
    }
};

int main()
{
    Graphs<int> g;
    int E;
    cout << "Enter number of Edges : ";
    cin >> E;
    cout << endl;
    for (int i = 0; i < E; i++)
    {
        int v, u, weigh;
        cin >> v >> u >> weigh;
        g.add_Edge(v, u, weigh);
    }
    g.print();
    cout << endl;
    g.prims();
}