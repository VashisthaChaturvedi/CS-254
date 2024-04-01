#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

int dp_ans(vector<int> &w, vector<int> &v, int n, int W)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= W; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    return dp[n][W];
}

int main()
{
    // Taking input from input.in and giving output to output.out
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    ll t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {

        int n, W;
        cin >> n >> W;
        vector<int> weight(n), value(n);
        for (int i = 0; i < n; i++)
            cin >> weight[i];
        for (int i = 0; i < n; i++)
            cin >> value[i];
        int ans = dp_ans(weight, value, n, W);
        cout << "the max value possible by greedy approach in testcase " << tt << " is -> " << ans << endl;
        cout << endl;
    }
}