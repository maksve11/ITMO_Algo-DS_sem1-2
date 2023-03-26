#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ifstream in("pathbge1.in");
    ofstream out("pathbge1.out");

    in.tie(NULL)->sync_with_stdio(false);

    int n, m, a, b;
    vector<vector<int>> graph;
    queue<int> q;
    vector<int> dis;

    in >> n >> m;
    graph.resize(n);
    dis.resize(n);

    for (int i = 0; i < m; ++i)
    {
        in >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; ++i)
    {
        dis[i] = INT_MAX;
    }

    q.push(0);
    dis[0] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto j : graph[v])
        {
            if (dis[j] == INT_MAX)
            {
                q.push(j);
                dis[j] = dis[v] + 1;
            }
        }
    }

    for (auto i : dis)
    {
        out << i << " ";
    }

    return 0;
}