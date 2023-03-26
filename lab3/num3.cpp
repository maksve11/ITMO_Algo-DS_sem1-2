#include <bits/stdc++.h>
#include <fstream>
using namespace std;
void radixsort(vector<string> &arr, int m, int k)
{
    for (int i = 0; i < k; i++)
    {
        vector<int> count(26);
        vector<vector<string>> arrnew(26);
        for (int t = 0; t < arr.size(); t++)
        {
            count[arr[t][m - i - 1] - 'a']++;
            arrnew[arr[t][m - i - 1] - 'a'].push_back(arr[t]);
        }
        int pos = 0;
        for (int t = 0; t < 26; t++)
        {
            for (int j = 0; j < count[t]; j++)
                arr[pos++] = arrnew[t][j];
        }
    }
}
int main()
{
    ifstream in("radixsort.in");
    ofstream out("radixsort.out");
    int n, m, k;
    in >> n >> m >> k;
    vector<string> arr(n);
    for (int i = 0; i < arr.size(); i++)
        in >> arr[i];
    radixsort(arr, m, k);
    for (auto it : arr)
        out << it << '\n';
    return 0;
}