#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
void mergesort(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid;
    int* Left = new int[n1];
    int* Right = new int[n2];
    for (int i = 0; i < n1; i++)
        Left[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];
    int i=0, j=0, k = left;
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
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
void sort(int arr[], int l, int r)
{
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    sort(arr, l, mid);
    sort(arr, mid + 1, r);
    mergesort(arr, l, mid, r);
}
int main()
{
    int n;
    ifstream in("sort.in");
    ofstream out("sort.out");
    in >> n;
    int* arr1 = new int[n];
    for (int i = 0; i < n; i++)
        in >> arr1[i];
    sort(arr1, 0, n-1);
    for (int i = 0; i < n; i++)
        out << arr1[i] << " ";
    return 0;
}