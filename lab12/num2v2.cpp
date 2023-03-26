#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool kuhn(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &matching, int from)
{
    if (visited[from])
        return false;
    visited[from] = true;
    for (int i = 0; i < graph[from].size(); i++)
    {
        int to = graph[from][i];
        if (matching[to] == -1 || kuhn(graph, visited, matching, matching[to]))
        {
            matching[to] = from;
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream in("matching.in");
    ofstream out("matching.out");

    int nfirst, nsecond, e;

    in >> nfirst >> nsecond >> e;

    vector<vector<int>> graph(nfirst, vector<int>());
    vector<int> matching(nsecond, -1);
    vector<bool> visited(nfirst);
    vector<bool> used(nfirst);

    for (int i = 0; i < e; i++)
    {
        int from, to;
        in >> from >> to;
        graph[from - 1].push_back(to - 1);
    }

    for (int i = 0; i < nfirst; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
            if (matching[graph[i][j]] == -1)
            {
                matching[graph[i][j]] = i;
                used[i] = true;
                break;
            }
    }

    for (int i = 0; i < nfirst; i++)
    {
        if (used[i])
            continue;
        for (int j = 0; j < nfirst; j++)
            visited[j] = false;
        kuhn(graph, visited, matching, i);
    }

    int value = 0;
    for (int i = 0; i < nsecond; i++)
        if (matching[i] != -1)
            value++;

    out << value;
    return 0;
}