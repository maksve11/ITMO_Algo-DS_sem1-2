#include <bits/stdc++.h>

using namespace std;

vector<int> visited;
vector<vector<int>> graph;
int part = 1;

void dfs(int v, int color)
{
    visited[v] = color;

    if (color == 1)
        color = 2;
    else
        color = 1;

    for (int i = 0; i < graph[v].size(); i++)
    {
        int t = graph[v][i];
        if (visited[t] == 0)
        {
            dfs(t, color);
        }
        else if (visited[t] == visited[v])
        {
            part = 0;
            return;
        }
    }
}

int main()
{
    ifstream in("bipartite.in");
    ofstream out("bipartite.out");
    int n, m, x, y;
    in >> n >> m;

    graph.resize(n);
    visited.resize(n);

    for (int i = 0; i < m; i++)
    {
        in >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int curcolor = 1;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, curcolor);
        }
    }

    part == 1 ? out<<"YES" : out<<"NO";
    return 0;
}