#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, s, f, a;
    long long INF = LLONG_MAX;
    ifstream in("pathmgep.in");
    ofstream out("pathmgep.out");
    in >> n >> s >> f;
    s--;
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            in >> a;
            if (a != -1)
                graph[i].push_back(make_pair(j, a));
        }

    vector<long long> dist(n, INF), parent(n);
    dist[s] = 0;
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
            long long to = graph[v][j].first, result = graph[v][j].second;
            if (dist[v] + result < dist[to])
            {
                dist[to] = dist[v] + result;
                parent[to] = v;
            }
        }
    }

    if (dist[f - 1] == INF)
        out << -1;
    else
        out << dist[f - 1];
    return 0;
}