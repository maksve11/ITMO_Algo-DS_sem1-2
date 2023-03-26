#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

int main()
{
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int dist[n], prev[n];

    for (int i = 0; i < n; ++i)
    {
        dist[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; ++j)
            if (arr[j] < arr[i])
                if (1 + dist[j] > dist[i])
                {
                    dist[i] = 1 + dist[j];
                    prev[i] = j;
                }
    }

    int ans = dist[0], pos = 0;

    for (int i = 0; i < n; ++i)
        if (dist[i] > ans)
        {
            ans = dist[i];
            pos = i;
        }
    cout << ans << endl;

    vector<int> path;
    while (pos != -1)
    {
        path.push_back(arr[pos]);
        pos = prev[pos];
    }

    reverse(path.begin(), path.end());
    for (int i = 0; i < (int)path.size(); ++i)
        cout << path[i] << ' ';

    return 0;
}