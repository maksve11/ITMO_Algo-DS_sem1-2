#include <bits/stdc++.h>

using namespace std;
const int INF = INT_MAX;

vector<int> way(vector<vector<pair<int, int>>> &graph, int start, int n)
{
    vector<int> dist(n, INF), parent(n);
    dist[start] = 0;
    vector<bool> visited(n);

    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!visited[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        if (dist[v] == INF)
            break;
        visited[v] = true;

        for (size_t j = 0; j < graph[v].size(); j++)
        {
            int to = graph[v][j].first, result = graph[v][j].second;
            if (dist[v] + result < dist[to])
            {
                dist[to] = dist[v] + result;
                parent[to] = v;
            }
        }
    }

    return dist;
}

int main()
{
    int n, m, x, y, w;
    ifstream in("pathsg.in");
    ofstream out("pathsg.out");
    in >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++)
    {
        in >> x >> y >> w;
        graph[x - 1].push_back(make_pair(y - 1, w));
    }
    vector<int> result(n);

    for (int i = 0; i < n; i++)
    {
        result = way(graph, i, n);
        for (int j = 0; j < result.size(); j++)
            out << result[j] << " ";
        out << '\n';
    }

    return 0;
}