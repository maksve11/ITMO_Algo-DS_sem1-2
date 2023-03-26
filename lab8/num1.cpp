#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int n, m, a, b;
    vector<vector<int>> graph;

    ifstream in("input.txt");
    ofstream out("output.txt");

    in.tie(NULL)->sync_with_stdio(false);

    in >> n >> m;
    graph.resize(n);

    for (int i = 0; i < n; ++i)
    {
        graph[i].resize(n);
    }

    for (int i = 0; i < m; ++i)
    {
        in >> a >> b;
        graph[a - 1][b - 1] = 1;
    }

    for (int i = 0; i < n; ++i)
    {
        for (auto j : graph[i])
        {
            out << j << " ";
        }
        out << endl;
    }

    return 0;
}