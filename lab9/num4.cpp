#include <bits/stdc++.h>

using namespace std;

void firstdfs(int v, vector<vector<int>> &g, vector<bool> &visited, vector<int> &ord)
{
    visited[v] = true;
    for (int t : g[v])
    {
        if (!visited[t])
        {
            firstdfs(t, g, visited, ord);
        }
    }
    ord.push_back(v);
}

void seconddfs(int v, vector<vector<int>> &g, vector<bool> &used, vector<int> &comp)
{
    used[v] = true;
    comp.push_back(v);
    for (int t : g[v])
    {
        if (!used[t])
        {
            seconddfs(t, g, used, comp);
        }
    }
}

int main()
{
    ifstream in("cond.in");
    ofstream out("cond.out");

    int n, m, x, y;

    in >> n >> m;

    vector<vector<int>> g(n);
    vector<vector<int>> h(n);

    vector<bool> visited(n, false);
    vector<bool> used(n, false);

    vector<int> ord, comp;
    vector<int> cond(n);

    for (int i = 0; i < m; i++)
    {
        in >> x >> y;
        g[x - 1].push_back(y - 1);
        h[y - 1].push_back(x - 1);
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            firstdfs(i, g, visited, ord);
    }

    int count = 1;

    for (int i = 0; i < n; i++)
    {
        int t = ord[n - 1 - i];
        if (!used[t])
        {
            seconddfs(t, h, used, comp);
            for (int i = 0; i < size(comp); i++)
                cond[comp[i]] = count;
            count++;
            comp.clear();
        }
    }

    out << count - 1 << endl;
    for (int i = 0; i < n; i++)
        out << cond[i] << " ";

    return 0;
}