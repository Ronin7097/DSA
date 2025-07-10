#include <iostream>
#include <list>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
using namespace std;
class Graphs {
    unordered_map<int, list<int>> mp;
    unordered_map<int, list<pair<int, int>>> mpw;
    // topo sort
    void topo(unordered_map<int, bool> &vis, stack<int> &s, int node) {
        vis[node] = true;
        for(auto i : mpw[node]) {
            if(!vis[i.first])
                topo(vis, s, i.first);
        }
        s.push(node);
    }
    vector<int> parentfinder(int src) {
        vector<bool> vis(mp.size() + 1, false);
        vector<int> parent(mp.size() + 1, -1);
        queue<int> q;
        q.push(src);
        while(!q.empty()) {
            int curr = q.front();
            vis[curr] = true;
            q.pop();

            for(auto i : mp[curr]) {
                if(!vis[i]) {
                    vis[i] = true;
                    q.push(i);
                    parent[i] = curr;
                }
            }
        }
        return parent;
    }

  public:
    void add_Edge(int v, int e, bool direction, int weight, bool w) {
        // direction 1 -> direct
        // direction 0 -> non-direct
        // w->1 if weight
        // w->0 if no weight
        if(w) {
            mpw[v].push_back(make_pair(e, weight));
            if(direction == 0)
                mpw[e].push_back(make_pair(v, weight));
            return;
        }
        mp[v].push_back(e);
        if(direction == 0)
            mp[e].push_back(v);
    }
    void print() {
        for(auto i : mpw) {
            cout << i.first << "-> ";
            for(auto j : i.second)
                cout << j.first << ", ";
            cout << endl;
        }
    }
    void shortest_path_undirected_unweighted(int src, int dest) {
        vector<int> parent = parentfinder(src);
        for(auto i : parent)
            cout << i << " ";
        cout << endl;
        // backtracking
        while(src != dest) {
            cout << dest << " ";
            dest = parent[dest];
        }
        cout << src << endl;
    }

    void shortest_path_directed(int src, int des) {
        stack<int> s;
        unordered_map<int, bool> vis;
        topo(vis, s, 0);
        vector<int> dis(mpw.size(), INT_MAX);
        dis[src] = 0;
        while(!s.empty() && src != s.top()) {
            dis[s.top()] = 0;
            s.pop();
        }
        // find dis
        while(!s.empty()) {
            for(auto i : mpw[s.top()])
                if(dis[i.first] > (i.second + dis[s.top()]))
                    dis[i.first] = (i.second + dis[s.top()]);
            s.pop();
        }
        cout << dis[des] << endl;
        return;
    }

    void dijkstra(int src, int des) {
        set<pair<int, int> > s;
        vector<int> dist(mpw.size(), INT_MAX);
        dist[src] = 0;
        s.insert(make_pair(0, src));
        while(!s.empty()) {
            pair<int, int> curr = *(s.begin());
            s.erase(s.begin());
            for(auto i : mpw[curr.second]) {
                if(dist[i.first] > (i.second + dist[curr.second])) {
                    auto record = s.find(make_pair(dist[i.first], i.first));
                    //if record exist erase it
                    if(record != s.end())
                        s.erase(record);

                    dist[i.first] = i.second + dist[curr.second];
                    s.insert(make_pair(dist[i.first], i.first));
                }
            }
        }
        for(auto i : dist)
            cout << i << " ";
        cout << endl;
    }
};

// Driver code
int main() {
    int e;
    cout << "Enter the  number of Edges : " << endl;
    cin >> e;
    Graphs g;
    // for (int i = 0; i < e; i++)
    // {
    //     int v, u; // undirected graphs
    //     cin >> v >> u;
    //     g.add_Edge(v, u, 0,0,0);
    // }
    // weighted direct graphs
    for(int i = 0; i < e; i++) {
        int v, u, w; // undirected graphs
        cin >> v >> u >> w;
        g.add_Edge(v, u, 0, w, 1);
    }
    g.print();
    g.dijkstra(0, 3);
}