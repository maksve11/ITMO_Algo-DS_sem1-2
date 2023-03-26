#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("knapsack.in");
    ofstream out("knapsack.out");

    int s, n;

    in >> s >> n;

    vector<int> arr(n);
    vector<int> weight(10010, 0);
    weight[0] = 1;

    for (int i = 0; i < n; i++)
    {
        in >> arr[i];
        for (int j = s; j >= arr[i]; j--)
            if (weight[j - arr[i]] == 1)
                weight[j] = 1;
    }

    int j;
    for (j = s;; j--)
        if (weight[j] > 0)
            break;

    out << j;

    return 0;
}