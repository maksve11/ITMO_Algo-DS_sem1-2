#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void mergesort(vector<pair<string, string>>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid;
    vector<pair<string, string>> Left(n1);
    vector<pair<string, string>> Right(n2);
    for (int i = 0; i < n1; i++)
        Left[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + j + 1];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (Left[i].first <= Right[j].first)
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}
void sortirovochka(vector<pair<string, string>>& arr, int l, int r)
{
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    sortirovochka(arr, l, mid);
    sortirovochka(arr, mid + 1, r);
    mergesort(arr, l, mid, r);
}
int main()
{
    int n;
    vector<pair<string, string>> gg;
    ifstream in("race.in");
    ofstream out("race.out");
    in >> n;
    string country, name;
    for (int i = 0; i < n; i++)
    {
        in >> country >> name;
        gg.push_back(make_pair(country, name));
    }
    sortirovochka(gg, 0, gg.size() - 1);
    country = gg[0].first;
    out << "=== " << country << " ===" << endl;
    for (const auto& it : gg)
    {
        if (country != it.first)
        {
            country = it.first;
            out << "=== " << country << " ===" << endl;
        }
        out << it.second << endl;
    }
    return 0;
}