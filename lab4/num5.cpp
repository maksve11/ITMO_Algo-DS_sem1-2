#include <bits/stdc++.h>
using namespace std;
int binfind(int arr[], int n, int key, bool leftsearch)
{
    int notf = -1;
    if (arr[0] > key || arr[n - 1] < key)
        return notf;
    int leftpoint = -1;
    int rightpoint = n + 1;
    while (rightpoint - leftpoint > 1)
    {
        int mid = (rightpoint + leftpoint) / 2;
        if (leftsearch ? arr[mid] < key : arr[mid] <= key)
            leftpoint = mid;
        else
            rightpoint = mid;
    }
    if (leftsearch ? arr[rightpoint] == key : arr[rightpoint - 1] == key)
        return leftsearch ? rightpoint + 1 : rightpoint;
    return notf;
}
int main()
{
    ifstream in("binsearch.in");
    ofstream out("binsearch.out");
    int n, m;
    in >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        in >> arr[i];
    in >> m;
    int *con = new int[m];
    for (int i = 0; i < m; i++)
        in >> con[i];
    for (int i = 0; i < m; ++i)
    {
        out << binfind(arr, n - 1, con[i], true) << " " << binfind(arr, n - 1, con[i], false) << endl;
    }
    return 0;
}