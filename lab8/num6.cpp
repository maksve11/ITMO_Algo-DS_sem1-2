#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    in.tie(NULL)->sync_with_stdio(false);

    vector<vector<int>> graph;
    queue<pair<int, int>> q;
    vector<pair<int, int>> mb;
    vector<vector<pair<int, int>>> p;
    vector<vector<int>> d;
    vector<char> score;
    int n, m;
    char a;
    pair<int, int> f, k;

    in >> n >> m;

    graph.resize(n);
    d.resize(n);
    p.resize(n);

    for (int i = 0; i < n; ++i)
    {
        d[i].resize(m);
        p[i].resize(m);
        graph[i].resize(m);
    }

    int startX, startY, finalX, finalY;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            in >> a;
            if (a == '.')
            {
                graph[i][j] = 1;
            }
            else if (a == '#')
            {
                graph[i][j] = 0;
            }
            else if (a == 'S')
            {
                startX = i;
                startY = j;
                graph[i][j] = 1;
            }
            else if (a == 'T')
            {
                finalX = i;
                finalY = j;
                graph[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            d[i][j] = 1e+8;
        }
    }

    q.push({startX, startY});
    d[startX][startY] = 0;

    while (!q.empty())
    {
        f = q.front();
        mb.emplace_back(f.first + 1, f.second);
        mb.emplace_back(f.first - 1, f.second);
        mb.emplace_back(f.first, f.second + 1);
        mb.emplace_back(f.first, f.second - 1);
        q.pop();
        for (auto j : mb)
        {
            if ((j.first >= 0) && (j.first <= n - 1))
            {
                if ((j.second >= 0) && (j.first <= n - 1))
                {
                    if (graph[j.first][j.second] == 1)
                    {
                        if (d[j.first][j.second] == 1e+8)
                        {
                            q.push(j);
                            p[j.first][j.second] = f;
                            d[j.first][j.second] = d[f.first][f.second] + 1;
                        }
                    }
                }
            }
        }
        mb.clear();
    }

    int check = 1;

    if (d[finalX][finalY] == 1e+8)
    {
        out << -1 << '\n';
        check = 0;
    }
    else
    {
        out << d[finalX][finalY] << '\n';
    }

    while ((finalX != startX) || (finalY != startY))
    {
        k = p[finalX][finalY];
        if (k.first < finalX)
        {
            score.push_back('D');
        }
        if (k.first > finalX)
        {
            score.push_back('U');
        }
        if (k.second < finalY)
        {
            score.push_back('R');
        }
        if (k.second > finalY)
        {
            score.push_back('L');
        }
        finalX = k.first;
        finalY = k.second;
    }

    reverse(score.begin(), score.end());

    if (check == 1)
    {
        for (auto i : score)
        {
            out << i;
        }
    }

    return 0;
}