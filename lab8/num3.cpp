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

    int check = 1;

    for (int i = 0; i < m; ++i)
    {
        in >> a >> b;
        graph[a - 1][b - 1]++;
        graph[b - 1][a - 1]++;
        if ((graph[a - 1][b - 1] + graph[b - 1][a - 1]) > 2)
        {
            check = 0;
            break;
        }
    }

    if (check == 0)
        out << "YES";
    else
        out << "NO";

    return 0;
}