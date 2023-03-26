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
    bool check();
};

Graph::Graph(int v)
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

bool Graph::check()
{
    for (int i = 0; i < result.size() - 1; i++)
    {
        int flag = 0;
        for (int t : adj[result[i]])
            if (t == result[i + 1])
                flag = 1;
        if (flag == 0)
            return false;
    }
    return true;
}

int main()
{
    ifstream in("hamiltonian.in");
    ofstream out("hamiltonian.out");
    int n, m, x, y;

    in >> n >> m;
    Graph g(n + 1);
    for (int i = 0; i < m; i++)
    {
        in >> x >> y;
        g.addEdge(x, y);
    }

    g.bigTopSort();
    bool flag = g.check();
    flag == 1 ? out << "YES" : out << "NO";
    return 0;
}