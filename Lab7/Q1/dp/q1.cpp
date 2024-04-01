#include <bits/stdc++.h> //Including the header files
#include <cstdio>
using namespace std;
#define ll long long

int greedy_ans(vector<int> &w, vector<int> &v, int n, int W)
{
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        a.push_back({w[i], v[i]});
    }
    sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y)
         { return (x.first * 1.0 / x.second) < (y.first * 1.0 / y.second); });
    int ans = 0;
    for (auto it : a)
    {
        if (it.first <= W)
        {
            W -= it.first;
            ans += it.second;
        }
    }
    return ans;
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
        int ans = greedy_ans(weight, value, n, W);
        cout << "the max value possible by greedy approach in testcase " << tt << " is -> " << ans << endl;
        cout << endl;
    }
}