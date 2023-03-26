#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int find_set(int x, vector<int> &parent)
{
    return (x == parent[x]) ? x : parent[x] = find_set(parent[x], parent);
}

void unite_set(int x, int y, vector<int> &parent)
{
    x = find_set(x, parent);
    y = find_set(y, parent);

    if (x == y)
        return;

    if (x < y)
        swap(x, y);

    parent[x] = y;
}

int main()
{
    ifstream in("spantree3.in");
    ofstream out("spantree3.out");

    int n, m, x, y, len, s = 0;
    long long result = 0;

    in >> n >> m;

    vector<int> parent(n+1);

    for (int i = 1; i <= n; ++i)
        parent[i] = i;
        
    pair<int, pair<int, int>> graph[m];

    for (int i = 0; i < m; ++i)
    {
        in >> x >> y >> len;
        graph[i] = make_pair(len, make_pair(x, y));
    }

    sort(graph, graph + m);

    for (int i = 0; i < m && s < n - 1; ++i)
    {
        x = find_set(graph[i].second.first, parent);
        y = find_set(graph[i].second.second, parent);
        if (x != y)
        {
            result += graph[i].first;
            s++;
            unite_set(x, y, parent);
        }
    }

    out << result;
    return 0;
}