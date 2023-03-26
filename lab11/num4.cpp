#include <fstream>
#include <vector>

using namespace std;

struct Edge
{
    int to;
    long long weight;
};

const long long INF = 8e18;

void dfs1(int v, vector<bool> &visited, vector<vector<Edge>> &graph)
{
    visited[v] = true;
    for (auto &e : graph[v])
    {
        if (!visited[e.to])
        {
            dfs1(e.to, visited, graph);
        }
    }
}

void dfs2(int v, vector<bool> &neg_Cycle, vector<vector<Edge>> &graph)
{
    neg_Cycle[v] = true;
    for (auto &e : graph[v])
    {
        if (!neg_Cycle[e.to])
        {
            dfs2(e.to, neg_Cycle, graph);
        }
    }
}

void FordBellman(int n, vector<vector<Edge>> &graph, vector<long long> &dist, vector<bool> &visited, vector<bool> &neg_Cycle)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (auto &e : graph[j])
            {
                if (dist[j] + e.weight < dist[e.to])
                {
                    dist[e.to] = max(-INF, dist[j] + e.weight);
                    if (i == n - 1 && visited[e.to])
                    {
                        dfs2(e.to, neg_Cycle, graph);
                    }
                }
            }
        }
    }
}

int main()
{
    ifstream in("path.in");
    ofstream out("path.out");

    int n, m, s;

    in >> n >> m >> s;
    s--;

    vector<vector<Edge>> graph(n);
    vector<long long> dist(n, INF);
    vector<bool> neg_Cycle(n, false);
    vector<bool> visited(n, false);

    int from;
    Edge edge{};
    for (int i = 0; i < m; ++i)
    {
        in >> from >> edge.to >> edge.weight;
        edge.to--;
        graph[from - 1].push_back(edge);
    }

    dist[s] = 0;
    dfs1(s, visited, graph);
    FordBellman(n, graph, dist, visited, neg_Cycle);

    for (int i = 0; i < n; ++i)
    {
        if (neg_Cycle[i] || dist[i] < -INF)
        {
            out << "-\n";
        }
        else if (!visited[i])
        {
            out << "*\n";
        }
        else
        {
            out << dist[i] << "\n";
        }
    }

    return 0;
}