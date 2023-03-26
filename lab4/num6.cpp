#include <bits/stdc++.h>
using namespace std;
double ans;
vector<double> lamp;
bool check(double secondlamp)
{
    lamp[1] = secondlamp;
    for (int i = 2; i < lamp.size(); ++i)
    {
        lamp[i] = 2.0 * lamp[i - 1] + 2.0 - lamp[i - 2];
        if (lamp[i] < 0)
        {
            return false;
        }
    }
    ans = lamp[lamp.size() - 1];
    return true;
}

void binp(double l, double r)
{
    while (r - l > 0.000000000001)
    {
        double mid = (r + l) / 2.0;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
}
int main()
{
    ifstream in("garland.in");
    ofstream out("garland.out");
    int n;
    in >> n;
    lamp.resize(n);
    double firstlamp;
    in >> firstlamp;
    lamp[0] = firstlamp;
    binp(0.0, firstlamp);
    out << setprecision(2) << fixed << ans << endl;
    return 0;
}