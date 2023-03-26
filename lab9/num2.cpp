#include <fstream>
#include <vector>

using namespace std;

class Graph
{
    int Vertex;
    vector<int> *adj;
    bool smallCycle(int v);

public:
    int *visited;
    int *way;
    int startCycle, endCycle;
    Graph(int v);
    void addEdge(int a, int b);
    bool bigCycle();
};

Graph::Graph(int v)
{
    this->Vertex = v;
    adj = new vector<int>[Vertex];
    visited = new int[Vertex];
    way = new int[Vertex];
}

void Graph::addEdge(int a, int b)
{
    adj[a].push_back(b);
}

bool Graph::smallCycle(int v)
{
    this->visited[v] = 1;
    for (int i = 0; i < adj[v].size(); ++i)
    {
        int t = adj[v][i];
        if (this->visited[t] == 0)
        {
            this->way[t] = v;
            if (smallCycle(t))
                return true;
        }
        else if (this->visited[t] == 1)
        {
            this->endCycle = v;
            this->startCycle = t;
            return true;
        }
    }
    this->visited[v] = 2;
    return false;
}

bool Graph::bigCycle()
{
    for (int i = 0; i < Vertex; i++)
    {
        this->visited[i] = 0;
        this->way[i] = -1;
    }

    for (int i = 1; i < Vertex; i++)
        if (smallCycle(i))
            return true;

    return false;
}

int main()
{
    ifstream in("cycle.in");
    ofstream out("cycle.out");
    int n, m, x, y;
    in >> n >> m;
    Graph g(n + 1);
    for (int i = 0; i < m; i++)
    {
        in >> x >> y;
        g.addEdge(x, y);
    }
    bool flag = g.bigCycle();
    int start = g.startCycle;
    if (flag == 1)
    {
        out << "YES" << endl;
        out << g.endCycle << " ";
        while (start != g.endCycle)
        {
            for (int i = 0; i < n + 1; i++)
            {
                if (g.way[i] == start)
                {
                    start = i;
                    out << g.way[i] << ' ';
                }
            }
        }
    }
    else
        out << "NO";
    return 0;
}