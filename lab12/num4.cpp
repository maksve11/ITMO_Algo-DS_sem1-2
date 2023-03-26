#include <fstream>
#include <vector>

using namespace std;

int n, m;

long long solve(int i, int j, vector<vector<long long>> &dp)
{
    if ((i >= 0 && i < n) && (j >= 0 && j < m))
    {
        if (dp[i][j] == -1)
            dp[i][j] = solve(i - 2, j - 1, dp) + solve(i - 2, j + 1, dp) + solve(i - 1, j - 2, dp) + solve(i + 1, j - 2, dp);
    }
    else
        return 0;
    return dp[i][j];
}

int main()
{
    ifstream in("knight2.in");
    ofstream out("knight2.out");
    in >> n >> m;

    vector<vector<long long>> dp;
    dp.resize(n, vector<long long>(m, -1));

    dp[0][0] = 1;

    out << solve(n - 1, m - 1, dp);
}