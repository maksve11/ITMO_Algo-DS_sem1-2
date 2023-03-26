#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    int n;
    ifstream in("sortland.in");
    ofstream out("sortland.out");
    in >> n;
    double* arr = new double[n];
    double* arr1 = new double[n];
    for (int i = 0; i < n; i++)
        in >> arr[i];
    for (int i = 0; i < n; i++)
        arr1[i]=arr[i];
    double mini, sri, maxi;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    int i1 = 0, i2 = 0, i3 = 0;
    mini = arr[0];
    sri = arr[(n / 2)];
    maxi = arr[n-1];
    for (int i = 0; i < n; ++i)
    {
      if (arr1[i] == mini) i1 = i;
      if (arr1[i] == sri) i2 = i;
      if (arr1[i] == maxi) i3 = i;
    }
    out << i1 + 1 << " " << i2 + 1 << " " << i3 + 1;
    return 0;
}