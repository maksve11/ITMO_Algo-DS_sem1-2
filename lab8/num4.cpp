#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> used;

void dfs(int compcount, int pos)
{
    used[pos] = compcount;
    for (auto i : graph[pos])
    {
        if (used[i] == 0)
        {
            dfs(compcount, i);
        }
    }
}

int main()
{
    ifstream in("components.in");
    ofstream out("components.out");

    in.tie(NULL)->sync_with_stdio(false);

    int n, m, a, b;

    in >> n >> m;
    graph.resize(n);
    used.resize(n);

    for (int i = 0; i < m; ++i)
    {
        in >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    int compcount = 1;

    for (int i = 0; i < n; ++i)
    {
        if (used[i] == 0)
        {
            dfs(compcount, i);
            ++compcount;
        }
    }

    out << compcount - 1 << endl;

    for (auto i : used)
    {
        out << i << " ";
    }

    return 0;
}