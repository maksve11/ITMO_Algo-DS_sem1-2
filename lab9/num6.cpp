#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int Vertex;
    list<int> *adj;
    vector<int> result;
    void smallTopSort(int v, bool visited[], stack<int> &stack);

public:
    Graph(int v);
    void addEdge(int a, int b);
    void bigTopSort();
    bool check(int start);
    vector<bool> firstWin;
};

Graph::Graph(int v) : firstWin(v, false)
{
    this->Vertex = v;
    adj = new list<int>[Vertex];
}

void Graph::addEdge(int a, int b)
{
    adj[a].push_back(b);
}

void Graph::smallTopSort(int v, bool visited[], stack<int> &stack)
{
    visited[v] = true;
    for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            smallTopSort(*i, visited, stack);
    stack.push(v);
}

void Graph::bigTopSort()
{
    stack<int> stack;
    bool *visited = new bool[Vertex];

    for (int i = 0; i < Vertex; i++)
        visited[i] = false;

    for (int i = 0; i < Vertex; i++)
        if (visited[i] == false)
            smallTopSort(i, visited, stack);

    while (stack.empty() == false)
    {
        if (stack.top() != 0)
        {
            result.push_back(stack.top());
            stack.pop();
        }
        else
        {
            stack.pop();
        }
    }
}

bool Graph::check(int start)
{
    for (int i = result.size() - 1; i >= 0; i--)
    {
        int t = result[i];
        if (adj[t].size() == 0)
            firstWin[t] == false;
        else
            for (int j = i + 1; j < result.size(); j++)
            {
                for (int v : adj[result[i]])
                    if (firstWin[v] == false)
                    {
                        firstWin[result[i]] = true;
                        break;
                    }
            }
    }
    if (firstWin[start] == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    ifstream in("game.in");
    ofstream out("game.out");
    int n, m, x, y, start;

    in >> n >> m >> start;
    Graph g(n + 1);
    for (int i = 0; i < m; i++)
    {
        in >> x >> y;
        g.addEdge(x, y);
    }

    g.bigTopSort();
    bool flag = g.check(start);

    flag == 1 ? out << "First player wins" : out << "Second player wins";
    return 0;
}