#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int Kpor(vector<int> &arr, int k, int l=0, int r=-1)
{
    if (r==-1) r = arr.size() - 1, l=0;
    int i=l, j=r, pivot, buf;
    pivot = arr[(l + r) / 2];
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (pivot < arr[j])
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if ((k <= j) && (l <= k))
    {
        return Kpor(arr, k, l, j);
    }
    else if ((i <= k) && (k <= r))
    {
        return Kpor(arr, k, i, r);
    }
    else
        return arr[j + 1];
}
int main()
{
    ifstream in("kth.in");
    ofstream out("kth.out");
    int n, k, a, b, c;
    in >> n >> k;
    vector<int> arr(n);
    in >> a >> b >> c;
    for (int i = 0; i <= 1; i++)
        in >> arr[i];
    for (int i = 2; i < n; i++)
        arr[i] = a * arr[i - 2] + b * arr[i - 1] + c;
    out << Kpor(arr, k - 1);
    return 0;
}