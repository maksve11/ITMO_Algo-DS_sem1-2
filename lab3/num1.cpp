#include <fstream>
using namespace std;
int main()
{
    int n;
    ifstream in("isheap.in");
    ofstream out("isheap.out");
    in >> n;
    bool flag = 1;
    long long *arr = new long long[n];
    for (int i = 1; i <= n; ++i)
        in >> arr[i];
    for (int i = 1; i <= n / 2; ++i)
    {
        if (2 * i < n && arr[2 * i] < arr[i])
            flag = 0;
        if (2 * i + 1 < n && arr[2 * i + 1] < arr[i])
            flag = 0;
    }
    if (flag == 1)
        out << "YES";
    else
        out << "NO";
    return 0;
}