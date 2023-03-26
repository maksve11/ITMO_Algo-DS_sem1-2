#include <iostream>
#include <fstream>
using namespace std;
void buildheap(int a[], int n, int i)
{
    int larg = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] > a[larg])
        larg = l;
    if (r < n && a[r] > a[larg])
        larg = r;
    if (larg != i)
    {
        swap(a[i], a[larg]);
        buildheap(a, n, larg);
    }
}
void sort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        buildheap(a, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        buildheap(a, i, 0);
    }
}
int main()
{
    int n;
    ifstream in("sort.in");
    ofstream out("sort.out");
    in >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        in >> arr[i];
    sort(arr, n);
    for (int i = 0; i < n; i++)
        out << arr[i] << " ";
    return 0;
}