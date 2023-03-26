#include <fstream> 
#include <vector>
#include <cmath>

using namespace std;

ifstream in("spantree.in");
ofstream out("spantree.out");

void spantree(int n, int vertex, vector<pair<int, int>> &koor, vector<double> &ver, double &length, vector<bool> &visited)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            double r = sqrt(pow(koor[vertex].first - koor[j].first, 2) + pow(koor[vertex].second - koor[j].second, 2));
            if (ver[j] == -1 || r < ver[j])
                ver[j] = r;
        }
        visited[vertex] = true;

        if (i == n)
            return;

        int min = -1;
        for (int j=0; j<n; j++)
        {
            if (visited[j])
                continue;
            if (min == -1 || ver[j] < ver[min])
                min = j;    
        }

        length += ver[min];
        vertex = min;    
    }
}

int main()
{
    int n, a, b;
    in >> n;

    vector<pair<int, int>> koor(n);
    vector<double> ver(n, -1);
    vector<bool> visited(n, false);

    for (int i=0; i<n; i++)
    {
        in >> a >> b;
        koor[i].first = a;
        koor[i].second = b;
    }

    double length = 0;
    
    spantree(n, 0, koor, ver, length, visited);
    
    out.precision(20);

    out << length;

    return 0;
}