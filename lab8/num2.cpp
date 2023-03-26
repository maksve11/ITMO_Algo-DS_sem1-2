#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int n, a, b;
    vector<vector<int>> graph;

    ifstream in("input.txt");
    ofstream out("output.txt");

    in.tie(NULL)->sync_with_stdio(false);

    in >> n;
    graph.resize(n);

    int check = 0;

    for (int i = 0; i < n; ++i)
    {
        graph[i].resize(n);
        for (int j = 0; j < n; ++j)
        {
            in >> graph[i][j];
            if (graph[i][j] == 1)
                check++;
        }
    }

    if (check % 2 == 0)
        out << "YES";
    else
        out << "NO";

    return 0;
}