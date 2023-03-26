#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> get_children(vector<vector<int>> &tree, short v)
{
    return tree[v];
}
 
vector<int> get_grandchildren(vector<vector<int>> &tree, short v)
{
    vector<int> result;
    vector<int> children = get_children(tree, v);
 
    for (int i = 0; i < children.size(); ++i)
    {
        for (int j = 0; j < tree[children[i]].size(); ++j)
        {
            result.push_back(tree[children[i]][j]);
        }
    }
 
    return result;
}
 
long long solve(vector<vector<int>> &tree, vector<int> &dp, int root)
{
    if (dp[root] != -1)
        return dp[root];
 
    int childrenSum = 0, grandchildrenSum = 0;
 
    vector<int> children = get_children(tree, root);
    vector<int> grandchildren = get_grandchildren(tree, root);
 
    for (int i = 0; i < children.size(); ++i)
    {
        childrenSum += solve(tree, dp, children[i]);
    }
 
    for (int i = 0; i < grandchildren.size(); ++i)
    {
        grandchildrenSum += solve(tree, dp, grandchildren[i]);
    }
 
    dp[root] = max(int(1 + grandchildrenSum), childrenSum);
    return dp[root];
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int n;
    cin >> n;
 
    vector<vector<int>> tree(n);
    int v, root;
 
    for (int i = 0; i < n; ++i)
    {
        cin >> v;
 
        if (v == 0)
        {
            root = i;
            continue;
        }
 
        tree[v - 1].push_back(i);
    }
 
    if (n == 1)
    {
        cout << 1 << '\n';
        return 0;
    }
 
    // dp[i] -- number of vertices in considering set with root i
    vector<int> dp(n, -1);
 
    cout << solve(tree, dp, root) << '\n';
 
    return 0;
}