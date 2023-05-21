#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    list<int> *l;
    int V;
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }
    int minCostbfs(int source, int dest = -1)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *dist = new int[V]{0};
        int *parent = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }
        q.push(source);
        visited[source] = true;
        parent[source] = source;
        dist[source] = 0;
        while (!q.empty())
        {
            int f = q.front();
            cout << f << endl;
            q.pop();
            for (auto nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr); 
                    parent[nbr] = f;
                    dist[nbr] = dist[f] + 1;
                    visited[nbr] = true;
                }
            }
        }
      return dist[dest];
    }
};
int min_ladders(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders)
{
    vector<int> board(n + 1, 0);
    for (auto sp : snakes)
    {
        int s = sp.first;
        int e = sp.second;
        board[s] = e - s;
    }
    for (auto lp : ladders)
    {
        int s = lp.first;
        int e = lp.second;
        board[s] = e - s;
    }
    Graph g(n + 1);
    for (int u = 1; u < n; u++)
    {
        for (int dice = 1; dice < = 6; dice++)
        {
            int v = u + dice;
            v += board[v];
            if (v <= n)
            {
                g.addEdge(u, v);
            }
        }
    }
    return g.minCostbfs(1,n);
}

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.bfs(1, 6);
    return 0;
}
