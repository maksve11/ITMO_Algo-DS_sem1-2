#include <bits/stdc++.h>

using namespace std;
const int INF = INT_MAX;

vector<int> way(vector<vector<pair<int, int>>> &graph, int start, int n)
{
    vector<int> dist(n, INF), parent(n);
    dist[start] = 0;
    set<pair<int, int>> q;
    q.insert(make_pair(dist[start], start));
    while (!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (size_t j = 0; j < graph[v].size(); j++)
        {
            int to = graph[v][j].first, result = graph[v][j].second;
            if (dist[v] + result < dist[to])
            {
                q.erase(make_pair(dist[to], to));
                dist[to] = dist[v] + result;
                parent[to] = v;
                q.insert(make_pair(dist[to], to));
            }
        }
    }
    return dist;
}

int main()
{
    int n, m, x, y, w;
    ifstream in("pathbgep.in");
    ofstream out("pathbgep.out");
    in >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++)
    {
        in >> x >> y >> w;
        graph[x - 1].push_back(make_pair(y - 1, w));
        graph[y - 1].push_back(make_pair(x - 1, w));
    }
    vector<int> result(n);
    result = way(graph, 0, n);

    for (int i = 0; i < result.size(); i++)
    {   
        if (result[i] == INF)
            out << 0 << " ";
        else
            out << result[i] << " ";    
    }

    return 0;
}