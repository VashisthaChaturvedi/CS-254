#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#include <ctime>

void solve();
int main()
{
    clock_t t;
    t = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inputQ2.in", "r", stdin);
    freopen("outputQ2.out", "w", stdout);
    // Reading input files.
    // Printing the output in output file.
#endif
    solve();
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
#ifndef ONLINE_JUDGE
    cout << endl
         << "::" << time_taken;
#endif
}
void solve()
{
    int n;
    cin >> n;
    vector<int> weight(n);
    vector<int> values(n);
    // 2 vectors for storing the weight and respective values of the items

    int maxWgt;
    cin >> maxWgt;
    // maximum weight allowed to carry in knapsack 

    vector<vector<int>> dp_table((n + 1), vector<int>(maxWgt + 1, 0));
    // for storing the possible weight and values of ithe item.

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWgt; j++)
        {
            dp_table[i][j] = dp_table[i - 1][j];
            // we know that atleast dp_table[i][j] will be dp_table[i-1][j] where we are not using ith item 
            if (j >= weight[i - 1])
            {
                dp_table[i][j] = max(dp_table[i - 1][j], dp_table[i - 1][j - weight[i - 1]] + values[i - 1]);
            }
        }
    }
    cout << dp_table[n][maxWgt] << endl;
    return;
}