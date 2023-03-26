#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    multimap <int, int> a,b;
    int n, m, x, y;
    in >> n >> m;
    for (int i=0; i<m; i++)
    {
        in >> x >> y;
        a.insert(make_pair(x, y));
        b.insert(make_pair(y, x));
    }
    a.merge(b);
    for (int i=1; i<=n; i++)
    {
        out << a.count(i) << " ";
    }
    return 0;
}