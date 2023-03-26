#include <fstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxFlow;

bool bfs(vector<vector<int>> &graph, vector<int> &parent, int source, int sink, int n)
{
    vector<bool> visited(n);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int from = q.front();
        q.pop();
        for (int to = 0; to < n; to++)
        {
            if (!visited[to] && graph[from][to] > 0)
            {
                q.push(to);
                parent[to] = from;
                visited[to] = true;
            }
        }
    }
    return visited[sink];
}

void edmondsKarp(vector<vector<int>> &graph, vector<int> &parent, int source, int sink, int n)
{
    while (bfs(graph, parent, source, sink, n))
    {
        int partFlow = INT_MAX;
        for (int to = sink; to != source; to = parent[to])
        {
            int from = parent[to];
            partFlow = min(partFlow, graph[from][to]);
        }
        for (int to = sink; to != source; to = parent[to])
        {
            int from = parent[to];
            graph[from][to] -= partFlow;
            graph[to][from] += partFlow;
        }
        maxFlow += partFlow;
    }
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    ifstream in("maxflow.in");
    ofstream out("maxflow.out");

    int n, m;
    in >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<int> parent(n, -1);

    for (int i = 0; i < m; i++)
    {
        int from, to, flow;
        in >> from >> to >> flow;
        graph[from - 1][to - 1] = flow;
    }

    edmondsKarp(graph, parent, 0, n - 1, n);
    
    out << maxFlow;
    return 0;
}