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
    freopen("inputQ3.in", "r", stdin);
    freopen("outputQ3.out", "w", stdout);
    // function to read the input file and print the output in another file.
#endif
    solve();
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
#ifndef ONLINE_JUDGE
    cout << endl
         << "::" << time_taken;
#endif
}

// 2D array to store the distances between cities
int dist[65][65];
// dp memoisation array.
int dp[65][65];


int tsp(int i, int city,int n)
{
    if (city == ((1 << i) | 3))
        return dist[1][i];
    // memoization
    if (dp[i][city] != 0)
        return dp[i][city];

    int res = INT32_MAX;
    for (int j = 1; j <= n; j++)
        if ((city & (1 << j)) && j != i && j != 1)
            res = min(res, tsp(j, city & (~(1 << i)),n) + dist[j][i]);

    return dp[i][city] = res;
}



void solve()
{
    // input of number of cities.
    int n;
    cin >> n;

    // initialising array
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            dist[i][j] = 0;
    }

    // input of array elements.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
        }
    }

    int answer = INT32_MAX;

    // // Brute forcing all paths using dp;
    for (int i = 1; i <= n;i++)
    {
        answer = min(answer, tsp(i, (1 << (n + 1)) - 1,n) + dist[i][1]);
    }

    cout << "Least cost path for the Travelling Salesman = " << answer<<endl;
    return;
}
