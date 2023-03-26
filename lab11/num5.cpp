#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;
const int NOEDGE = 100000;

ifstream in("negcycle.in");
ofstream out("negcycle.out");

struct edge
{
    int u, v, w;
};

void findNegativeCycle(int n, vector<edge> &edges)
{
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    int x;
    dist[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        x = -1;
        for (int j = 0; j < edges.size(); ++j)
        {
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = max(-INF, dist[u] + w);
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1)
    {
        out << "NO" << endl;
    }
    else
    {
        out << "YES" << endl;

        vector<int> cycle;
        int y = x;

        for (int i = 0; i < n; ++i)
        {
            y = parent[y];
        }

        for (int cur = y;; cur = parent[cur])
        {
            cycle.push_back(cur);
            if (cur == y && cycle.size() > 1)
                break;
        }

        reverse(cycle.begin(), cycle.end());

        out << cycle.size() << endl;

        for (int i = 0; i < cycle.size(); ++i)
        {
            out << cycle[i] + 1;
            if (i != cycle.size() - 1)
                out << " ";
        }

        out << endl;
    }
}

int main()
{
    int n;
    in >> n;

    vector<edge> edges;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int w;
            in >> w;
            if (w != NOEDGE)
            {
                edges.push_back({i, j, w});
            }
        }
    }

    findNegativeCycle(n, edges);

    return 0;
}