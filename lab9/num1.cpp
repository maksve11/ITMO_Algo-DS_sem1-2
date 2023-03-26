#include <fstream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
    int Vertex;
    list<int> *adj;

    bool smallCycle(int v, bool visited[], bool *greyStack);
    void smallTopSort(int v, bool visited[], stack<int> &check);

public:
    Graph(int V);
    void addEdge(int v, int a);
    bool bigCycle();
    void bigTopSort();
};

Graph::Graph(int V)
{
    this->Vertex = V;
    adj = new list<int>[Vertex];
}

void Graph::addEdge(int v, int a)
{
    adj[v].push_back(a);
};

bool Graph::smallCycle(int v, bool visited[], bool *greyStack)
{
    if (visited[v] == false)
    {
        visited[v] = true;
        greyStack[v] = true;

        for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i] && smallCycle(*i, visited, greyStack))
                return true;
            else if (greyStack[*i])
                return true;
        }
    }
    greyStack[v] = false;
    return false;
};

void Graph::smallTopSort(int v, bool visited[], stack<int> &check)
{
    visited[v] = true;
    for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
            smallTopSort(*i, visited, check);
    }
    check.push(v);
};

bool Graph::bigCycle()
{
    bool *visited = new bool[Vertex];
    bool *greyStack = new bool[Vertex];

    for (int i = 0; i < Vertex; i++)
    {
        visited[i] = false;
        greyStack[i] = false;
    }

    for (int i = 0; i < Vertex; i++)
        if (smallCycle(i, visited, greyStack))
            return true;

    return false;
};

void Graph::bigTopSort()
{
    stack<int> check;
    bool *visited = new bool[Vertex];

    for (int i = 0; i < Vertex; i++)
        visited[i] = false;

    for (int i = 0; i < Vertex; i++)
        if (visited[i] == false)
            smallTopSort(i, visited, check);

    ofstream out("topsort.out");

    while (check.empty() == false)
    {
        if (check.top() != 0)
        {
            out << check.top() << " ";
            check.pop();
        }
        else
        {
            check.pop();
            out.close();
        }
    }
};

int main()
{
    ifstream in("topsort.in");

    int n, m, x, y;
    in >> n >> m;
    Graph g(n + 1);

    for (int i = 0; i < m; i++)
    {
        in >> x >> y;
        g.addEdge(x, y);
    }

    if (g.bigCycle() == true)
    {
        ofstream out("topsort.out");
        out << -1;
    }
    else
    {
        g.bigTopSort();
    }

    return 0;
}