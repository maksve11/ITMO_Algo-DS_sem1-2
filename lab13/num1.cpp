#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> naive_search(const string &t, const string &p)
{
    int n = (int)t.size();
    int m = (int)p.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == p[0])
        {
            if (m != 1)
                for (int j = 1; j < m; j++)
                {
                    if (t[i + j] == p[j])
                    {
                        if (j == m - 1)
                            ans.push_back(i);
                        continue;
                    }
                    else
                        break;
                }
            else
                ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    ifstream in("search1.in");
    ofstream out("search1.out");

    string p, t;
    in >> p >> t;

    vector<int> ans = naive_search(t, p);
    out << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        out << ++ans[i] << " ";
    }

    return 0;
}