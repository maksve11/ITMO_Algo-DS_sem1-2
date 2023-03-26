#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    unsigned n;
    cin >> n;
    vector<pair<int, int>> arr(n, {0, n});

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first; 
    }

    vector<int> dp(n + 1, INT_MAX), pos(n + 1, -1);
    int length;
    dp[0] = -(INT_MAX);

    for (int i = 0; i < n; ++i)
    {
        length = static_cast<int>(upper_bound(dp.begin(), dp.end(), arr[i].first) - dp.begin());
        if (dp[length - 1] < arr[i].first)
        {
            dp[length] = arr[i].first;
            pos[length] = i;
            arr[i].second = pos[length - 1];
        }
    }

    vector<int> ans;
    int p = static_cast<int>(lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin()) - 1;

    cout << p << endl;

    ans.push_back(arr[pos[p]].first);
    p = arr[pos[p]].second;

    while (p != -1)
    {
        ans.push_back(arr[p].first);
        p = arr[p].second;
    }

    reverse(ans.begin(), ans.end());

    for (auto &k : ans)
    {
        cout << k << " ";
    }

    return 0;
}