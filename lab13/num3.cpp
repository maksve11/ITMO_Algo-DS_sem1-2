#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> get_prefix(const string &str)
{
    int n = (int)str.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++)
    {
        int k = p[i - 1];
        while (k > 0 & str[i] != str[k])
            k = p[k - 1];
        if (str[i] == str[k])
            k++;
        p[i] = k;
    }
    return p;
}

int main()
{
    ifstream in("prefix.in");
    ofstream out("prefix.out");

    string str;
    in >> str;
    vector<int> p = get_prefix(str);

    for (int i = 0; i < p.size(); i++)
        out << p[i] << ' ';
    return 0;
}