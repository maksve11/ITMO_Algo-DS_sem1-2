#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    int n;
    ifstream in("smallsort.in");
    ofstream out("smallsort.out");
    in >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        in >> arr[i];
    int tmp;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    for (int i = 0; i < n; ++i)
        out << arr[i] << " ";
    return 0;
}