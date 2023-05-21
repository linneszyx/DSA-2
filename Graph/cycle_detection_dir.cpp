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
    void addEdge(int i, int j)
    {
        l[i].push_back(j);
    }
    bool dfs(int node, vector<bool> &visited, vector<bool> &stack)
    {
        visited[node] = true;
        stack[node] = true;
        for (auto nbr : l[node])
        {
            if (stack[nbr])
                return true;
            else if (!visited[nbr])
            {
                bool cycle = dfs(nbr, visited, stack);
                if (cycle)
                    return true;
            }
        }
        stack[node] = false;
        return false;
    }
    bool contains_cycle()
    {
        vector<bool> visited(V, false);
        vector<bool> stack(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, stack))
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    if (g.contains_cycle())
        cout << "Cycle Exits";
    else
        cout << "Cycle Doesn't Exist";
    return 0;
}